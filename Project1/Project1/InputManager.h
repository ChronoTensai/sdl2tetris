#pragma once

#include <SDL_system.h>
#include <SDL.h>
#include <map>
#include "InputHandler.h"
#include "InputDefintion.h"

using namespace std;

class InputManager
{
	public:
		InputManager();
		~InputManager();
		void CheckInputs(SDL_Event e);
		void RegisterInputHandler(InputHandler * inputHandler);
		void ClearInputs();
	private:
		InputHandler* _inputHandler;
		map<Uint32, InputDefinition::InputKeys> InputRegisters;
};