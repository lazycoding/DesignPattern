#pragma once
class Request;
class Handler
{
public:

	Handler()
	{
	}

	virtual ~Handler()
	{
	}

	virtual void SetSuccessor(Handler*) = 0;
	virtual void Handle(const Request&) = 0;

protected:
	Handler*	successor_;
};

