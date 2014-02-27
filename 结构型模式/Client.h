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

	//使用Foo， Bar接口
	void Do()
	{
		adapter_->Foo();
		adapter_->Bar();
	}

private:
	Adapter* adapter_;
};

