#pragma once
#include "Decorator.h"
//ְ���ࣨ��������̬��ӵ������ࣩ
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

