#pragma once
#include "IProduct.h"
class ProductB :
	public IProduct
{
public:
	ProductB();
	~ProductB();
	void Foo() override;
};

