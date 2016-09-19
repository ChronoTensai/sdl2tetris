#pragma once

#include "RenderManager.h"
#include "InputManager.h"
#include <assert.h>


class EngineTools
{
	public:
		static int FrameCount;
		static void InitializeEngineTools(InputManager* iM, SDL_Window* win, SDL_Renderer* renderer);
		static void FinalizeEngineTools();
		static InputManager& InputService();
		static RenderManager& RenderService();
		~EngineTools();
	private:
		EngineTools();
		static bool _engineToolsInitialized;
		static InputManager* _inputManager;
		static RenderManager* _renderService;		
};


