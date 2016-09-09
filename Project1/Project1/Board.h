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
	void AddAtTopBoard(int * matriz, int w, int h);
	~Board();
private:
	const string  boardTilePath = "Assets/Gameplay/boardtile.png";
	int _height;
	int _width;
	int*   logicMatriz;
	Sprite* spriteMatriz;	
};

