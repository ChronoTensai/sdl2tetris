#include "Game.h"

Game::Game()
{
	CreateTetrominioPool();
	gameBoard = new Board(&HEIGHT_BOARD, &WIDTH_BOARD, BOARD_X, BOARD_Y, TILE_SIZE);
	_rTimer = RecursiveTimer(_timeToDownTetrominio);
	EndOfGameAsset = new Sprite(EndOfGameAssetPath, BOARD_X + WIDTH_BOARD*TILE_SIZE/2 - EndOfGameSize/2, BOARD_Y + HEIGHT_BOARD*TILE_SIZE / 2 - EndOfGameSize / 2, EndOfGameSize, EndOfGameSize);
}

void Game::CreateTetrominioPool()
{
	tetrominioMap[0] = new ZBlock(&TILE_SIZE, &NEXT_TETROMINIO_X, &NEXT_TETROMINIO_Y);
	tetrominioMap[1] = new JBlock(&TILE_SIZE, &NEXT_TETROMINIO_X, &NEXT_TETROMINIO_Y);
	tetrominioMap[2] = new LBlock(&TILE_SIZE, &NEXT_TETROMINIO_X, &NEXT_TETROMINIO_Y);
	tetrominioMap[3] = new OBlock(&TILE_SIZE, &NEXT_TETROMINIO_X, &NEXT_TETROMINIO_Y);
	tetrominioMap[4] = new SBlock(&TILE_SIZE, &NEXT_TETROMINIO_X, &NEXT_TETROMINIO_Y);
	tetrominioMap[5] = new TBlock(&TILE_SIZE, &NEXT_TETROMINIO_X, &NEXT_TETROMINIO_Y);
	tetrominioMap[6] = new IBlock(&TILE_SIZE, &NEXT_TETROMINIO_X, &NEXT_TETROMINIO_Y);
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
				int moveCount = 0;
				while (LogicTetrominioX + activeTetrominio->LogicR.OffsetX < 0)
				{

					if (!CheckCollision(CollisionType::RIGHT, rotateMatriz))
					{
						LogicTetrominioX++;
						activeTetrominio->MoveRight();
						moveCount++;
						applyRotate = true;
					}
					else
					{
						while (moveCount != 0)
						{
							LogicTetrominioX--;
							activeTetrominio->MoveLeft();
							moveCount--;
						}

						applyRotate = false;
						break;
					}
				}
			}
			//Rotate and move Left
			else if (LogicTetrominioX + activeTetrominio->LogicR.ColisionWidth() > WIDTH_BOARD)
			{
				
				int moveCount = 0;
				while (LogicTetrominioX + activeTetrominio->LogicR.ColisionWidth() > WIDTH_BOARD)
				{

					if (!CheckCollision(CollisionType::LEFT, rotateMatriz))
					{
						LogicTetrominioX--;
						activeTetrominio->MoveLeft();
						moveCount++;
						applyRotate = true;
					}
					else
					{
						while (moveCount != 0)
						{
							LogicTetrominioX++;
							activeTetrominio->MoveRight();
							moveCount--;
						}
						applyRotate = false;
						break;
					}
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
	if (_currentGameState == EndOfGame)
	{
		gameBoard->CleanBoard();
		_currentGameState = StartGame;
	}


}

void Game::Back()
{
	printf("Back \n");

}

//Despues se llama al Update

void Game::PickTetrominio()
{
	//Pick Random Tetriminio
	if (_currentGameState == StartGame)
	{
		srand(time(0));
		activeTetrominio = tetrominioMap[rand() % 6];
	}
	else
	{
		activeTetrominio = nextTetrominio;	
	}

	srand(time(0));
	int nextTetrominioId = rand() % 7;
	//if (nextTetrominioId == 7) nextTetrominioId = 6;
	nextTetrominio = tetrominioMap[6];	

	
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
	printf("-------------\n");


	for (int i = LogicCollisionTetrominioY + activeTetrominio->LogicR.OffsetY; i <  LogicCollisionTetrominioY + activeTetrominio->LogicR.ColisionHeight(); i++)
	{
		for (int j = LogicCollisionTetrominioX + activeTetrominio->LogicR.OffsetX ; j < LogicCollisionTetrominioX + activeTetrominio->LogicR.ColisionWidth(); j++)
		{
			currentBoardIndex = WIDTH_BOARD * i + j;
			currentTetrominioIndex = tetrominioSizeMatriz * (i - LogicCollisionTetrominioY) + (j - LogicCollisionTetrominioX);

			if (collision == LEFT)
			{
				printf("IndexCheck: %d  valor: %d\n", currentTetrominioIndex, tetrominioMatriz[currentTetrominioIndex]);
			}

			if (currentBoardIndex >= 0 &&  currentTetrominioIndex >= 0 && tetrominioMatriz[currentTetrominioIndex] != 0)
			{
				
				if (tetrominioMatriz[currentTetrominioIndex] == boardMatriz[currentBoardIndex])
				{
					//Out top bounds
					if (collision == DOWN)
					{
						if (LogicTetrominioY - activeTetrominio->LogicR.OffsetY <= 0)
						{
							_currentGameState = EndOfGame;
						}
						else
						{
							_currentGameState = WaitingBoard;
						}
					}
					//Collision with other Tetrominio
					printf("-------TRUE------\n");

					return true;					
				}				
			}
			
		}
	}
	printf("-------FALSE------\n");

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
	gameBoard->Update();
	

	switch (_currentGameState)
	{
		case StartGame:
		case InactiveTetrominio:
			PickTetrominio();
			nextTetrominio->RedrawNext();
			break;
		case ActiveTetrominio:
			nextTetrominio->RedrawNext();
			if (_rTimer.TimerComplete())
			{
				UpdateGame();
				_rTimer.ResetTimer();
			}
			activeTetrominio->Redraw();			
			break;
		case WaitingBoard:
			nextTetrominio->RedrawNext();
			if (!gameBoard->BoardAnimationActive())
				_currentGameState = InactiveTetrominio;
			break;
		case EndOfGame:
			nextTetrominio->RedrawNext();
			EndOfGameAsset->Redraw();
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
	delete gameBoard;
	gameBoard = nullptr;

	delete EndOfGameAsset;
	EndOfGameAsset = nullptr;

	activeTetrominio = nullptr;
	nextTetrominio = nullptr;	
}
