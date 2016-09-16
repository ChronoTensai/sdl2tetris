#pragma once

#include "GameScreen.h"
#include "Game.h"

class MainMenu : public GameScreen
{
	public:
		MainMenu();
		~MainMenu();
		virtual void Advance() override;
		virtual void OnPressUp() override;
		virtual void Update() override;
	private:
		Game* _game;		
};
		
		

