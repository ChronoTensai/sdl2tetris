#pragma once

#include <stdio.h>
#include <string>
#include <SDL.h>
#include "EngineTools.h"

class Sprite
{
	public:
		Sprite(std::string path, int x, int y, int w, int h);
		void AddSprite();
		void PositionX(int value);
		void PositionY(int value);
		void Width(int value);
		void Height(int value);
		~Sprite();
	private:
		bool drawed;
		SDL_Texture* sourceTexture;
		SDL_Rect Rect;
};






