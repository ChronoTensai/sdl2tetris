#include "Tetrimino.h"

LBlock::LBlock(const int* tileSize) : Tetrimino(tileSize)
{
	int auxMatriz[4][4] = {
		{ 0, 0, 0, 0 },
		{ 0,0,1,0 },
		{ 1,1,1,0 },
		{ 0,0,0,0 }

	};

	std::memcpy(logicMatriz, auxMatriz, sizeof(logicMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);

	tintColor.R = DEFAULT_COLOR;
	tintColor.G = DEFAULT_COLOR/2;
	tintColor.B = 0;

	Draw();
	
}

LBlock::~LBlock()
{
}
