#include "GameManager.h"
#include "Game.h"
#include "InputDefintion.h"
#include <stdio.h>

typedef void(*inputCallback)();


void GameManager::PrintableFunction()
{
	printf("PrinteoPrinteo");
}

Game* _game;

GameManager::GameManager()
{
	_game = new Game();
	//inputCallback callback = PrintableFunction; 
	//EngineTools::InputService().RegisterInput(InputDefinition::InputKeys::DOWN, PrintableFunction);
}



void GameManager::Update()
{
	_game->Update();
}




GameManager::~GameManager()
{
}
