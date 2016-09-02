#include "GameLoop.h"


GameEngine* gameEngine;
GameManager* gameManager;
bool IsRunning;

GameLoop::GameLoop()
{
	gameEngine = new GameEngine();
}

void GameLoop::Start()
{
	IsRunning = true;
	if (gameEngine->Start())
	{
		gameManager = new GameManager();
		Looping();
	}		
	else
		EndLoop();
}

void GameLoop::Looping()
{
	while (IsRunning)
	{
		gameEngine->BeforeUpdate(&IsRunning);
		if (IsRunning)
		{		
			gameManager->Update();
			gameEngine->AfterUpdate();
		}
	}
	EndLoop();
}

void  GameLoop::EndLoop()
{
	gameEngine = nullptr;
	delete gameEngine;

	gameManager = nullptr;
	delete gameManager;
}

GameLoop::~GameLoop()
{
	
}