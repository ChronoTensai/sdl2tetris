#pragma once

#include "EngineTools.h"

class RecursiveTimer
{
public:
	RecursiveTimer() {};
	RecursiveTimer(float delay);
	void SetDelay(float delay);
	void ResetTimer();
	bool TimerComplete();
	~RecursiveTimer();
private:	
	float _targetTime;
	float _delay;

};

class FrameTimer
{
	public:
		FrameTimer() {};
		void StartTimer(float delay);
		int CurrentFrame();
		bool FrameTimerComplete();
		~FrameTimer();
	private:
		float _targetFrame;
};

