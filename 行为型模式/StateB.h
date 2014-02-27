#pragma once
#include "State.h"
class StateB :
	public State
{
public:
	StateB();
	~StateB();
	void Request(Context* ctx);
};

