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
		void BackToPool();
		void Redraw();
		int* GetLogicMatriz();
		Tetrimino();
		~Tetrimino();
	protected:
		int logicMatriz[4][4];
		Sprite* spriteMatriz[4];
		const int sizeMatriz = 4;

};


class IBlock : public Tetrimino
{
public:
	IBlock();
	~IBlock();
};

class LBlock : public Tetrimino
{
public:
	LBlock();
	~LBlock();
};


class JBlock : public Tetrimino
{

public:
	JBlock();
	~JBlock();
};

class ZBlock : public Tetrimino
{
public:
	ZBlock();
	~ZBlock();
};

class TBlock : public Tetrimino
{
public:
	TBlock();
	~TBlock();
};

class SBlock : public Tetrimino
{

public:
	SBlock();
	~SBlock();
};

class OBlock : public Tetrimino
{

public:
	OBlock();
	~OBlock();
};




