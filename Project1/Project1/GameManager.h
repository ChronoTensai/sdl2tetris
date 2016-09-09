#pragma once

#include "Game.h"

class GameManager
{
public:
	GameManager();
	void Update();
	~GameManager();
private:
	bool init;
	Game* _game;

};

