#include "Tetrimino.h"

Tetrimino::Tetrimino()
{
	logicMatriz = new int[SIZE_MATRIZ * SIZE_MATRIZ];
	spriteMatriz = new Sprite[TILES_PER_ITEM];
}

Tetrimino::Tetrimino(const int* tileSize)
{
	_tileSize = tileSize;
	logicMatriz = new int[SIZE_MATRIZ * SIZE_MATRIZ];
	spriteMatriz = new Sprite[TILES_PER_ITEM];
}


void Tetrimino::RotateLeft()
{
	/*int auxIndexer = SIZE_MATRIZ -1;
	int auxMatriz[4][4];

	std::memcpy(auxMatriz, logicMatriz, sizeof(logicMatriz) * SIZE_MATRIZ);

	for (int i = 0; i < SIZE_MATRIZ; i++)
	{
		for (int j = 0; j < SIZE_MATRIZ; j++)
		{
			auxMatriz[auxIndexer][j] = logicMatriz[i][j];
			auxIndexer--;
		}
	}

	std::memcpy(logicMatriz, auxMatriz, sizeof(logicMatriz) * SIZE_MATRIZ * SIZE_MATRIZ); //Funciona?*/
}

void Tetrimino::RotateRight()
{
	/*int auxIndexer = SIZE_MATRIZ -1;
	int auxMatriz[4][4];

	std::memcpy(auxMatriz, logicMatriz, sizeof(logicMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);

	for (int i = 0; i < SIZE_MATRIZ; i++)
	{
		for (int j = 0; j < SIZE_MATRIZ; j++)
		{
			auxMatriz[j][auxIndexer] = logicMatriz[i][j];
			auxIndexer--;
		}
	}

	std::memcpy(logicMatriz, auxMatriz, sizeof(logicMatriz) * SIZE_MATRIZ);*/

}

void Tetrimino::Redraw()
{
	int spriteIndex = 0;

	for (int i = 0; i < SIZE_MATRIZ; i++)
	{
		for (int j = 0; j < SIZE_MATRIZ; j++)
		{
			if (logicMatriz[j + (SIZE_MATRIZ*i)] == 1)
			{
				spriteMatriz[spriteIndex].Clear();
				spriteMatriz[spriteIndex].PositionX(X + (j* (*_tileSize)) );
				spriteMatriz[spriteIndex].PositionY(Y + (i*(*_tileSize)) );
				spriteMatriz[spriteIndex].Add();
				spriteIndex++;
			}
		}
	}
}

void Tetrimino::GoToBoard(int boardX, int boardY)
{
	X = boardX;

	Y = boardY - (*_tileSize* SIZE_MATRIZ);
}

int* Tetrimino::GetLogicMatriz()
{
	return logicMatriz;
}


void Tetrimino::Draw()
{
	int spriteIndex = 0;

	for (int i = 0; i < SIZE_MATRIZ; i++)
	{
		for (int j = 0; j < SIZE_MATRIZ; j++)
		{
			if (logicMatriz[j + (SIZE_MATRIZ*i)] == 1)
			{
				spriteMatriz[spriteIndex] = *(new Sprite(TILE_PATH, j**_tileSize, i**_tileSize, *_tileSize, *_tileSize));
				spriteMatriz[spriteIndex].Tint(tintColor.R, tintColor.G, tintColor.B);				
				spriteIndex++;
			}			
		}
	}
}

Tetrimino::~Tetrimino()
{
	delete [] logicMatriz;
	delete [] spriteMatriz;
}




