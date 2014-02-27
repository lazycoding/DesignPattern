#pragma once
#include "IFactory.h"
#include "ProductB.h"
class FactoryB : public IFactory
{
public:
	FactoryB()
	{
	}

	virtual ~FactoryB()
	{
	}

	std::shared_ptr<IProduct> Create() override
	{
		return std::make_shared<ProductB>();
	}
};
