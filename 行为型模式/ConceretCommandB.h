#pragma once
#include "Command.h"
class ConceretCommandB :
	public Command
{
public:
	ConceretCommandB(Receiver* receiver);
	~ConceretCommandB();
	void Execute();
};

