#pragma once
#ifndef CustomInputManager_H
#endif CustomInputManager_H

#include <SDL_system.h>
#include <SDL.h>
#include <map>
#include "InputDefintion.h"

using namespace std;
using InputDefinition::InputKeys;

typedef void(*inputCallback)();

class CustomInputManager
{
	public:
		CustomInputManager();
		~CustomInputManager();
		void CheckInputs(SDL_Event e);
		void RegisterInput(InputKeys InputKey, inputCallback callback);
		void ClearInputs();
	private:
		map<InputKeys, inputCallback> InputMapping;
		map<Uint32, InputKeys> InputRegisters;
};