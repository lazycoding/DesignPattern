#pragma once
#include "Component.h"

//��������ࣨ���Ա���̬���ְ��
class ConcreteComponent :
	public Component
{
public:
	ConcreteComponent();
	~ConcreteComponent();
	void Operation() override;
};

