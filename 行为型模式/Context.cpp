#include "Context.h"

#include "StateA.h"
using namespace std;
Context::Context() :current_state_(make_shared<StateA>()), time_(0)
{
}


Context::~Context()
{
}

void Context::Request()
{	
	if (current_state_)
	{
		current_state_->Request(this);
	}
}