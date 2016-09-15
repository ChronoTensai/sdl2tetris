#include "MainMenu.h"

MainMenu::MainMenu()
{
	

	_game = new Game();
	TestTwo = new SecondCallback(_game);
	EngineTools::InputService().RegisterInput(InputDefinition::UP, TestTwo);
}

void MainMenu::CallbackOne()
{
	printf("MainMenu CallbackOne");
}

MainMenu::~MainMenu()
{
}
