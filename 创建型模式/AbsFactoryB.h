#pragma once
#include "AbstracFactory.h"
class AbsFactoryB:public AbstracFactory
{
public:

	AbsFactoryB()
	{
	}

	~AbsFactoryB()
	{
	}

	std::shared_ptr<INewProduct> CreateNewProduct() override;

	std::shared_ptr<IProduct> CreateProduct() override;
};

