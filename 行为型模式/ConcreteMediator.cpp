#include "ConcreteMediator.h"


ConcreteMediator::ConcreteMediator()
{
}


ConcreteMediator::~ConcreteMediator()
{
}

void ConcreteMediator::Send(const std::string& message, Colleague* colleague)
{
	if (colleague == c1)
	{
		c2->OnReceiveMsg(message);
	}
	else if (colleague == c2)
	{
		c1->OnReceiveMsg(message);
	}
}