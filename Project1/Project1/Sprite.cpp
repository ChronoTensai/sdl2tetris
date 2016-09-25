#include "Sprite.h"

Sprite::Sprite()
{
}

Sprite::Sprite(std::string path, int posX, int posY, int width, int height)
{
	drawed = false;
	Rect.x = posX;
	Rect.y = posY;
	Rect.w = width;
	Rect.h = height;
	sourceTexture = EngineTools::RenderService().LoadTexture(path);
}

void Sprite::PositionX(int value)
{
	Rect.x = value;
	if(drawed)
		EngineTools::RenderService().RenderTexture(Rect, sourceTexture);

}

void Sprite::PositionY(int value)
{
	Rect.y = value;
	if (drawed)
		EngineTools::RenderService().RenderTexture(Rect, sourceTexture);
}

void Sprite::Width(int value)
{
	Rect.w = value;
	if (drawed)
		EngineTools::RenderService().RenderTexture(Rect, sourceTexture);
}

void Sprite::Height(int value)
{
	Rect.h = value;
	if (drawed)
		EngineTools::RenderService().RenderTexture(Rect, sourceTexture);
}



void Sprite::Redraw()
{
	drawed = true;
	//Check update texture
	EngineTools::RenderService().RenderTexture(Rect, sourceTexture);
}

void Sprite::Clear()
{
	drawed = false;	
}

void Sprite::Tint(Color color)
{
	EngineTools::RenderService().TintTexture(sourceTexture, color.R, color.G, color.B);
}

void Sprite::Tint(float r, float g, float b)
{
	EngineTools::RenderService().TintTexture(sourceTexture,r,g,b);
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(sourceTexture);
}



SpriteBackground::SpriteBackground()
{
}

SpriteBackground::SpriteBackground(std::string path)
{
	sourceTexture = EngineTools::RenderService().LoadTexture(path);
}

void SpriteBackground::Redraw()
{
	EngineTools::RenderService().RenderBackground(sourceTexture);
}

SpriteBackground::~SpriteBackground()
{
	SDL_DestroyTexture(sourceTexture);
}
