#pragma once
#include "Component.h"
class Decorator:public Component
{
public:

	Decorator(Component* component)
		:component_(component)
	{
	}

	virtual ~Decorator()
	{
	}

protected:
	Component* component_;
};

