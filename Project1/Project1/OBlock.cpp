#include "Tetrimino.h"

OBlock::OBlock(const int* tileSize) : Tetrimino(tileSize)
{
	int auxMatriz[4][4] =
	{
		{ 0,0,0,0 },
		{ 1,1,0,0 },
		{ 1,1,0,0 },
		{ 0,0,0,0 }

	};

	std::memcpy(logicMatriz, auxMatriz, sizeof(logicMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);
	_rotateAvailable = RotateAvailable::None;


	tintColor.R = DEFAULT_COLOR;
	tintColor.G = DEFAULT_COLOR;
	tintColor.B = 0;

	Draw();
}


OBlock::~OBlock()
{
}
