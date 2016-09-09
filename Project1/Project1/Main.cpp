#include <stdio.h>
#include "GameLoop.h"

int main(int argc, char ** argv)
{
	GameLoop* gLoop = new GameLoop();

	gLoop->Start();
	
	delete gLoop;
	gLoop = nullptr;

	return 0;
}