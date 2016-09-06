#include "LBlock.h"



LBlock::LBlock()
{
	int starter[4][4] = {
		{ 0, 0, 0, 0 },
		{ 0,0,1,0 },
		{ 1,1,1,0 },
		{ 0,0,0,0 }

	};

	std::memcpy(logicMatriz, starter, sizeof(logicMatriz) * sizeMatriz);
}


LBlock::~LBlock()
{
}
