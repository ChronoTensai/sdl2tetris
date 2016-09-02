#include "Sprite.h"

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



void Sprite::AddSprite()
{
	drawed = true;
	EngineTools::RenderService().RenderTexture(Rect, sourceTexture);
}



Sprite::~Sprite()
{
	drawed = false;

	sourceTexture = nullptr;
	delete sourceTexture;

}
