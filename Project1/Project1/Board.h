#pragma once
#include "Sprite.h"
#include <stdio.h>
#include <algorithm>


using namespace std;

class Board
{
public:
	Board(const int * height,const int * width, int x, int y, int tilesSize);
	void Redraw();
	int * GetLogicMatriz();
	void UpdateLogicMatriz(int * newMatriz, int matrizSize, int posX, int posY);
	~Board();
private:
	const string  boardTilePath = "Assets/Gameplay/trinomiotile.jpg";
	int _height;
	int _width;
	int*   logicMatriz;
	Sprite* spriteMatriz;	
};

