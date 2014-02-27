#pragma once
#include "AbstracFactory.h"
class AbsFactoryA : public AbstracFactory
{
public:

	AbsFactoryA()
	{
	}

	~AbsFactoryA()
	{
	}

	std::shared_ptr<INewProduct> CreateNewProduct() override;
	
	std::shared_ptr<IProduct> CreateProduct() override;
	
};

