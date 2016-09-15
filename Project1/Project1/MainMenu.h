#pragma once

#include <stdio.h>
#include "EngineTools.h"
#include "Game.h"




class MainMenu
{
	public:
		MainMenu();
		void CallbackOne();
		~MainMenu();
	private:
		typedef  void (MainMenu::*MainMenuPtr)();

		class FirstCallback : public InputHandler
		{
		public:
			FirstCallback(MainMenuPtr callbackPtr) { _callback = callbackPtr; };
			virtual void Callback() override { /*_callback();*/ }
		private:
			MainMenuPtr _callback;
		};

		FirstCallback* Test;
		
		/**/
		class SecondCallback : public InputHandler
		{
		public:
			SecondCallback(Game* callbackPtr) { _callback = callbackPtr; };
			virtual void Callback() override { _callback->RotateTetrominio();}
		private:
			Game* _callback;
		};
		SecondCallback* TestTwo;
		
		Game* _game;
};

