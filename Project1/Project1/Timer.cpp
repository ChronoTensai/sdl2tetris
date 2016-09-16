#include "Timer.h"

//Me gustaria hacer esto con callbacks.

RecursiveTimer::RecursiveTimer(float delay)
{
	_delay = delay;
	_targetTime = SDL_GetTicks() + delay;
}

void RecursiveTimer::ResetTimer()
{
	_targetTime = SDL_GetTicks() + _delay;
}

bool RecursiveTimer::TimerComplete()
{
	return (SDL_GetTicks() >= _targetTime);
}

RecursiveTimer::~RecursiveTimer()
{
}
