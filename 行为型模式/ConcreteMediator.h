#pragma once
#include "Mediator.h"
#include "ConcreteColleague1.h"
#include "ConcreteColleague2.h"

class ConcreteMediator :
	public Mediator
{
public:
	ConcreteMediator();
	~ConcreteMediator();
	void SetC1(ConcreteColleague1* c){ c1 = c; }
	void SetC2(ConcreteColleague2* c){ c2 = c; }
	void Send(const std::string& message, Colleague*);

private:
	ConcreteColleague1* c1;
	ConcreteColleague2* c2;
};

