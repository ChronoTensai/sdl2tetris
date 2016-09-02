#pragma once

#ifndef RenderManager_h
#endif RenderManager_h

#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"


class RenderManager
{
	public:
		RenderManager(SDL_Renderer * renderer, SDL_Window* window);
		SDL_Texture* LoadTexture(std::string path);
		//void RenderTexture(RectSprite rectTexture, SDL_Texture* source);
		void RenderTexture(SDL_Texture source);
		~RenderManager();

	private:
		SDL_Renderer* gRenderer;
		SDL_Window * gWindow;
};