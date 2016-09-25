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
	void ChangeToNextColor();
	void Update();
	int *GetLogicMatriz();
	void UpdateLogicMatriz(int * newMatriz, int matrizSize, int logicX, int logicY);
	void DeleteRowsAndDown(vector<int> rowsToDelete);
	void DownLines();
	bool BoardAnimationActive();
private:
	const string  BOARD_TILE_PATH = "Assets/Gameplay/trinomiotile.jpg";
	const int DEFAULT_COLOR = 255;
	static const int COLOR_LENGHT = 8;
	Color backgroundColor = Color(48 ,37 ,29);
	Color _colorTiles[COLOR_LENGHT];
	Color* currentBoardColor;
	int currentIdColor = 0;
	void CreateColorArray();	
	void Redraw();
	bool AnimationActive;
	int _height;
	int _width;
	int*   logicMatriz;
	Sprite* spriteMatriz;
		
	//Change to time
	FrameTimer _frameTimer;
	int FRAMES_DELETE_ANIMATION = 4;
	vector<int> _rowsDeleting;
};

