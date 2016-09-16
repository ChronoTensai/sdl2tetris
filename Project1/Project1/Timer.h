#pragma once

#include <SDL.h>

class RecursiveTimer
{
public:
	RecursiveTimer() {};
	RecursiveTimer(float delay);
	void ResetTimer();
	bool TimerComplete();
	~RecursiveTimer();
private:	
	float _targetTime;
	float _delay;

};

