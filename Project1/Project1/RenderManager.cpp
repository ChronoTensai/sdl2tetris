#include "RenderManager.h"

RenderManager::RenderManager(SDL_Renderer* screenSurface, SDL_Window* window)
{
	gRenderer = screenSurface;
	gWindow = window;
}

SDL_Texture* RenderManager::LoadTexture(std::string path)
{
	int imgFlags = IMG_INIT_JPG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}
	
	//Load image at specified path 
	SDL_Texture* _texture = IMG_LoadTexture(gRenderer, path.c_str() );
	
	if(_texture == NULL )
	{ 
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError()); 
	} 
	
	IMG_Quit();

	return _texture;
}

void RenderManager::RenderTexture(SDL_Rect rectTexture, SDL_Texture * source)
{
	SDL_RenderCopy(gRenderer, source, NULL, &rectTexture);
}

RenderManager::~RenderManager() 
{
	

}


