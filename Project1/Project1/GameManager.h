#pragma once

#include "Game.h"
#include "MainMenu.h"

class GameManager
{
public:
	GameManager();
	void Update();
	~GameManager();
private:
	bool init;
	Game* _game;
	MainMenu* _mainMenu;

};

