#pragma once

#include "GameScreen.h"
#include "Timer.h"
#include "Board.h"
#include "Tetrimino.h"
#include "NextTetriminio.h"
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <map>




class Game : public GameScreen
{
	public:
		Game();
		virtual void Update() override;
		virtual void Advance() override;
		virtual void Back() override;
		virtual void OnPressUp() override;
		virtual void OnPressDown() override;
		virtual void OnPressLeft() override;
		virtual void OnPressRight() override;
		~Game();
	private:

		const int  HEIGHT_BOARD = 20;
		const int  WIDTH_BOARD = 10;
		const int  BOARD_X = 100;
		const int  BOARD_Y = 70;
		const int  TILE_SIZE = 25;

		const int  NEXT_TETROMINIO_Y = BOARD_Y + TILE_SIZE/2;
		const int  NEXT_TETROMINIO_X = BOARD_X*2 + WIDTH_BOARD*TILE_SIZE + TILE_SIZE*2;
		RecursiveTimer _rTimer;
		float _timeToDownTetrominio = 900; //Reducir para generar diferentes niveles
		enum CollisionType { DOWN, LEFT, RIGHT, ROTATE };
		enum GameState{ StartGame, InactiveTetrominio,ActiveTetrominio, WaitingBoard, EndOfGame};
		
		GameState _currentGameState = StartGame;
		Board* gameBoard;
		map<int, NextTetriminio*> nextTetrominioMap;
		map<int, Tetrimino*> tetrominioMap;

		const string EndOfGameAssetPath = "Assets/Gameplay/gameOver.jpg";
		const int  EndOfGameSize = 300;
		Sprite* EndOfGameAsset;

		int nextTetrominioId;
		NextTetriminio* nextTetrominio;

		Tetrimino* activeTetrominio;
		int LogicTetrominioX;
		int LogicTetrominioY;

		void CreateTetrominioPool();
		void PickTetrominio();
		void UpdateGame();
		bool CheckBottomBoard();
		bool CheckCollision(CollisionType collision, int * tetrominioMatriz);		
		void CheckLinesCompletesInBoard();
};
		

		

