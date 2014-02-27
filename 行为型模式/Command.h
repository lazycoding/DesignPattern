#pragma once
class Receiver;
class Command
{
public:
	Command(Receiver* receiver) :receiver_(receiver)
	{}
	virtual ~Command(){}
	virtual void Execute() = 0;
	int GetId() const
	{
		return id_;
	}

protected:
	Receiver* receiver_;
	int id_;
};

