#include "Board.h"


Board::Board(const int* height, const int* width,int x, int y, int tilesSize)
{
	_height = *height;
	_width = *width;

	logicMatriz = new int[(_height * _width)];
	spriteMatriz = new Sprite[(_height * _width)];

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			logicMatriz[j + (_width*i)] = 0;
			spriteMatriz[j + (_width*i)] =  *(new Sprite(BOARD_TILE_PATH, x + (tilesSize*j), y + (tilesSize*i), tilesSize, tilesSize));
		}
	}
}


void Board::CleanBoard()
{
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			logicMatriz[j + (_width*i)] = 0;		
		}
	}
}

void Board::Redraw()
{
	int currentIndex;
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			currentIndex = j + (_width*i);
			if (AnimationActive && logicMatriz[currentIndex] == 2)
			{
				if (_frameTimer.CurrentFrame() % 2 == 0)
				{
					spriteMatriz[currentIndex].Tint(224, 224, 224);
				}
				else
				{
					spriteMatriz[currentIndex].Tint(0, 0, 51);
				}
				spriteMatriz[currentIndex].Redraw();
			}			
			else if(logicMatriz[currentIndex] == 1)
			{
				spriteMatriz[currentIndex].Tint(224, 224, 224);
				spriteMatriz[currentIndex].Redraw();
			}			
		}
	}
}

int* Board::GetLogicMatriz ()
{
	return logicMatriz;
}

void Board::UpdateLogicMatriz(int* newMatriz, int matrizSize, int logicX, int logicY)
{
	int currentBoardIndex;
	int currentUpdateMatrixBoard;

	for (int i = logicY; i < matrizSize + logicY; i++)
	{
		for (int j = logicX; j < matrizSize + logicX; j++)
		{
			currentBoardIndex = _width * i + j;
			currentUpdateMatrixBoard = matrizSize * (i - logicY) + (j - logicX);
			
			if (newMatriz[currentUpdateMatrixBoard] == 1)
			{
				logicMatriz[currentBoardIndex] = 1;
			}

		}
	}
}

void Board::DeleteRowsAndDown(vector<int> rowsToDelete)
{
	_rowsDeleting = rowsToDelete;
	AnimationActive = true;
	
	for (vector<int>::iterator iterator = _rowsDeleting.begin(); iterator < _rowsDeleting.end(); ++iterator)
	{
		for (int j = 0; j < _width; j++)
		{
			logicMatriz[j + (_width* (*iterator))] = 2;
		}
	}

	//StartAnimation
	_frameTimer.StartTimer(FRAMES_DELETE_ANIMATION);
}

void Board::DownLines()
{
	int currentIndex;
	int rowMoved = 0;

	for (vector<int>::iterator iterator = _rowsDeleting.begin(); iterator < _rowsDeleting.end(); ++iterator)
	{
		for (int j = 0; j < _width; j++)
		{
			logicMatriz[j + (_width* (*iterator + rowMoved))] = 0;
		}

		for (int i = *iterator; i >= rowMoved * -1; i--)
		{
			for (int j = 0; j < _width; j++)
			{
				currentIndex = j + (_width* (i + rowMoved));
				if (i <= 0)
				{
					logicMatriz[currentIndex] = 0;
				}
				else
				{
					logicMatriz[currentIndex] = logicMatriz[currentIndex - _width];
				}				
			}
		}
		rowMoved++;
		
	}
	AnimationActive = false;
}


void Board::Update()
{
	if (AnimationActive)
	{
		if (_frameTimer.FrameTimerComplete())
			DownLines();
	}
	Redraw();
}

bool Board::BoardAnimationActive()
{
	return AnimationActive;
}

/* No se usa se guarda por la logica */

/*void Board::PrintMatriz(int* matriz)
{
	for (int i = 0; i < SIZE_MATRIZ; i++)
	{
		printf("{ ");
		for (int j = 0; j < SIZE_MATRIZ; j++)
		{
			printf("%d ,", matriz[i + (SIZE_MATRIZ*j)]);
		}
		printf(" } \n");

	}	
}*/


Board::~Board()
{
	//dont forget erase memory
	delete[] spriteMatriz;
	delete [] logicMatriz;
}


