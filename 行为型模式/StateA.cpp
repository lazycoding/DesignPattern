#include "StateA.h"
#include "Context.h"
#include "StateB.h"
#include <iostream>
using namespace std;
StateA::StateA()
{
}


StateA::~StateA()
{
}

void StateA::Request(Context* ctx)
{
	if (ctx->GetTime() < 3)
	{
		cout << "StateA.Request" << endl;
	}
	else
	{
		ctx->SetState(make_shared<StateB>());
		ctx->Request();
	}	
}