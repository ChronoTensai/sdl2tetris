#pragma once
#ifndef Tetrimino_H
#endif Tetrimino_H

#include <stdio.h>
#include "Sprite.h"
#include <algorithm>

using namespace std;

struct LogicRectangle
{
	int OffsetX;
	int OffsetY;
	int W;
	int H;
	//Change Name
	int ColisionHeight() { return H + OffsetY; }
	int ColisionWidth() { return W + OffsetX; }
	void ResetValues()
	{
		W = H = 0;
		OffsetX = OffsetY = INT_MAX;
	}
};

class Tetrimino
{
	public:
		const int SIZE_MATRIZ = 4;

		Tetrimino(const int* tileSize, const int* nextX, const int* nextY);
		Tetrimino();
		virtual ~Tetrimino();

		int* GetLogicMatriz();
		LogicRectangle LogicR;

		int* GenerateMatrizRotate();		
		void ApplyRotateMatriz(int * rotateMatriz);
		void ResetRotateMatriz(int * rotateMatriz);
		void MoveLeft();
		void MoveRight();
		void MoveDown();
		void Redraw();
		void RedrawNext();
		void SetPosition(int x, int y);
		void ResetLogicMatrix();
	protected:
		const int DEFAULT_COLOR = 255;
		Sprite* spriteMatriz;
		enum RotateAvailable { None, Two, All };
		RotateAvailable _rotateAvailable = RotateAvailable::None;
		int* logicMatriz;
		int* orginalMatriz;
		void Draw(Color color, const int* nextX, const int* nextY);
	private:
		Sprite* nextSpriteMatriz;
		const int TILES_PER_ITEM = 4;
		const int* _tileSize;
		const string TILE_PATH = "Assets/Gameplay/trinomiotile.jpg";
		int _spriteX = 0;
		int _spriteY = 0;
		int _rotateTimes = 0;
		int* RotateMatrizToRight(int * matrizTarget);
		int * RotateMatrizToLeft(int * matrizTarget);
		void CalculateLogicValues(int * matrizToCheck);
};


class IBlock : public Tetrimino
{
public:
	IBlock(const int* tileSize, const int* nextX, const int* nextY);
	~IBlock();
};

class LBlock : public Tetrimino
{
public:
	LBlock(const int* tileSize, const int* nextX, const int* nextY);
	~LBlock();
};


class JBlock : public Tetrimino
{

public:
	JBlock(const int* tileSize, const int* nextX, const int* nextY);
	~JBlock();
};

class ZBlock : public Tetrimino
{
public:
	ZBlock(const int* tileSize, const int* nextX, const int* nextY);
	~ZBlock();
};

class TBlock : public Tetrimino
{
public:
	TBlock(const int* tileSize, const int* nextX, const int* nextY);
	~TBlock();
};

class SBlock : public Tetrimino
{

public:
	SBlock(const int* tileSize, const int* nextX, const int* nextY);
	~SBlock();
};

class OBlock : public Tetrimino
{

public:
	OBlock(const int* tileSize, const int* nextX, const int* nextY);
	~OBlock();
};




