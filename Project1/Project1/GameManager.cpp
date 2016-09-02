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
		init = true;
	}
}


GameManager::~GameManager()
{
}
