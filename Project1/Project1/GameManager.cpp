#include "GameManager.h"


GameManager::GameManager()
{
	_game = new Game();
	_inputHandler = InputHandler(_game);
	EngineTools::InputService().RegisterInputHandler(&_inputHandler);
}

void GameManager::Update()
{
	_game->Update();
}

GameManager::~GameManager()
{
	delete _game;
	_game = nullptr;
}
