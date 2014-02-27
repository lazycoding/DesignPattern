#pragma once
#include "INewProduct.h"
#include <iostream>
class NewProduct :
	public INewProduct
{
public:
	NewProduct();
	~NewProduct();
	void Bar()
	{
		std::cout << "NewProduct::Bar" << std::endl;
	}
};

