#pragma once
#include <memory>
class IProduct;
class IFactory
{
public:

	IFactory()
	{
	}

	virtual ~IFactory()
	{
	}

	virtual std::shared_ptr<IProduct> Create() = 0;
};

