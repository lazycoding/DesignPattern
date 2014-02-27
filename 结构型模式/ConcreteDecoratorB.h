#pragma once
#include "Decorator.h"
//职责类（被用来动态添加到具体类）
class ConcreteDecoratorB :
	public Decorator
{
public:
	ConcreteDecoratorB(Component* component);
	~ConcreteDecoratorB();
	void Operation() override;

private:
	void OtherOperation();
};

