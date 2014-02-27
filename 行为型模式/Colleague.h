#pragma once
class Mediator;
class Colleague
{
public:

	Colleague(Mediator* mediator) :mediator_(mediator)
	{
	}

	virtual ~Colleague()
	{
	}

protected:
	Mediator* mediator_;
};

