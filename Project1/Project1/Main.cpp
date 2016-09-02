#include <stdio.h>
#include "GameLoop.h"

int main(int argc, char ** argv)
{
	GameLoop* gLoop = new GameLoop();
	gLoop->Start();

	return 0;
}