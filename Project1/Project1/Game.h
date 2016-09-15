#pragma once

#include "EngineTools.h"
#include "Board.h"
#include "Tetrimino.h"
#include "InputDefintion.h"
#include <stdlib.h>
#include <ctime>
#include <map>

class Game 
{
public:
	Game();
	void Update();
	void RotateTetrominio();

	~Game();
private:
	const int  HEIGHT_BOARD = 20;
	const int  WIDTH_BOARD = 10;
	const int  BOARD_X = 10;
	const int  BOARD_Y = 100;
	const int  TILE_SIZE = 32;
	
	void UpdateGame();
	void PickTetrominio();
	void CreateAssetPool();
	bool CheckCollision(int & logicX, int & logicY);
	bool EndOfGame = false;

	static void MoveLeftTetrominio();
	static void MoveRightTetrominio();
	static void DownTetrominio();


	Board* gameBoard;
	Tetrimino* activeTetrominio;
	bool hasTetrominioActive;
	map<int, Tetrimino*> tetrominioMap;



};

