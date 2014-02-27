#pragma once
#include <string>
class Colleague;
class Mediator
{
public:

	Mediator()
	{
	}

	virtual ~Mediator()
	{
	}

	virtual void Send(const std::string& message, Colleague*)=0;
};

