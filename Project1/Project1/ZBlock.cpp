#include "Tetrimino.h"

ZBlock::ZBlock(const int* tileSize) : Tetrimino(tileSize)
{
	int auxMatriz [4][4] =

	{ 0,0,0,0,
	 1,1,0,0,
	 0,1,1,0,
	 0,0,0,0 };
	
	std::memcpy(logicMatriz, auxMatriz, sizeof(logicMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);
	_rotateAvailable = RotateAvailable::Two;
	
	tintColor.R = DEFAULT_COLOR;
	tintColor.G = 0;
	tintColor.B = 0;

	Draw();
}

ZBlock::~ZBlock()
{
}
