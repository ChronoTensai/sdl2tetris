#pragma once
#ifndef Tetrimino_H
#endif Tetrimino_H

#include <stdio.h>
#include <algorithm>


using namespace std;


class Tetrimino
{
	public:
		void RotateLeft();
		void RotateRight();
		void BackToPool();
		int* GetLogicMatriz();
		Tetrimino();
		~Tetrimino();
	protected:
		int logicMatriz[4][4];
		const int sizeMatriz = 4;

};



