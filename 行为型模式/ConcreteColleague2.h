#pragma once
#include "Colleague.h"
#include <string>
class ConcreteColleague2 :
	public Colleague
{
public:
	ConcreteColleague2(Mediator* mediator);
	~ConcreteColleague2();
	void Send(const std::string& message);
	void OnReceiveMsg(const std::string& message);
};

