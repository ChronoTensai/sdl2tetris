#include "CustomInputManager.h"


CustomInputManager::CustomInputManager() 
{
	InputRegisters[SDLK_UP] = InputKeys::UP;
	InputRegisters[SDLK_DOWN] = InputKeys::DOWN;
	InputRegisters[SDLK_LEFT] = InputKeys::LEFT;
	InputRegisters[SDLK_RIGHT] = InputKeys::RIGHT;
	InputRegisters[SDLK_1] = InputKeys::NUM1;
	InputRegisters[SDLK_2] = InputKeys::NUM2;
	InputRegisters[SDLK_KP_ENTER] = InputKeys::RETURN;
	InputRegisters[SDLK_ESCAPE] = InputKeys::ESCAPE;	
}

void CustomInputManager::RegisterInput(InputKeys InputKey, void(*callback)())
{
	InputMapping[InputKey] = callback;
}

void CustomInputManager::ClearInputs()
{
	InputMapping.clear();
}

void CustomInputManager::CheckInputs(SDL_Event e)
{
	inputCallback callBack = InputMapping[InputRegisters[e.key.keysym.sym]]; //Handle Null case
	if (callBack != NULL) callBack();
	else printf("Input Not Registed \n"); 
}

CustomInputManager::~CustomInputManager()
{
}
