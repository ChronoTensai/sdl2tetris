#include "CustomInputManager.h"

typedef void(*inputCallback)();
std::map<Uint32, inputCallback> InputMapping;

CustomInputManager::CustomInputManager() {}

void CustomInputManager::RegisterInput(Uint32 InputKey, void(*callback)())
{
	InputMapping[InputKey] = callback;
}

void CustomInputManager::CheckInputs(SDL_Event e)
{
	/*switch (e.key.keysym.sym)
	{
		case SDLK_UP:
			printf("SDLK_UP \n");
			break;
		case SDLK_DOWN:
			printf("SDLK_DOWN \n");
			break;
		case SDLK_LEFT:
			printf("SDLK_LEFT \n");
			break;
		case SDLK_RIGHT:
			printf("SDLK_RIGHT \n");
			break;
		case SDLK_1:
			printf("SDLK_1 \n");
			break;
		case SDLK_2:
			printf("SDLK_2 \n");
			break;
		case SDLK_RETURN:
			printf("SDLK_KP_ENTER \n");
			break;
		case SDLK_ESCAPE:
			printf("SDLK_ESCAPE \n");
			break;
	}*/

	inputCallback callBack = InputMapping[e.key.keysym.sym];
	if (callBack != NULL) callBack();
	else printf("Input Not Registed \n"); 
}

CustomInputManager::~CustomInputManager()
{
}
