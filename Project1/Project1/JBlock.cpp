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

	std::memcpy(orginalMatriz, auxMatriz, sizeof(orginalMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);	
	_rotateAvailable = RotateAvailable::All;

	tintColor.R = 0;
	tintColor.G = 0;
	tintColor.B = DEFAULT_COLOR;

	Draw();
}

JBlock::~JBlock()
{
}
