#include "NextTetriminio.h"



NextTetriminio::NextTetriminio()
{
	logicMatriz = new int[SIZE_MATRIZ * SIZE_MATRIZ];
	spriteMatriz = new Sprite[SIZE_MATRIZ];
}


void NextTetriminio::Redraw()
{
	int spriteIndex = 0;

	for (int i = 0; i < SIZE_MATRIZ; i++)
	{
		for (int j = 0; j < SIZE_MATRIZ; j++)
		{
			if (logicMatriz[j + (SIZE_MATRIZ*i)] == 1)
			{
				spriteMatriz[spriteIndex].Add();
				spriteIndex++;
			}
		}
	}
}

void NextTetriminio::Draw(const int * tileSize, int x, int y, Color colorTint)
{
	int spriteIndex = 0;

	for (int i = 0; i < SIZE_MATRIZ; i++)
	{
		for (int j = 0; j < SIZE_MATRIZ; j++)
		{
			if (logicMatriz[j + (SIZE_MATRIZ*i)] == 1)
			{
				spriteMatriz[spriteIndex] = *(new Sprite(TILE_PATH, x + ((*tileSize)*j), y + (*tileSize*i), *tileSize, *tileSize));
				spriteMatriz[spriteIndex].Tint(colorTint);
				spriteIndex++;
			}			
		}
	}
}


NextTetriminio::~NextTetriminio()
{
	delete[] logicMatriz;
	delete[] spriteMatriz;
}

NextIBlock::NextIBlock(const int * tileSize, int x, int y) 
{
	int auxMatriz[4][4] =
	{
		{ 0,0,0,0 },
		{ 1,1,1,1 },
		{ 0,0,0,0 },
		{ 0,0,0,0 }
	
	};

	std::memcpy(logicMatriz, auxMatriz, sizeof(logicMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);
	Color tintColor;
	tintColor.R = 0;
	tintColor.G = DEFAULT_COLOR;
	tintColor.B = DEFAULT_COLOR;

	Draw(tileSize, x, y, tintColor);
}

NextIBlock::~NextIBlock()
{
}

NextLBlock::NextLBlock(const int * tileSize, int x, int y) 
{
	int auxMatriz[4][4] = {
		{ 0, 0, 0, 0 },
		{ 0,0,1,0 },
		{ 1,1,1,0 },
		{ 0,0,0,0 }

	};

	std::memcpy(logicMatriz, auxMatriz, sizeof(logicMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);
	Color tintColor;
	tintColor.R = DEFAULT_COLOR;
	tintColor.G = DEFAULT_COLOR/2;
	tintColor.B = 0;

	Draw(tileSize, x, y, tintColor);
}

NextLBlock::~NextLBlock()
{
}

NextJBlock::NextJBlock(const int * tileSize, int x, int y) 
{
	int auxMatriz[4][4] =
	{
		{ 0,0,0,0 },
		{ 1,0,0,0 },
		{ 1,1,1,0 },
		{ 0,0,0,0 }

	};

	std::memcpy(logicMatriz, auxMatriz, sizeof(logicMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);
	Color tintColor;
	tintColor.R = 0;
	tintColor.G = 0;
	tintColor.B = DEFAULT_COLOR;

	Draw(tileSize, x, y, tintColor);
}


NextJBlock::~NextJBlock()
{
}

NextZBlock::NextZBlock(const int * tileSize, int x, int y) 
{
	int auxMatriz [4][4] =

	{ 0,0,0,0,
	 1,1,0,0,
	 0,1,1,0,
	 0,0,0,0 };

	std::memcpy(logicMatriz, auxMatriz, sizeof(logicMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);
	Color tintColor;
	tintColor.R = DEFAULT_COLOR;
	tintColor.G = 0;
	tintColor.B = 0;
	Draw(tileSize, x, y, tintColor);
}


NextZBlock::~NextZBlock()
{
}

NextTBlock::NextTBlock(const int * tileSize, int x, int y) 
{
	int auxMatriz[4][4] =
	{
		{ 0,0,0,0 },
		{ 0,1,0,0 },
		{ 1,1,1,0 },
		{ 0,0,0,0 }
	};

	std::memcpy(logicMatriz, auxMatriz, sizeof(logicMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);
	Color tintColor;
	tintColor.R = DEFAULT_COLOR;
	tintColor.G = 0;
	tintColor.B = DEFAULT_COLOR;

	Draw(tileSize, x, y, tintColor);
}


NextTBlock::~NextTBlock()
{
}

NextSBlock::NextSBlock(const int * tileSize, int x, int y) 
{
	int auxMatriz[4][4] =
	{
		{ 0,0,0,0 },
		{ 0,1,1,0 },
		{ 1,1,0,0 },
		{ 0,0,0,0 }

	};

	std::memcpy(logicMatriz, auxMatriz, sizeof(logicMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);
	Color tintColor;
	tintColor.R = 0;
	tintColor.G = DEFAULT_COLOR;
	tintColor.B = 0;

	Draw(tileSize, x, y, tintColor);
}


NextSBlock::~NextSBlock()
{
}

NextOBlock::NextOBlock(const int * tileSize, int x, int y) 
{
	int auxMatriz[4][4] =
	{
		{ 0,0,0,0 },
		{ 1,1,0,0 },
		{ 1,1,0,0 },
		{ 0,0,0,0 }

	};

	std::memcpy(logicMatriz, auxMatriz, sizeof(logicMatriz) * SIZE_MATRIZ * SIZE_MATRIZ);
	Color tintColor;

	tintColor.R = DEFAULT_COLOR;
	tintColor.G = DEFAULT_COLOR;
	tintColor.B = 0;

	Draw(tileSize, x, y, tintColor);
}


NextOBlock::~NextOBlock()
{
}
