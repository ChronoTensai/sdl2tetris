#include "GameEngine.h"
#include "GameManager.h"


#ifndef GaneLoop_H
#endif GaneLoop_H

class GameLoop
{

public:
	GameLoop();
	void Start();
	~GameLoop();


private:
	void Looping();
	void EndLoop();
};

