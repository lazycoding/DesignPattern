#pragma once
#include "INewProduct.h"
#include "IProduct.h"
#include <memory>
class AbstracFactory
{
public:
	AbstracFactory() = default;
	virtual ~AbstracFactory() = default;
	virtual std::shared_ptr<INewProduct> CreateNewProduct() = 0;
	virtual std::shared_ptr<IProduct> CreateProduct() = 0;
};

