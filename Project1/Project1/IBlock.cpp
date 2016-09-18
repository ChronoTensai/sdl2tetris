#include "Tetrimino.h"

IBlock::IBlock(const int* tileSize) : Tetrimino(tileSize)
{
	int auxMatriz[4][4] =
	{
		{ 0,0,0,0 },
		{ 1,1,1,1 },
		{ 0,0,0,0 },
		{ 0,0,0,0 }
	
	};

	std::memcpy(logicMatriz, auxMatriz, sizeof(logicMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);
	_rotateAvailable = RotateAvailable::Two;

	tintColor.R = 0;
	tintColor.G = DEFAULT_COLOR;
	tintColor.B = DEFAULT_COLOR;

	Draw();
}


IBlock::~IBlock()
{

}
