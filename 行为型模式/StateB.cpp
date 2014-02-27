#include "StateB.h"
#include "Context.h"
#include <iostream>
using namespace std;

StateB::StateB()
{
}


StateB::~StateB()
{
}

void StateB::Request(Context* ctx)
{
	if (3 <= ctx->GetTime() && ctx->GetTime() < 5)
	{
		cout << "State.Request" << endl;
	}
	else
	{
		ctx->SetState(nullptr);
		ctx->Request();
	}
}