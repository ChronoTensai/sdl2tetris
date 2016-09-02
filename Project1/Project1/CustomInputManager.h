#pragma once
#ifndef CustomInputManager_H
#endif CustomInputManager_H

#include <SDL_system.h>
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <map>

class CustomInputManager
{
	public:
		CustomInputManager();
		~CustomInputManager();
		void CheckInputs(SDL_Event e);
		void RegisterInput(Uint32 InputKey, void(*callback)());
};