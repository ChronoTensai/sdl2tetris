#include "Tetrimino.h"

const int sizeMatriz = 4;



void Tetrimino::RotateLeft()
{
	int auxIndexer = sizeMatriz -1;
	int auxMatriz[4][4];

	std::memcpy(auxMatriz, logicMatriz, sizeof(logicMatriz) * sizeMatriz);

	for (int i = 0; i < sizeMatriz; i++)
	{
		for (int j = 0; j < sizeMatriz; j++)
		{
			auxMatriz[auxIndexer][j] = logicMatriz[i][j];
			auxIndexer--;
		}
	}

	std::memcpy(logicMatriz, auxMatriz, sizeof(logicMatriz) * sizeMatriz * sizeMatriz); //Funciona?
}

void Tetrimino::RotateRight()
{
	int auxIndexer = sizeMatriz -1;
	int auxMatriz[4][4];

	std::memcpy(auxMatriz, logicMatriz, sizeof(logicMatriz) * sizeMatriz * sizeMatriz);

	for (int i = 0; i < sizeMatriz; i++)
	{
		for (int j = 0; j < sizeMatriz; j++)
		{
			auxMatriz[j][auxIndexer] = logicMatriz[i][j];
			auxIndexer--;
		}
	}

	std::memcpy(logicMatriz, auxMatriz, sizeof(logicMatriz) * sizeMatriz);

}

void Tetrimino::BackToPool()
{

}

int* Tetrimino::GetLogicMatriz()
{
	int* matriz = *logicMatriz;
	return matriz;
}

Tetrimino::Tetrimino()
{}


Tetrimino::~Tetrimino()
{
}
