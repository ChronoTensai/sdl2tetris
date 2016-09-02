#ifndef GameEngine_h
#endif GameEngine_h
#pragma once

#include <SDL.h>
#include <stdio.h>
#include "EngineTools.h"
#include "CustomInputManager.h"
#include "RenderManager.h"
#include "ScreenManager.h"


class GameEngine
{
	public:
		GameEngine();
		bool Start();
		~GameEngine();		
		void BeforeUpdate(bool* IsRunning);
		void AfterUpdate();

	private:
		bool InitVideo();
		bool CreateWindowRendered();
		const int SCREEN_WIDHT = 800;
		const int SCREEN_HEIGTH = 600;
		SDL_Window* window;
		SDL_Renderer* renderer;
		CustomInputManager* inputManager;
		SDL_Event Event;
};





