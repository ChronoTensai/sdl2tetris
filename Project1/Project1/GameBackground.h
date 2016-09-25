#pragma once

#include "Sprite.h"


class GameBackground
{
public:
	GameBackground() {};
	~GameBackground() {};
	void RedrawBackground() { _background.Redraw(); };
	void RedrawForeground() { _foreground.Redraw(); };
private:
	const string BACKGROUND_PATH = "Assets/Gameplay/background.jpg";
	SpriteBackground _background = SpriteBackground(BACKGROUND_PATH);
	const string FOREGROUND_PATH = "Assets/Gameplay/foreground.jpg";
	const int WIDTH_FOREGROUND = 800;
	const int HEIGHT_FOREGROUND = 45;
	Sprite _foreground = Sprite(FOREGROUND_PATH, 0, 0, WIDTH_FOREGROUND, HEIGHT_FOREGROUND);
};

