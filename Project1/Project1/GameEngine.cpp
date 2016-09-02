#include "GameEngine.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
CustomInputManager* inputManager;
SDL_Event Event;

bool GameEngine::InitVideo()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	return true;
}


bool GameEngine::CreateWindowRendered()
{
	window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDHT, SCREEN_HEIGTH, SDL_WINDOW_SHOWN);
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
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDHT, SCREEN_WIDHT);

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
		inputManager = new CustomInputManager();
		EngineTools::InitializeEngineTools(inputManager, window, renderer);
		return true;
	}

	return false;
}



void GameEngine::BeforeUpdate(bool* running)
{
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

}

GameEngine::~GameEngine()
{
	//Destroy renderer
	SDL_DestroyRenderer(renderer);
	//Destroy window 
	SDL_DestroyWindow(window);
	//Quit SDL subsystems
	SDL_Quit();
}




