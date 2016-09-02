#include "Sprite.h"

Sprite::Sprite(std::string path)
{
//	_texture = EngineTools::RenderService().LoadTexture(path);
}

void Sprite::AddSprite(RectSprite rect)
{
	RectS = rect;
//	EngineTools::RenderService().RenderTexture(RectS, _texture);
}

Sprite::~Sprite()
{
}
