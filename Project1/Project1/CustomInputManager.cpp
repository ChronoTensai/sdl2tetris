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

void CustomInputManager::RegisterInput(InputKeys InputKey, inputCallback callback)
{
	InputMapping[InputKey] = callback;
}

void CustomInputManager::ClearInputs()
{
	InputMapping.clear();
}

void CustomInputManager::CheckInputs(SDL_Event e)
{
	InputKeys inputNumber = InputRegisters[e.key.keysym.sym];
	if (inputNumber != NULL)
	{	
		inputCallback callBack = InputMapping[inputNumber]; //Handle Null case
		if (callBack != NULL) callBack();
		else printf("Callback not Registerd \n");
	}
	else
		printf("Input not Registerd \n");
}



CustomInputManager::~CustomInputManager()
{
}
