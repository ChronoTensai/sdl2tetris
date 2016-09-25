#pragma once

#include "Game.h"
#include "InputHandler.h"
#include "EngineTools.h"

class GameManager
{
public:
	
	GameManager();
	void Update();
	virtual ~GameManager();
private:
	Game _game;
	InputHandler _inputHandler = InputHandler(&_game);
};

