#pragma once
class Context;
class State
{
public:

	State()
	{
	}

	virtual ~State()
	{
	}

	virtual void Request(Context* ctx) = 0;
};

