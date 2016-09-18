#include "Tetrimino.h"

TBlock::TBlock(const int* tileSize) : Tetrimino(tileSize)
{
	int auxMatriz[4][4] =
	{
		{ 0,0,0,0 },
		{ 0,1,0,0 },
		{ 1,1,1,0 },
		{ 0,0,0,0 }
	};

	std::memcpy(logicMatriz, auxMatriz, sizeof(logicMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);
	_rotateAvailable = RotateAvailable::All;

	tintColor.R = DEFAULT_COLOR;
	tintColor.G = 0;
	tintColor.B = DEFAULT_COLOR;

	Draw();
}

TBlock::~TBlock()
{
}
