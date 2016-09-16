#pragma once

#include <stdio.h>

class GameScreen
{
	public:
		GameScreen();
		virtual void Update() = 0;
		virtual void Advance();
		virtual void Back();
		virtual void OnPressUp();
		virtual void OnPressDown();
		virtual void OnPressLeft();
		virtual void OnPressRight();
		virtual ~GameScreen();
};

