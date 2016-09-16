#include "InputManager.h"

InputManager::InputManager() 
{
	InputRegisters[SDLK_UP] = InputDefinition::UP;
	InputRegisters[SDLK_DOWN] = InputDefinition::DOWN;
	InputRegisters[SDLK_LEFT] = InputDefinition::LEFT;
	InputRegisters[SDLK_RIGHT] = InputDefinition::RIGHT;
	InputRegisters[SDLK_RETURN] = InputDefinition::ADVANCE;
	InputRegisters[SDLK_ESCAPE] = InputDefinition::BACK;	
}

void InputManager::ClearInputs()
{
	_inputHandler = NULL;
}

void InputManager::RegisterInputHandler(InputHandler * inputHandler)
{
	_inputHandler = inputHandler;
}


void InputManager::CheckInputs(SDL_Event e)
{
	InputDefinition::InputKeys inputNumber = InputRegisters[e.key.keysym.sym];
	if (inputNumber != NULL)
	{	
		switch (inputNumber)
		{
			case InputDefinition::ADVANCE:
				_inputHandler->Advance();
				break;
			case InputDefinition::BACK:
				_inputHandler->Back();
				break;
			case InputDefinition::UP:
				_inputHandler->OnPressUp();
				break;
			case InputDefinition::DOWN:
				_inputHandler->OnPressDown();
				break;
			case InputDefinition::LEFT:
				_inputHandler->OnPressLeft();
				break;
			case InputDefinition::RIGHT:
				_inputHandler->OnPressRight();
				break;
			default:
				printf("Callback not Registerd \n");
				break;
		}
	}
	else
		printf("Input not Registerd \n");
}

InputManager::~InputManager()
{
}
