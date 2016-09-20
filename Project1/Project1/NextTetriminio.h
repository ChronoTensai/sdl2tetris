#pragma once
#include "Sprite.h"

class NextTetriminio
{
public:
	NextTetriminio();
	void Redraw();
	virtual ~NextTetriminio();
protected:
	const int DEFAULT_COLOR = 255;
	const int SIZE_MATRIZ = 4;
	const string TILE_PATH = "Assets/Gameplay/trinomiotile.jpg";
	void Draw(const int * tileSize, int x, int y, Color colorTint);
	int* logicMatriz;
	Sprite* spriteMatriz;
};


class NextIBlock : public NextTetriminio
{
public:
	NextIBlock(const int* tileSize, int x, int y);
	~NextIBlock();
};

class NextLBlock : public NextTetriminio
{
public:
	NextLBlock(const int* tileSize, int x, int y);
	~NextLBlock();
};


class NextJBlock : public NextTetriminio
{

public:
	NextJBlock(const int* tileSize, int x, int y);
	~NextJBlock();
};

class NextZBlock : public NextTetriminio
{
public:
	NextZBlock(const int* tileSize, int x, int y);
	~NextZBlock();
};

class NextTBlock : public NextTetriminio
{
public:
	NextTBlock(const int* tileSize, int x, int y);
	~NextTBlock();
};

class NextSBlock : public NextTetriminio
{

public:
	NextSBlock(const int* tileSize, int x, int y);
	~NextSBlock();
};

class NextOBlock : public NextTetriminio
{

public:
	NextOBlock(const int* tileSize, int x, int y);
	~NextOBlock();
};

