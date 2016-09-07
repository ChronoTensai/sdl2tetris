#include "GameManager.h"
#include "Game.h"

Game* _game;

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
	_game = nullptr;
	delete _game;
}
