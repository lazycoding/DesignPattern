#pragma once
#include "Handler.h"
#include "Request.h"
class ConcreteHandlerB :
	public Handler
{
public:
	ConcreteHandlerB();
	~ConcreteHandlerB();
	virtual void SetSuccessor(Handler* successor)
	{
		successor_ = successor;
	}
	virtual void Handle(const Request& request)
	{
		if (request.Type() < 5)
		{
			//...DoHandle
			return;
		}
		if (!successor_)
		{
			successor_->Handle(request);
		}
	}
};

