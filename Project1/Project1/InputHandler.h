#pragma once

#include "GameScreen.h"

class InputHandler {
public:
	InputHandler() {};
	InputHandler(GameScreen* gameScreen) { _gameScreen = gameScreen; };
	virtual void Advance() {_gameScreen->Advance();}
	virtual void Back() {_gameScreen->Back();}
	virtual void OnPressUp() { _gameScreen->OnPressUp(); }
	virtual void OnPressDown() { _gameScreen->OnPressDown(); }
	virtual void OnPressLeft() { _gameScreen->OnPressLeft(); }
	virtual void OnPressRight() { _gameScreen->OnPressRight(); }
	virtual ~InputHandler() { _gameScreen = nullptr; };
private:
	GameScreen* _gameScreen;
};
