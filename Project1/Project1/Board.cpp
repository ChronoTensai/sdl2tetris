#include "Board.h"

const string  boardTilePath = "Assets/Gameplay/boardtile.png";


Board::Board(const int* height, const int* width,int x, int y, int tilesSize)
{
	bool swichtColor = false;
	_height = *height;
	_width = *width;

	//logicMatriz = int [*height][*width];;
	//spriteMatriz = Sprite* [*height][*width];

	Sprite sprite = Sprite(boardTilePath, 0, 0, tilesSize, tilesSize);

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			spriteMatriz[i][j] = sprite.Clone();
			spriteMatriz[i][j]->PositionX(x + (tilesSize*j));
			spriteMatriz[i][j]->PositionY(y + (tilesSize*i));
			if (swichtColor)
			{
				spriteMatriz[i][j]->Tint(0, 0, 100);
			}
			else
			{
				spriteMatriz[i][j]->Tint(100,0,0);
			}
			spriteMatriz[i][j]->Add();
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
			if (logicMatriz[i][j] == 1)
			{
				spriteMatriz[i][j]->Tint(0, 100, 0);
			}
			spriteMatriz[i][j]->Add();					
		}
	}
}

/* No se usa se guarda por la logica */

void Board::AddAtTopBoard(int* matriz,int w, int h)
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
				logicMatriz[i][j] = matrizItem[i][j - centerId];
				spriteMatriz[i][j]->Add();
			}
		}
	}

	for (int i = 0; i < _height; i++)
	{
		printf("{ ");
		for (int j = 0; j < _width; j++)
		{
			printf("%d ,", logicMatriz[i][j]);
		}
		printf(" } \n");
		
	}
	
}


Board::~Board()
{
	//dont forget erase memory
}
