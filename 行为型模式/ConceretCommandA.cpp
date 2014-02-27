#include "ConceretCommandA.h"
#include "Receiver.h"

ConceretCommandA::ConceretCommandA(Receiver* receiver)
:Command(receiver)
{
}


ConceretCommandA::~ConceretCommandA()
{
}

void ConceretCommandA::Execute()
{
	if (receiver_)
	{
		receiver_->ActionA();
	}
}