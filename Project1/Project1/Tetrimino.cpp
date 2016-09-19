#include "Tetrimino.h"

Tetrimino::Tetrimino()
{
}

Tetrimino::Tetrimino(const int* tileSize)
{
	_tileSize = tileSize;
	logicMatriz = new int[SIZE_MATRIZ * SIZE_MATRIZ];
	orginalMatriz = new int[SIZE_MATRIZ * SIZE_MATRIZ];
	spriteMatriz = new Sprite[TILES_PER_ITEM];
}

//Rotation
int* Tetrimino::GenerateMatrizRotate()
{
	switch (_rotateAvailable)
	{
		case RotateAvailable::Two:
			if (_rotateTimes == 0) return RotateMatrizToRight(logicMatriz);
			else return RotateMatrizToLeft(logicMatriz);
			break;
		case RotateAvailable::All:			
			return RotateMatrizToRight(logicMatriz);
			break;
		default:
			break;
	}
	return nullptr;
}

int* Tetrimino::RotateMatrizToRight(int* matrizTarget)
{
	_rotateTimes++;
	if (_rotateTimes > 4) _rotateTimes = 0;

	const int auxIndexer = SIZE_MATRIZ - 1;
	int* auxMatriz = new int[SIZE_MATRIZ*SIZE_MATRIZ];

	std::memcpy(auxMatriz, matrizTarget, sizeof(matrizTarget) * SIZE_MATRIZ * SIZE_MATRIZ);

	for (int i = 0; i < SIZE_MATRIZ; i++)
	{
		for (int j = 0; j < SIZE_MATRIZ; j++)
		{
			auxMatriz[(auxIndexer - i) + SIZE_MATRIZ * j] = matrizTarget[j + (SIZE_MATRIZ*i)];

		}
	}

	CalculateLogicValues(auxMatriz);
	return auxMatriz;
}

int* Tetrimino::RotateMatrizToLeft(int* matrizTarget)
{
	_rotateTimes--;

	const int auxIndexer = (SIZE_MATRIZ - 1) * SIZE_MATRIZ;
	int* auxMatriz = new int[SIZE_MATRIZ*SIZE_MATRIZ];

	std::memcpy(auxMatriz, matrizTarget, sizeof(matrizTarget) * SIZE_MATRIZ * SIZE_MATRIZ);

	for (int i = 0; i < SIZE_MATRIZ; i++)
	{
		for (int j = 0; j < SIZE_MATRIZ; j++)
		{
			auxMatriz[auxIndexer - SIZE_MATRIZ * j + i] = matrizTarget[j + (SIZE_MATRIZ*i)];
		}
	}

	CalculateLogicValues(auxMatriz);
	return auxMatriz;
}

void Tetrimino::ApplyRotateMatriz(int* rotateMatriz)
{
	delete[] logicMatriz;
	logicMatriz = rotateMatriz;
}

void Tetrimino::ResetRotateMatriz(int* rotateMatriz)
{
	delete[] rotateMatriz;
	rotateMatriz = nullptr;

	switch (_rotateAvailable)
	{
		case RotateAvailable::Two:
			if (_rotateTimes == 0) _rotateTimes++;
			else _rotateTimes--;
			break;
		case RotateAvailable::All:
			_rotateTimes--;
			break;	
	}
	CalculateLogicValues(logicMatriz);
}


// Move 
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

void Tetrimino::CalculateLogicValues(int* matrizToCheck)
{
	LogicR.ResetValues();

	unsigned int tilesRemainings = TILES_PER_ITEM * 2;
	
	unsigned int maxHeightValue = 0;

	bool foundTileInWidth = false;
	bool foundTileInHeight = false;
	bool foundOffsetX = false;
	bool foundOffsetY = false;	

	for (int i = 0; i < SIZE_MATRIZ; i++)
	{
		foundTileInWidth = false;
		foundTileInHeight = false;

		for (int j = 0; j < SIZE_MATRIZ; j++)
		{
			if (!foundTileInWidth && matrizToCheck[j + (SIZE_MATRIZ*i)] == 1)
			{				
				LogicR.H++;
				foundTileInWidth = true;

				if (!foundOffsetY)
				{
					LogicR.OffsetY = i;
					foundOffsetY = true;
				}		
			}

			if (!foundTileInHeight && matrizToCheck[i + (SIZE_MATRIZ*j)] == 1)
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
	std::memcpy(logicMatriz, orginalMatriz, sizeof(int*) * SIZE_MATRIZ * SIZE_MATRIZ);
	CalculateLogicValues(orginalMatriz);
}

void Tetrimino::Draw()
{
	int spriteIndex = 0;

	for (int i = 0; i < SIZE_MATRIZ; i++)
	{
		for (int j = 0; j < SIZE_MATRIZ; j++)
		{
			if (orginalMatriz[j + (SIZE_MATRIZ*i)] == 1)
			{
				spriteMatriz[spriteIndex] = *(new Sprite(TILE_PATH, j**_tileSize, i**_tileSize, *_tileSize, *_tileSize));
				spriteMatriz[spriteIndex].Tint(tintColor.R, tintColor.G, tintColor.B);				
				spriteIndex++;
			}			
		}
	}

	CalculateLogicValues(orginalMatriz);
}



Tetrimino::~Tetrimino()
{	
	delete[] orginalMatriz;
	delete[] logicMatriz;
	delete [] spriteMatriz;
}

int * Tetrimino::GetLogicMatriz()
{
	return logicMatriz;
}




