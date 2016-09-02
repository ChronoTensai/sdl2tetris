#pragma once

#include <stdio.h>
#include <string>



class SDLSprite
{
	public:
		SDLSprite(std::string path, float x, float y, float w, float h);
		~SDLSprite();
	private:
		SDL_Texture* sourceTexture;
		SDL_Rect Rect;
};






