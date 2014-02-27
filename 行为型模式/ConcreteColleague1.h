#pragma once
#include "Colleague.h"
#include <string>
class ConcreteColleague1 :
	public Colleague
{
public:
	ConcreteColleague1(Mediator* mediator);
	~ConcreteColleague1();
	void Send(const std::string& message);
	void OnReceiveMsg(const std::string& message);
};

