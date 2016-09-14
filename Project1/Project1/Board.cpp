#include "Board.h"


Board::Board(const int* height, const int* width,int x, int y, int tilesSize)
{
	bool swichtColor = false;
	_height = *height;
	_width = *width;

	logicMatriz = new int[(_height * _width)];
	spriteMatriz = new Sprite[(_height * _width)];

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			logicMatriz[j + (_width*i)] = 0;
			spriteMatriz[j + (_width*i)] =  *(new Sprite(boardTilePath, x + (tilesSize*j), y + (tilesSize*i), tilesSize, tilesSize));
			spriteMatriz[j + (_width*i)].Tint(0, 0, 51);			
			spriteMatriz[j + (_width*i)].Add();

			swichtColor = !swichtColor;
		}
		swichtColor = !swichtColor;
	}
}


void Board::Redraw()
{
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			if (logicMatriz[j + (_width*i)] == 0)
			{
				spriteMatriz[j + (_width*i)].Tint(0, 0, 51);				
			}
			else
			{
				spriteMatriz[j + (_width*i)].Tint(224, 224, 224);
			}
			spriteMatriz[j + (_width*i)].Add();
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

/* No se usa se guarda por la logica */

/*void Board::AddAtTopBoard(int* matriz,int w, int h)
{
	//RandomColors
	int matrizItem[4][4];

	for ( int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			matrizItem[i][j] = *(matriz + j + (w*i));
		}
	}

	//PickCenterTileToAddItem
	int centerId = floor((_width - w -1)/ 2);
	for (int i = 0; i < h; i++)
	{
		for (int j = centerId; j < centerId + w ; j++)
		{
			if (matrizItem[i][j - centerId] == 1)
			{
				//logicMatriz[i][j] = matrizItem[i][j - centerId];
				//spriteMatriz[i][j]->Add();
			}
		}
	}

	for (int i = 0; i < _height; i++)
	{
		printf("{ ");
		for (int j = 0; j < _width; j++)
		{
			//printf("%d ,", logicMatriz[i][j]);
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
