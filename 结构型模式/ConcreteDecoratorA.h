#pragma once
#include "Decorator.h"
class Component;

//ְ���ࣨ��������̬��ӵ������ࣩ
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

