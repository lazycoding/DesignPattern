#pragma once
#include "Adapter.h"
class Client
{
public:

	Client(Adapter* adapter) :adapter_(adapter)
	{
	}

	~Client()
	{
	}

	//ʹ��Foo�� Bar�ӿ�
	void Do()
	{
		adapter_->Foo();
		adapter_->Bar();
	}

private:
	Adapter* adapter_;
};

