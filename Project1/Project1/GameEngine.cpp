#include "GameEngine.h"


bool GameEngine::InitVideo()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	return true;
}


bool GameEngine::CreateWindowRendered()
{
	window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGTH, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Windows could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGTH);

	return true;
}

GameEngine::GameEngine() 
{
	InitVideo();
}



bool GameEngine::Start()
{
	if (CreateWindowRendered())
	{
		inputManager = new InputManager();
		EngineTools::InitializeEngineTools(inputManager, window, renderer);
		return true;
	}

	return false;
}



void GameEngine::BeforeUpdate(bool* running)
{
	startTicks = SDL_GetTicks();
	SDL_RenderClear(renderer);
	
	while (SDL_PollEvent(&Event) != 0)
	{
		if (Event.type == SDL_QUIT)
		{
			*running = false;
		}
		else if (Event.type == SDL_KEYDOWN)
		{
			inputManager->CheckInputs(Event);
		}
	}
	
}

void GameEngine::AfterUpdate()
{
	SDL_RenderPresent(renderer);

	int endTick = SDL_GetTicks() - startTicks;
	if (endTick < SCREEN_TICKS_PER_FRAME)
	{
		SDL_Delay(SCREEN_TICKS_PER_FRAME - endTick);		
	}
	EngineTools::FrameCount++;
}

GameEngine::~GameEngine()
{
	//Destroy renderer
	SDL_DestroyRenderer(renderer);
	//Destroy window 
	SDL_DestroyWindow(window);
	//Quit SDL subsystems
	SDL_Quit();

	delete inputManager;
	inputManager = nullptr;
	
}




