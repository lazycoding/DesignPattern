#pragma once
#include "Component.h"

//具体对象类（可以被动态添加职责）
class ConcreteComponent :
	public Component
{
public:
	ConcreteComponent();
	~ConcreteComponent();
	void Operation() override;
};

