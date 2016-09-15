#pragma once
#ifndef CustomInputManager_H
#endif CustomInputManager_H

#include <SDL_system.h>
#include <SDL.h>
#include <map>
#include "InputHandler.h"
#include "InputDefintion.h"


using namespace std;
using InputDefinition::InputKeys;



class CustomInputManager
{
	public:
		CustomInputManager();
		~CustomInputManager();
		void CheckInputs(SDL_Event e);
		void RegisterInput(InputKeys InputKey, InputHandler* callback);
		void ClearInputs();
	private:
		map<InputKeys, InputHandler*> InputMapping;
		map<Uint32, InputKeys> InputRegisters;
};