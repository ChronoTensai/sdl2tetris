#include "Timer.h"

//Me gustaria hacer esto con callbacks.

RecursiveTimer::RecursiveTimer(float delay)
{
	_delay = delay;
	_targetTime = SDL_GetTicks() + delay;
}

void RecursiveTimer::SetDelay(float delay) 
{
	_delay = delay;
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


void FrameTimer::StartTimer(float delay)
{
	_targetFrame = EngineTools::FrameCount + delay;
}

int FrameTimer::CurrentFrame()
{
	return _targetFrame - EngineTools::FrameCount;
}

bool FrameTimer::FrameTimerComplete()
{
	return EngineTools::FrameCount >= _targetFrame;
}

FrameTimer::~FrameTimer()
{
}
