#pragma once
#ifndef Tetrimino_H
#endif Tetrimino_H

#include <stdio.h>
#include "Sprite.h"
#include <algorithm>

using namespace std;

class Tetrimino
{
	public:
		void RotateLeft();
		void RotateRight();
		int X = 0;
		int Y = 0;
		void Redraw();
		void GoToBoard(int boardX, int boardY);
		int* GetLogicMatriz();
		Tetrimino(const int* tileSize);
		Tetrimino();
		virtual ~Tetrimino();
	protected:
		const string TILE_PATH = "Assets/Gameplay/trinomiotile.jpg";
		const int TILES_PER_ITEM = 4;
		const int DEFAULT_COLOR = 255;
		const int* _tileSize;
		Color tintColor;
		int* logicMatriz;
		Sprite* spriteMatriz;
		void Draw();
	public:
		const int SIZE_MATRIZ = 4;
};


class IBlock : public Tetrimino
{
public:
	IBlock(const int* tileSize);
	~IBlock();
};

class LBlock : public Tetrimino
{
public:
	LBlock(const int* tileSize);
	~LBlock();
};


class JBlock : public Tetrimino
{

public:
	JBlock(const int* tileSize);
	~JBlock();
};

class ZBlock : public Tetrimino
{
public:
	ZBlock(const int* tileSize);
	~ZBlock();
};

class TBlock : public Tetrimino
{
public:
	TBlock(const int* tileSize);
	~TBlock();
};

class SBlock : public Tetrimino
{

public:
	SBlock(const int* tileSize);
	~SBlock();
};

class OBlock : public Tetrimino
{

public:
	OBlock(const int* tileSize);
	~OBlock();
};




