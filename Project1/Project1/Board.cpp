#include "Board.h"
#include <stdlib.h>



Board::Board(const int* height, const int* width,int x, int y, int tilesSize)
{
	bool swichtColor = false;
	_height = *height;
	_width = *width;

	logicMatriz = new int[(_height * _width)];
	spriteMatriz = new Sprite[(_height * _width)];

	//Sprite* _sprite = new Sprite(boardTilePath, 0, 0, tilesSize, tilesSize);

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			/*Sprite auxSprite = *_sprite->Clone();
			spriteMatriz[j + (_width*i)] = auxSprite;
			spriteMatriz[j + (_width*i)].PositionX(x + (tilesSize*j));
			spriteMatriz[j + (_width*i)].PositionY(y + (tilesSize*i));*/

			spriteMatriz[j + (_width*i)] =  *(new Sprite(boardTilePath, x + (tilesSize*j), y + (tilesSize*i), tilesSize, tilesSize));

			if (swichtColor)
			{
				spriteMatriz[j + (_width*i)].Tint(0, 0, 100);
				printf("Si \n");				
			}
			else
			{
				spriteMatriz[j + (_width*i)].Tint(100,0,0);
				printf("No \n");
			}
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
			if (logicMatriz[j + (_width*i)] == 1)
			{
				spriteMatriz[j + (_width*i)].Tint(0, 100, 0);
			}
			spriteMatriz[j + (_width*i)].Add();
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
	
}


Board::~Board()
{
	//dont forget erase memory
	delete[] spriteMatriz;
	delete [] logicMatriz;
}
