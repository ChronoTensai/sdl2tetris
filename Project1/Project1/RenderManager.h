#ifndef RenderManager_h
#endif RenderManager_h

#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

class RenderManager
{
	public:
		RenderManager(SDL_Renderer * renderer, SDL_Window* window);
		SDL_Texture* LoadTexture(std::string path);
		void RenderTexture(SDL_Rect rectTexture, SDL_Texture* source);
		void RenderBackground(SDL_Texture * source);
		void TintTexture(SDL_Texture * source, float r, float g, float b);
		~RenderManager();
	private:
		SDL_Renderer* gRenderer;
		SDL_Window * gWindow;
};