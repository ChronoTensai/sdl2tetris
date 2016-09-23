#include "Tetrimino.h"

IBlock::IBlock(const int* tileSize, const int* nextX, const int* nextY) : Tetrimino(tileSize, nextX, nextY)
{
	int auxMatriz[4][4] =
	{
		{ 0,0,0,0 },
		{ 1,1,1,1 },
		{ 0,0,0,0 },
		{ 0,0,0,0 }
	
	};

	std::memcpy(orginalMatriz, auxMatriz, sizeof(orginalMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);
	_rotateAvailable = RotateAvailable::Two;

	Color tintColor;
	tintColor.R = 0;
	tintColor.G = DEFAULT_COLOR;
	tintColor.B = DEFAULT_COLOR;

	Draw(tintColor, nextX, nextY);
}


IBlock::~IBlock()
{

}
