#include "Game.h"

Game::Game()
{
	CreateTetrominioPool();
	gameBoard = new Board(&HEIGHT_BOARD, &WIDTH_BOARD, BOARD_X, BOARD_Y, TILE_SIZE);
	_rTimer = RecursiveTimer(_timeToDownTetrominio);
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
	if (_currentGameState == ActiveTetrominio)
	{
		bool applyRotate = false;
		int* rotateMatriz = activeTetrominio->GenerateMatrizRotate();
		if (rotateMatriz != nullptr)
		{
			//Rotate and move Right
			if (LogicTetrominioX + activeTetrominio->LogicR.OffsetX < 0)
			{
				if (!CheckCollision(CollisionType::RIGHT, activeTetrominio->GetLogicMatriz()))
				{
					while (LogicTetrominioX + activeTetrominio->LogicR.OffsetX < 0)
					{
						LogicTetrominioX++;
						activeTetrominio->MoveRight();
					}					
					applyRotate = true;
				}
			}
			//Rotate and move Left
			else if (LogicTetrominioX + activeTetrominio->LogicR.ColisionWidth() > WIDTH_BOARD)
			{
				if (!CheckCollision(CollisionType::LEFT, activeTetrominio->GetLogicMatriz()))
				{
					while (LogicTetrominioX + activeTetrominio->LogicR.ColisionWidth() > WIDTH_BOARD)
					{
						LogicTetrominioX--;
						activeTetrominio->MoveLeft();
					}					
					applyRotate = true;
				}
			}
			else if (!CheckCollision(CollisionType::ROTATE, rotateMatriz))
			{
				applyRotate = true;
			}
			else if (!CheckCollision(CollisionType::RIGHT, rotateMatriz))
			{
				LogicTetrominioX++;
				activeTetrominio->MoveRight();
				applyRotate = true;
			}
			else if (!CheckCollision(CollisionType::LEFT, rotateMatriz))
			{
				LogicTetrominioX--;
				activeTetrominio->MoveLeft();
				applyRotate = true;
			}
			
		}

		if (applyRotate)
		{
			activeTetrominio->ApplyRotateMatriz(rotateMatriz);
		}
		else
		{
			activeTetrominio->ResetRotateMatriz(rotateMatriz);
		}
		
	}

}

void Game::OnPressLeft()
{
	if (_currentGameState == ActiveTetrominio)
	{
		if (LogicTetrominioX + activeTetrominio->LogicR.OffsetX > 0)
		{
			if (!CheckCollision(CollisionType::LEFT, activeTetrominio->GetLogicMatriz()))
			{
				LogicTetrominioX--;
				activeTetrominio->MoveLeft();
			}
		}
	}
}

void Game::OnPressRight()
{
	if (_currentGameState == ActiveTetrominio)
	{
		if (LogicTetrominioX + activeTetrominio->LogicR.ColisionWidth() < WIDTH_BOARD)
		{
			if (!CheckCollision(CollisionType::RIGHT, activeTetrominio->GetLogicMatriz()))
			{
				LogicTetrominioX++;
				activeTetrominio->MoveRight();
			}

		}
	}
}

void Game::OnPressDown()
{
	if (_currentGameState == ActiveTetrominio)
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
	activeTetrominio = tetrominioMap[rand() % 7];
	
	//Save this in const?
	int InitialX = BOARD_X + ((WIDTH_BOARD * TILE_SIZE) / 2) - TILE_SIZE;
	int InitialY = BOARD_Y - (TILE_SIZE * 2);

	activeTetrominio->ResetLogicMatrix();
	activeTetrominio->SetPosition(InitialX, InitialY);	
	
	LogicTetrominioX = (InitialX - BOARD_X) / TILE_SIZE;
	LogicTetrominioY = -2;

	_currentGameState = ActiveTetrominio;
}

bool Game::CheckBottomBoard()
{
	if (LogicTetrominioY + activeTetrominio->LogicR.ColisionHeight() +1 > HEIGHT_BOARD)
	{
		return true;
	}
	return false;
}

