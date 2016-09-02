#pragma once

#include <stdio.h>
#include <string>
#include "EngineTools.h"

class RectSprite
{
public:
	int X;
	int Y;
	int Widht;
	int Height;
};

class Sprite
{
	public:
		Sprite(std::string path);
		RectSprite RectS;	 
		void Sprite::AddSprite(RectSprite rect);
		~Sprite();
	private:
		SDL_Texture* _texture;
};


