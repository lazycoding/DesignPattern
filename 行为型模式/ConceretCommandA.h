#pragma once
#include "Command.h"
class ConceretCommandA :
	public Command
{
public:
	ConceretCommandA(Receiver* receiver);
	~ConceretCommandA();
	virtual void Execute();
};

