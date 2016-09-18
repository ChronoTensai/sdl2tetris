#pragma once

#include "GameScreen.h"
#include "Timer.h"
#include "Board.h"
#include "Tetrimino.h"
#include <stdlib.h>
#include <ctime>
#include <map>


enum CollisionType { DOWN, LEFT, RIGHT };


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
		const int  BOARD_X = 10;
		const int  BOARD_Y = 100;
		const int  TILE_SIZE = 32;
		RecursiveTimer _rTimer;
		float _timeToDownTetrominio = 1100; //Reducir para generar diferentes niveles

		Board* gameBoard;

		map<int, Tetrimino*> tetrominioMap;

		Tetrimino* activeTetrominio;
		bool hasTetrominioActive;
		int LogicTetrominioX;
		int LogicTetrominioY;

		bool EndOfGame = false;

		void CreateTetrominioPool();
		void PickTetrominio();
		void UpdateGame();
		bool CheckBottomBoard();
		bool CheckCollision(CollisionType collision);
};
		

		

