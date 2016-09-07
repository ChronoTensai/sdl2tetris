#pragma once

#include "EngineTools.h"
#include "Board.h"
#include "Tetrimino.h"
#include "InputDefintion.h"
#include <map>

class Game
{
public:
	Game();
	void Update();
	~Game();
private:
	const int  HEIGHT_BOARD = 20;
	const int  WIDTH_BOARD = 10;
	const int  BOARD_X = 10;
	const int  BOARD_Y = 30;
	const int  TILE_SIZE = 35;
	void MoveRightTetrominio();
	void DownTetrominio();
	void PickTetrominio();
	void CreateAssetPool();
	void RotateTetrominio();
	void MoveLeftTetrominio();	
	Board* gameBoard;
	Tetrimino* activeTetrominio;
	bool hasTetrominioActive;
	map<int, Tetrimino*> tetrominioMap;

};

