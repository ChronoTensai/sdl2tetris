#pragma once

#include <assert.h>
#include "CustomInputManager.h"
#include "RenderManager.h"


class EngineTools
{
	public:
		static void InitializeEngineTools(CustomInputManager* iM, SDL_Window* win, SDL_Renderer* renderer);
		static void FinalizeEngineTools();
		static CustomInputManager & InputService();
		static RenderManager & RenderService();
		~EngineTools();
	private:
		EngineTools();
		static bool _engineToolsInitialized;
		static CustomInputManager* _inputManager;
		static RenderManager* _renderService;		
};


