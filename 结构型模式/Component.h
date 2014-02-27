#pragma once
//可以动态添加职责的类的接口类
class Component
{
public:

	Component()
	{
	}

	virtual ~Component()
	{
	}

	virtual void Operation() = 0;
};

