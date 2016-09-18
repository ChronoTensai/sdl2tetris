#include "Tetrimino.h"

Tetrimino::Tetrimino()
{
}

Tetrimino::Tetrimino(const int* tileSize)
{
	_tileSize = tileSize;
	logicMatriz = new int[SIZE_MATRIZ * SIZE_MATRIZ];
	spriteMatriz = new Sprite[TILES_PER_ITEM];
}


void Tetrimino::Rotate()
{
	switch (_rotateAvailable)
	{
		case RotateAvailable::Two:
			if (_rotateTimes == 0) RotateRight();
			else RotateLeft();
			break;
		case RotateAvailable::All:
			RotateRight();
			if (_rotateTimes > 4) _rotateTimes = 0;			
			break;
		default:
			break;
	}
}

void Tetrimino::RotateRight()
{
	_rotateTimes++;

	const int auxIndexer = SIZE_MATRIZ - 1;

	int* auxMatriz = new int[SIZE_MATRIZ*SIZE_MATRIZ];

	int changeIndex;
	int currentIndex;

	std::memcpy(auxMatriz, logicMatriz, sizeof(logicMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);

	for (int i = 0; i < SIZE_MATRIZ; i++)
	{
		for (int j = 0; j < SIZE_MATRIZ; j++)
		{
			currentIndex = j + (SIZE_MATRIZ*i);
			changeIndex = (auxIndexer - i) + SIZE_MATRIZ * j;
			auxMatriz[changeIndex] = logicMatriz[currentIndex];

		}
	}

	delete [] logicMatriz;

	logicMatriz = auxMatriz;
	auxMatriz = nullptr;

	CalculateLogicValues();
}

void Tetrimino::RotateLeft()
{
	_rotateTimes--;

	const int auxIndexer = (SIZE_MATRIZ - 1) * SIZE_MATRIZ;
	int* auxMatriz = new int[SIZE_MATRIZ*SIZE_MATRIZ];

	int changeIndex;
	int currentIndex;

	std::memcpy(auxMatriz, logicMatriz, sizeof(logicMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);

	for (int i = 0; i < SIZE_MATRIZ; i++)
	{
		for (int j = 0; j < SIZE_MATRIZ; j++)
		{
			currentIndex = j + (SIZE_MATRIZ*i);
			changeIndex = auxIndexer - SIZE_MATRIZ * j + i;
			auxMatriz[changeIndex] = logicMatriz[currentIndex];
			printf("Index %d -> %d \n", currentIndex, changeIndex);

		}
	}

	delete[] logicMatriz;

	logicMatriz = auxMatriz;
	auxMatriz = nullptr;

	CalculateLogicValues();
}



void Tetrimino::MoveLeft()
{
	_spriteX -= *_tileSize;
}

void Tetrimino::MoveRight()
{
	_spriteX += *_tileSize;
}

void Tetrimino::MoveDown()
{
	_spriteY += *_tileSize;
}

void Tetrimino::CalculateLogicValues()
{
	LogicR.ResetValues();

	unsigned int tilesRemainings = TILES_PER_ITEM * 2;
	
	unsigned int maxHeightValue = 0;

	bool foundTileInWidth = false;
	bool foundTileInHeight = false;
	bool foundOffsetX = false;
	bool foundOffsetY = false;
	

	//OnlyWorksInQuadMatriz	
	for (int i = 0; i < SIZE_MATRIZ; i++)
	{
		foundTileInWidth = false;
		foundTileInHeight = false;

		for (int j = 0; j < SIZE_MATRIZ; j++)
		{
			if (!foundTileInWidth && logicMatriz[j + (SIZE_MATRIZ*i)] == 1)
			{				
				LogicR.H++;
				foundTileInWidth = true;

				if (!foundOffsetY)
				{
					LogicR.OffsetY = i;
					foundOffsetY = true;
				}		
			}

			if (!foundTileInHeight && logicMatriz[i + (SIZE_MATRIZ*j)] == 1)
			{			
				LogicR.W++;
				foundTileInHeight = true;

				if (!foundOffsetX)
				{
					foundOffsetX = true;
					LogicR.OffsetX = i;
				}
				
			}	
		}	
	}

	//printf("Rlogic W: %d H: %d  X: %d Y: %d \n", LogicR.W, LogicR.H, LogicR.OffsetX, LogicR.OffsetY);

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
				spriteMatriz[spriteIndex].PositionX(_spriteX + (j* (*_tileSize)) );
				spriteMatriz[spriteIndex].PositionY(_spriteY + (i*(*_tileSize)) );
				spriteMatriz[spriteIndex].Add();
				spriteIndex++;
			}
		}
	}
}

void Tetrimino::SetPosition(int x, int y)
{
	_spriteX = x;
	_spriteY = y;
}

void Tetrimino::ResetLogicMatrix()
{
	if (_rotateTimes != 0)//I dont like this
	{
		if (_rotateTimes > 2)
		{
			while (_rotateTimes !=0)
			{
				RotateRight();
				if (_rotateTimes > 0)
					_rotateTimes = 0;
			}
			
		}
		else
		{
			while (_rotateTimes != 0)
			{
				RotateLeft();
			}
		}
	}
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

	CalculateLogicValues();
}



Tetrimino::~Tetrimino()
{	
	delete[] logicMatriz;
	delete [] spriteMatriz;
}

int * Tetrimino::GetLogicMatriz()
{
	return logicMatriz;
}




