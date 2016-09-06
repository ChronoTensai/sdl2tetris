#include "Board.h"

const int  HeightBoard = 20;
const int  WidthBoard = 10;
const int  startXPosition = 10;
const int  startYPosition = 30;
const int  tilesSize = 35;
const string  boardTilePath = "Assets/Gameplay/boardtile.png";
const string  itemsTilePath = "Assets/Gameplay/boardtile.png";

int    logicMatriz[HeightBoard][WidthBoard];
Sprite* spriteMatriz[HeightBoard][WidthBoard];

Board::Board()
{
	bool swichtColor = false;

	for (int i = 0; i < HeightBoard; i++)
	{
		for (int j = 0; j < WidthBoard; j++)
		{
			spriteMatriz[i][j] = new Sprite(boardTilePath, startXPosition + (tilesSize*j), startYPosition + (tilesSize*i), tilesSize, tilesSize);
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

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			spriteMatriz[i][j]->Tint(0, 100, 0);
			spriteMatriz[i][j]->Add();
			
		}
	}
}

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
	int centerId = floor((WidthBoard - w -1)/ 2);
	for (int i = 0; i < h; i++)
	{
		for (int j = centerId; j < centerId + w ; j++)
		{
			logicMatriz[i][j] = matrizItem[i][j - centerId];
			spriteMatriz[i][j]->Tint(0,50,0);
		}
	}

	for (int i = 0; i < HeightBoard; i++)
	{
		printf("{ ");
		for (int j = 0; j < WidthBoard; j++)
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
