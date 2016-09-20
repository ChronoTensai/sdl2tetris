#include "RenderManager.h"


RenderManager::RenderManager(SDL_Renderer * renderer, SDL_Window * window)
{
	gRenderer = renderer;
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

void RenderManager::RenderBackground(SDL_Texture * source)
{
	SDL_Rect Rect;
	Rect.x = Rect.y = 0;	
	SDL_GetWindowSize(gWindow, &Rect.w, &Rect.h);

	SDL_RenderCopy(gRenderer, source, NULL, &Rect);
}

void RenderManager::TintTexture(SDL_Texture * source, float r, float g, float b)
{
	SDL_SetTextureColorMod(source, r, g, b);
}

RenderManager::~RenderManager() 
{
	//I free the memory of this elements in GameEngine
	gRenderer = nullptr;
	gWindow = nullptr;

}


