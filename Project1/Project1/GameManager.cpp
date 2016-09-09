#include "GameManager.h"


GameManager::GameManager()
{
	_game = new Game();
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
