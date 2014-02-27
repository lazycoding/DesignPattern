#include "ConcreteColleague1.h"
#include "Mediator.h"
#include <iostream>
using namespace std;
ConcreteColleague1::ConcreteColleague1(Mediator* mediator)
:Colleague(mediator)
{
}


ConcreteColleague1::~ConcreteColleague1()
{
}

void ConcreteColleague1::Send(const std::string& message)
{
	mediator_->Send(message, this);
}

void ConcreteColleague1::OnReceiveMsg(const std::string& message)
{
	cout << "ConcreteColleague1 received message: \"" << message << "\"" << endl;
}