#pragma once

#include "GameScreen.h"
#include "GameBackground.h"
#include "Timer.h"
#include "Board.h"
#include "Tetrimino.h"
#include <vector>
#include <ctime>



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
		GameBackground _gameBackground;			
		
		//GameState		
		float _timeToDownTetrominio = 900; //Reducir para generar diferentes niveles
		RecursiveTimer _rTimer = RecursiveTimer(_timeToDownTetrominio);
		enum CollisionType { DOWN, LEFT, RIGHT, ROTATE };
		enum GameState { StartGame, InactiveTetrominio, ActiveTetrominio, WaitingBoard, EndOfGame };
		GameState _currentGameState = StartGame;
		void UpdateGame();
		bool CheckBottomBoard();
		bool CheckCollision(CollisionType collision, int * tetrominioMatriz);
		void CheckLinesCompletesInBoard();
		const int LINES_TO_CHANGE_LEVEL = 5; //Only to show the feature
		const int DELTA_SPEED_NEW_LEVEL = 75;
		const int MIN_SPEED = 50; 
		int linesCount = 0;


		//Board
		const int  HEIGHT_BOARD = 20;
		const int  WIDTH_BOARD = 10;
		const int  BOARD_X = 100;
		const int  BOARD_Y = 70;
		const int  TILE_SIZE = 25;
		Board gameBoard = Board(&HEIGHT_BOARD, &WIDTH_BOARD, BOARD_X, BOARD_Y, TILE_SIZE);

		//EndofGame
		const string EndOfGameAssetPath = "Assets/Gameplay/gameOver.jpg";
		const int  EndOfGameWidth = 800;
		const int  EndOfGameHeigh = 151;
		const int  EndOfGameY = 225;
		Sprite EndOfGameAsset = Sprite (EndOfGameAssetPath, 0, EndOfGameY, EndOfGameWidth, EndOfGameHeigh);

		//Tetriminios
		const int  NEXT_TETROMINIO_Y = BOARD_Y + TILE_SIZE;
		const int  NEXT_TETROMINIO_X = BOARD_X * 2 + WIDTH_BOARD*TILE_SIZE + TILE_SIZE / 2;
		Tetrimino* tetrominioMap[7];
		Tetrimino* nextTetrominio;
		Tetrimino* activeTetrominio;
		int LogicTetrominioX;
		int LogicTetrominioY;
		void CreateTetrominioPool();
		void PickTetrominio();		
		
};
		

		

