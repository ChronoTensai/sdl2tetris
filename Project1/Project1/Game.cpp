#include "Game.h"

Game::Game()
{
	CreateTetrominioPool();
	gameBoard = new Board(&HEIGHT_BOARD, &WIDTH_BOARD, BOARD_X, BOARD_Y, TILE_SIZE);
	_rTimer = RecursiveTimer(_timeToDownTetrominio);

	hasTetrominioActive = false;
}

void Game::CreateTetrominioPool()
{
	tetrominioMap[0] = new IBlock(&TILE_SIZE);
	tetrominioMap[1] = new JBlock(&TILE_SIZE);
	tetrominioMap[2] = new LBlock(&TILE_SIZE);
	tetrominioMap[3] = new OBlock(&TILE_SIZE);
	tetrominioMap[4] = new SBlock(&TILE_SIZE);
	tetrominioMap[5] = new TBlock(&TILE_SIZE);
	tetrominioMap[6] = new ZBlock(&TILE_SIZE);
}


//Primero se consumen los inputs

void Game::OnPressUp()
{
	printf("RotateTetrominio \n");
	activeTetrominio->Rotate();

}


void Game::OnPressLeft()
{
	if (hasTetrominioActive)
	{
		if (LogicTetrominioX + activeTetrominio->LogicR.OffsetX > 0)
		{
			if (!CheckCollision(CollisionType::LEFT))
			{
				LogicTetrominioX--;
				activeTetrominio->MoveLeft();
			}
		}
	}
}

void Game::OnPressRight()
{
	if (hasTetrominioActive)
	{
		printf("MoveRightTetrominio \n");
		if (LogicTetrominioX + activeTetrominio->LogicR.ColisionWidth() < WIDTH_BOARD)
		{
			if (!CheckCollision(CollisionType::RIGHT))
			{
				LogicTetrominioX++;
				activeTetrominio->MoveRight();
			}

		}
	}
}

void Game::OnPressDown()
{
	if (hasTetrominioActive)
	{
		printf("DownTetrominio \n");
		UpdateGame();
	}
	
}

void Game::Advance()
{
	printf("Advance \n");

}

void Game::Back()
{
	printf("Back \n");

}

//Despues se llama al Update

void Game::PickTetrominio()
{
	//Pick Random Tetriminio
	srand(time(0));
	activeTetrominio = tetrominioMap[rand() % 7];

	//Save this in const?
	int InitialX = BOARD_X + ((WIDTH_BOARD * TILE_SIZE) / 2) - TILE_SIZE;
	int InitialY = BOARD_Y - (TILE_SIZE * 2);

	activeTetrominio->ResetLogicMatrix();
	activeTetrominio->SetPosition(InitialX, InitialY);	
	
	LogicTetrominioX = (InitialX - BOARD_X) / TILE_SIZE;
	LogicTetrominioY = -2;

	hasTetrominioActive = true;
}

bool Game::CheckBottomBoard()
{
	//Primero chequeamos abajo
	if (LogicTetrominioY + activeTetrominio->LogicR.ColisionHeight() +1 > HEIGHT_BOARD)
	{
		printf("Collision Down Board \n");
		return true;
	}
	return false;
}

bool Game::CheckCollision(CollisionType collision)
{
	//Set the type of collision
	int LogicTetrominioYPlus = LogicTetrominioY;
	int LogicTetrominioXPlus = LogicTetrominioX;

	switch (collision)
	{
		case DOWN:
			LogicTetrominioYPlus++;
			break;
		case LEFT:
			LogicTetrominioXPlus--;
			break;
		case RIGHT:
			LogicTetrominioXPlus++;
			break;		
	}	

	//Tetrominio Data
	int* tetrominioMatriz = activeTetrominio->GetLogicMatriz();
	int tetrominioSizeMatriz = activeTetrominio->SIZE_MATRIZ;
	
	//Board Data
	int* boardMatriz = gameBoard->GetLogicMatriz();

	//Auxialiar 
	int currentBoardIndex;
	int currentTetrominioIndex;

	//Dificil de leer
	for (int i = LogicTetrominioYPlus + activeTetrominio->LogicR.OffsetY; i <  LogicTetrominioYPlus + activeTetrominio->LogicR.ColisionHeight(); i++)
	{
		for (int j = LogicTetrominioXPlus + activeTetrominio->LogicR.OffsetX ; j < LogicTetrominioXPlus + activeTetrominio->LogicR.ColisionWidth(); j++)
		{
			currentBoardIndex = WIDTH_BOARD * i + j;
			currentTetrominioIndex = tetrominioSizeMatriz * (i - LogicTetrominioYPlus) + (j - LogicTetrominioXPlus);

			if (currentBoardIndex >= 0 &&  currentTetrominioIndex > 0 && tetrominioMatriz[currentTetrominioIndex] != 0)
			{
				if (tetrominioMatriz[currentTetrominioIndex] == boardMatriz[currentBoardIndex])
				{
					if (LogicTetrominioYPlus - activeTetrominio->LogicR.OffsetY < 0)
					{
						printf("You Lose \n");
						EndOfGame = true;
						return true;
					}
					if (tetrominioMatriz[currentTetrominioIndex] == boardMatriz[currentBoardIndex])
					{
						printf("Collision OtherThing \n");
						return true;
					}
				}				
			}
			
		}
	}
	return false;
}


void Game::Update()
{
	//PickTetrominio
	if (!EndOfGame)
	{
		if (!hasTetrominioActive)
		{
			PickTetrominio();
			gameBoard->Redraw();
		}
		else
		{
			if (_rTimer.TimerComplete())
			{
				UpdateGame();
				_rTimer.ResetTimer();
			}
			gameBoard->Redraw();
			activeTetrominio->Redraw();
		}
	}
	else
	{
		gameBoard->Redraw();
	}
}



void Game::UpdateGame()
{
	//CheckColision
	if (LogicTetrominioY + activeTetrominio->LogicR.H >= 0 && (CheckBottomBoard() || CheckCollision(CollisionType::DOWN)))
	{
		// Update Board
		hasTetrominioActive = false;
		gameBoard->UpdateLogicMatriz(activeTetrominio->GetLogicMatriz(), activeTetrominio->SIZE_MATRIZ, LogicTetrominioX, LogicTetrominioY);
	}
	else
	{
		LogicTetrominioY++;
		activeTetrominio->MoveDown();
	}
}


Game::~Game()
{
	//delete gameBoard;
	gameBoard = nullptr;

	for (std::map<int, Tetrimino*>::iterator it = tetrominioMap.begin(); it != tetrominioMap.end(); ++it)
	{
		delete (it->second);
	}
	tetrominioMap.clear();
}
