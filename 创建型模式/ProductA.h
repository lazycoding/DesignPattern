#pragma once
#include "IProduct.h"
class ProductA :
	public IProduct
{
public:
	ProductA();
	~ProductA();
	void Foo() override;
};