bool Game::CheckCollision(CollisionType collision, int* tetrominioMatriz)
{
	//Set the type of collision
	int LogicCollisionTetrominioY = LogicTetrominioY;
	int LogicCollisionTetrominioX = LogicTetrominioX;

	switch (collision)
	{
		case DOWN:
			LogicCollisionTetrominioY++;
			break;
		case LEFT:
			LogicCollisionTetrominioX--;
			break;
		case RIGHT:
			LogicCollisionTetrominioX++;
			break;
	}	

	//Tetrominio Data
	int tetrominioSizeMatriz = activeTetrominio->SIZE_MATRIZ;
	
	//Board Data
	int* boardMatriz = gameBoard->GetLogicMatriz();

	//Auxiliar vars
	int currentBoardIndex;
	int currentTetrominioIndex;

	//Hard to understand
	for (int i = LogicCollisionTetrominioY + activeTetrominio->LogicR.OffsetY; i <  LogicCollisionTetrominioY + activeTetrominio->LogicR.ColisionHeight(); i++)
	{
		for (int j = LogicCollisionTetrominioX + activeTetrominio->LogicR.OffsetX ; j < LogicCollisionTetrominioX + activeTetrominio->LogicR.ColisionWidth(); j++)
		{
			currentBoardIndex = WIDTH_BOARD * i + j;
			currentTetrominioIndex = tetrominioSizeMatriz * (i - LogicCollisionTetrominioY) + (j - LogicCollisionTetrominioX);

			if (currentBoardIndex >= 0 &&  currentTetrominioIndex > 0 && tetrominioMatriz[currentTetrominioIndex] != 0)
			{
				if (tetrominioMatriz[currentTetrominioIndex] == boardMatriz[currentBoardIndex])
				{
					//Out top bounds
					if (collision == DOWN && LogicCollisionTetrominioY - activeTetrominio->LogicR.OffsetY < 0)
					{
						_currentGameState = EndOfGame;						
					}
					else
					{
						_currentGameState = WaitingBoard;
					}
					//Collision with other Tetrominio
					return true;					
				}				
			}
			
		}
	}
	return false;
}



//We do this here to keep the board independ for the tetris logic
void Game::CheckLinesCompletesInBoard()
{
	int* boardMatriz = gameBoard->GetLogicMatriz();
	vector<int> linesToDelete;
	vector<int>::iterator it = linesToDelete.begin();

	int currentBoardIndex;

	for (int i = LogicTetrominioY +activeTetrominio->LogicR.OffsetY; i < LogicTetrominioY + activeTetrominio->LogicR.ColisionHeight(); i++)
	{
		for (int j = 0; j < WIDTH_BOARD; j++)
		{
			currentBoardIndex = WIDTH_BOARD * i + j;
			if (boardMatriz[currentBoardIndex] != 1)
			{
				break;
			}
			else if (j == WIDTH_BOARD - 1)
			{
				linesToDelete.insert(it, i);
				it = linesToDelete.begin();
			}
		}
	}

	if (!linesToDelete.empty())
	{
		gameBoard->DeleteRowsAndDown(linesToDelete);		
	}
	else
		_currentGameState = InactiveTetrominio;
}



void Game::Update()
{
	//PickTetrominio
	switch (_currentGameState)
	{
		case InactiveTetrominio:
			PickTetrominio();
			gameBoard->Update();
			break;
		case ActiveTetrominio:
			if (_rTimer.TimerComplete())
			{
				UpdateGame();
				_rTimer.ResetTimer();
			}
			gameBoard->Update();
			activeTetrominio->Redraw();			
			break;
		case WaitingBoard:
			if (!gameBoard->BoardAnimationActive())
				_currentGameState = InactiveTetrominio;
			gameBoard->Update();
			break;
		case EndOfGame:
			gameBoard->Update();
		break;
	}

	
}



void Game::UpdateGame()
{
	//CheckColision
	if (LogicTetrominioY + activeTetrominio->LogicR.H >= 0 && (CheckBottomBoard() || CheckCollision(CollisionType::DOWN, activeTetrominio->GetLogicMatriz())))
	{
		// Update Board
		gameBoard->UpdateLogicMatriz(activeTetrominio->GetLogicMatriz(), activeTetrominio->SIZE_MATRIZ, LogicTetrominioX, LogicTetrominioY);
		if (_currentGameState != EndOfGame)
		{
			CheckLinesCompletesInBoard();
		}		
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
