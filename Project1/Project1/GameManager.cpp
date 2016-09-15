#include "GameManager.h"


GameManager::GameManager()
{
	_game = new Game();
	//_mainMenu = new MainMenu();
}

void GameManager::Update()
{
	_game->Update();
}

GameManager::~GameManager()
{
	delete _game;
	_game = nullptr;

	//delete _mainMenu;
	//_mainMenu = nullptr;
}
