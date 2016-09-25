#include "GameManager.h"


GameManager::GameManager()
{
	EngineTools::InputService().RegisterInputHandler(&_inputHandler);
}

void GameManager::Update()
{
	_game.Update();
}

GameManager::~GameManager()
{
	
}
