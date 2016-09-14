#pragma once

namespace InputDefinition
{
	typedef void(*inputCallback)();

	enum  InputKeys
	{
		ANY,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		NUM1,
		NUM2,
		RETURN,
		ESCAPE
	};
}