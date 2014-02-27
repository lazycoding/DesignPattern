#pragma once
#include "Flyweight.h"
class ConcreteFlyweight :
	public Flyweight
{
public:
	ConcreteFlyweight();
	~ConcreteFlyweight();
	void Operation() override
	{
		++number_;
	}

private:
	int number_;
};

