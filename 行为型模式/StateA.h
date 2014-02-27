#pragma once
#include "State.h"
class StateA :
	public State
{
public:
	StateA();
	~StateA();
	void Request(Context* ctx);
};

