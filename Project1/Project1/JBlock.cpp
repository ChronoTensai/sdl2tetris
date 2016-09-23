#include "Tetrimino.h"

JBlock::JBlock(const int* tileSize, const int* nextX, const int* nextY) : Tetrimino(tileSize, nextX, nextY)
{
	int auxMatriz[4][4] =
	{
		{ 0,0,0,0 },
		{ 1,0,0,0 },
		{ 1,1,1,0 },
		{ 0,0,0,0 }

	};

	std::memcpy(orginalMatriz, auxMatriz, sizeof(orginalMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);	
	_rotateAvailable = RotateAvailable::All;

	Color tintColor;
	tintColor.R = 0;
	tintColor.G = 0;
	tintColor.B = DEFAULT_COLOR;

	Draw(tintColor, nextX, nextY);
}



JBlock::~JBlock()
{
}
