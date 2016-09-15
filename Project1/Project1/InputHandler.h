#pragma once

class InputHandler {
public:
	virtual void Callback() = 0;
	virtual ~InputHandler() = 0;
};

inline InputHandler::~InputHandler() { }