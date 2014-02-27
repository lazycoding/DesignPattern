#pragma once
#include "Handler.h"
#include "Request.h"
class ConcreteHandler :
	public Handler
{
public:
	ConcreteHandler();
	~ConcreteHandler();

	virtual void SetSuccessor(Handler* successor)
	{
		successor_ = successor;
	}
	virtual void Handle(const Request& request)
	{
		if (request.Type() < 2)
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

