#include "ConceretCommandB.h"
#include "Receiver.h"

ConceretCommandB::ConceretCommandB(Receiver* receiver)
:Command(receiver)
{
}


ConceretCommandB::~ConceretCommandB()
{
}

void ConceretCommandB::Execute()
{
	if (receiver_)
	{
		receiver_->ActionB();
	}
}