#include "Tetrimino.h"

ZBlock::ZBlock(const int* tileSize, const int* nextX, const int* nextY) : Tetrimino(tileSize, nextX, nextY)
{
	int auxMatriz [4][4] =

	{ 0,0,0,0,
	 1,1,0,0,
	 0,1,1,0,
	 0,0,0,0 };
	
	std::memcpy(orginalMatriz, auxMatriz, sizeof(orginalMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);	
	_rotateAvailable = RotateAvailable::Two;
	
	
	Color tintColor;
	tintColor.R = DEFAULT_COLOR;
	tintColor.G = 0;
	tintColor.B = 0;

	Draw(tintColor, nextX, nextY);
}



ZBlock::~ZBlock()
{
}
