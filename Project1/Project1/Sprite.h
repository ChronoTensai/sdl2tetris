#pragma once

#include <stdio.h>
#include <string>
#include <SDL.h>
#include "EngineTools.h"

class Sprite
{
	public:
		Sprite();
		Sprite(std::string path, int x, int y, int w, int h);
		void Add();
		Sprite* Clone();
		void Tint(float r, float g, float b);
		void PositionX(int value);
		void PositionY(int value);
		void Width(int value);
		void Height(int value);
		~Sprite();
	private:
		Sprite(SDL_Texture* srcTexture, SDL_Rect rect);
		bool drawed;
		SDL_Texture* sourceTexture;
		SDL_Rect Rect;
};






