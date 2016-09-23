#include "Tetrimino.h"

LBlock::LBlock(const int* tileSize, const int* nextX, const int* nextY) : Tetrimino(tileSize, nextX, nextY)
{
	int auxMatriz[4][4] = {
		{ 0, 0, 0, 0 },
		{ 0,0,1,0 },
		{ 1,1,1,0 },
		{ 0,0,0,0 }

	};

	std::memcpy(orginalMatriz, auxMatriz, sizeof(orginalMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);	
	_rotateAvailable = RotateAvailable::All;
	
	Color tintColor;
	tintColor.R = DEFAULT_COLOR;
	tintColor.G = DEFAULT_COLOR/2;
	tintColor.B = 0;

	Draw(tintColor, nextX, nextY);
}



LBlock::~LBlock()
{
}
