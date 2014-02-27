#pragma once
#include "IFactory.h"
#include "ProductA.h"
class FactoryA:public IFactory
{
public:

	FactoryA()
	{
	}

	~FactoryA()
	{
	}

	std::shared_ptr<IProduct> Create() override
	{
		return std::make_shared<ProductA>();
	}
};

