#pragma once

#include <stdio.h>
#include <string>
#include <SDL.h>
#include "EngineTools.h"

struct Color
{
	Color() {};
	Color(int r, int g, int b) 
	{
		R = r;
		G = g;
		B = b;
	};
	int R;
	int G;
	int B;
};

class Sprite
{
	public:
		Sprite();
		Sprite(std::string path, int x, int y, int w, int h);
		void Redraw();
		void Clear();
		void Tint(Color color);
		void Tint(float r, float g, float b);
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

class SpriteBackground
{
	public:
		SpriteBackground();
		SpriteBackground(std::string path);
		void Redraw();
		~SpriteBackground();
	private:		
		SDL_Texture* sourceTexture;		
};






