#include "ConcreteColleague2.h"
#include "Mediator.h"
#include <iostream>
using namespace std;

ConcreteColleague2::ConcreteColleague2(Mediator* mediator)
:Colleague(mediator)
{
}


ConcreteColleague2::~ConcreteColleague2()
{
}

void ConcreteColleague2::Send(const std::string& message)
{
	mediator_->Send(message, this);
}

void ConcreteColleague2::OnReceiveMsg(const std::string& message)
{
	cout << "ConcreteColleague2 received message: \"" << message << "\"" << endl;
}