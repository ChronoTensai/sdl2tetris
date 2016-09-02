#include "GameManager.h"

#include <stdio.h>


GameManager::GameManager()
{
	init = false;
}

void GameManager::Update()
{
	if (!init)
	{
		EngineTools::RenderService().LoadTexture("Assets/MainMenu/Splash.jpg");
		init = true;
	}
}


GameManager::~GameManager()
{
}
