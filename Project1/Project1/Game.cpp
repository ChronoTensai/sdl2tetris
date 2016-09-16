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
	activeTetrominio->RotateLeft();

}


void Game::OnPressLeft()
{
	printf("MoveLeftTetrominio  \n");
	if (activeTetrominio->X >= BOARD_X && activeTetrominio->X < BOARD_X + (TILE_SIZE * WIDTH_BOARD))
	{
		activeTetrominio->X -= TILE_SIZE;
	}

}

void Game::OnPressRight()
{
	printf("MoveRightTetrominio \n");
	if (activeTetrominio->X >= BOARD_X && activeTetrominio->X < BOARD_X + (TILE_SIZE * WIDTH_BOARD))
	{
		activeTetrominio->X += TILE_SIZE;
	}


}

void Game::OnPressDown()
{
	printf("DownTetrominio \n");
	if (hasTetrominioActive)
	{
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
	activeTetrominio = tetrominioMap[rand() % 6];
	activeTetrominio->GoToBoard(BOARD_X + ((WIDTH_BOARD * TILE_SIZE) / 2) - TILE_SIZE, BOARD_Y);
	hasTetrominioActive = true;
}

bool Game::CheckCollision(int & logicX, int & logicY)
{
	int* tetrominioMatriz = activeTetrominio->GetLogicMatriz();
	int* boardMatriz = gameBoard->GetLogicMatriz();

	int tetrominioSizeMatriz = activeTetrominio->SIZE_MATRIZ;
	int boardYEdge = WIDTH_BOARD * HEIGHT_BOARD;

	int currentBoardIndex;
	int currentTetrominioIndex;

	bool result = false;
	
	//Primero chequear arriba
	for (int i = logicY; i < tetrominioSizeMatriz + logicY; i++)
	{
		for (int j = logicX; j < tetrominioSizeMatriz + logicX; j++)
		{
			currentBoardIndex = WIDTH_BOARD * i + j;
			currentTetrominioIndex = tetrominioSizeMatriz * (i - logicY) + (j - logicX);

			if (currentTetrominioIndex > 0 && tetrominioMatriz[currentTetrominioIndex] != 0)
			{
				if (currentBoardIndex > boardYEdge)
				{
					printf("Collision Down Board \n");
					return true;
				}
				else if (tetrominioMatriz[currentTetrominioIndex] == boardMatriz[currentBoardIndex])
				{
					if (logicY  == 0)
					{
						printf("You Lose \n");
						EndOfGame = true;
						return true;
					}
					else
					{
						printf("Collision OtherThing \n");
						result = true; // We not return the value until we check all the tiles, maybe we lose the game
						//Perfomance problem

					}					
				}
			}
			
		}
	}		
	return result;
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
	//DownTetrominio
	activeTetrominio->Y += TILE_SIZE;
	//CheckColision
	if (activeTetrominio->Y >= BOARD_Y)
	{
		int logicXTetrominio = (activeTetrominio->X - BOARD_X) / TILE_SIZE;
		int logicYTetrominio = (activeTetrominio->Y - BOARD_Y) / TILE_SIZE;

	
		if (CheckCollision(logicXTetrominio, logicYTetrominio))
		{
			activeTetrominio->Y -= TILE_SIZE;
			// Update Board
		
			gameBoard->UpdateLogicMatriz(activeTetrominio->GetLogicMatriz(), activeTetrominio->SIZE_MATRIZ, (activeTetrominio->X - BOARD_X) / TILE_SIZE, (activeTetrominio->Y - BOARD_Y) / TILE_SIZE);			
			hasTetrominioActive = false;		
		}
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
