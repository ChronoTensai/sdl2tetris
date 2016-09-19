#pragma once

#include <iostream>
#include <vector>
#include "Sprite.h"
#include <stdio.h>
#include <algorithm>
#include "Timer.h"


class Board
{

public:
	Board(const int * height,const int * width, int x, int y, int tilesSize);
	~Board();
	void CleanBoard();

	void Update();
	int *GetLogicMatriz();
	void UpdateLogicMatriz(int * newMatriz, int matrizSize, int logicX, int logicY);
	void DeleteRowsAndDown(vector<int> rowsToDelete);
	void DownLines();
	bool BoardAnimationActive();
private:
	const string  boardTilePath = "Assets/Gameplay/trinomiotile.jpg";
	void Redraw();
	bool AnimationActive;
	int _height;
	int _width;
	int*   logicMatriz;
	Sprite* spriteMatriz;
	void EndAnimation();
		
	//Change to time
	FrameTimer _frameTimer;
	int FRAMES_DELETE_ANIMATION = 4;
	vector<int> _rowsDeleting;
};

