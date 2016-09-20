#pragma once

#include "Game.h"
#include "InputHandler.h"
#include "EngineTools.h"

class GameManager
{
public:
	
	GameManager();
	void Update();
	~GameManager();
private:
	const string BACKGROUND_PATH = "Assets/Gameplay/background.jpg";
	SpriteBackground* _spriteBackground;
	Game* _game;
	InputHandler _inputHandler;
};

