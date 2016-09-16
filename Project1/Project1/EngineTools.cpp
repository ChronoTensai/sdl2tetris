#include "EngineTools.h"

//This variable should only return function pointer, not the full class
InputManager* EngineTools::_inputManager = nullptr;
RenderManager* EngineTools::_renderService = nullptr;

bool EngineTools::_engineToolsInitialized = false;

void EngineTools::InitializeEngineTools(InputManager* iM, SDL_Window *win, SDL_Renderer *renderer)
{
	if (!EngineTools::_engineToolsInitialized)
	{
		EngineTools::_inputManager = iM;
		EngineTools::_renderService = new RenderManager(renderer, win);
		EngineTools::_engineToolsInitialized = true;
	}
}

void EngineTools::FinalizeEngineTools()
{
	EngineTools::_engineToolsInitialized = false;

	delete EngineTools::_inputManager;
	EngineTools::_inputManager = nullptr;
	
	delete EngineTools::_renderService;
	EngineTools::_renderService = nullptr;
}

InputManager& EngineTools::InputService()
{
	assert(EngineTools::_engineToolsInitialized);
	return *_inputManager;
}
RenderManager& EngineTools::RenderService()
{
	assert(EngineTools::_engineToolsInitialized);
	return *_renderService;
}

EngineTools::~EngineTools()
{
	
}


