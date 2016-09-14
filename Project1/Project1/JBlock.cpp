#include "Tetrimino.h"

JBlock::JBlock(const int* tileSize) : Tetrimino(tileSize)
{
	int auxMatriz[4][4] =
	{
		{ 0,0,0,0 },
		{ 1,0,0,0 },
		{ 1,1,1,0 },
		{ 0,0,0,0 }

	};

	std::memcpy(logicMatriz, auxMatriz, sizeof(logicMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);

	tintColor.R = 0;
	tintColor.G = 0;
	tintColor.B = DEFAULT_COLOR;

	Draw();
}

JBlock::~JBlock()
{
}
