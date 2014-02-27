#pragma once
#include "Decorator.h"
class Component;

//职责类（被用来动态添加到具体类）
class ConcreteDecoratorA :
	public Decorator
{
public:
	ConcreteDecoratorA(Component* component);
	~ConcreteDecoratorA();
	void Operation() override;
private:
	void OtherOperation();
};

