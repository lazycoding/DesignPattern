#pragma once
#include "INewProduct.h"
#include <iostream>
class NewProductB:public INewProduct
{
public:

	NewProductB()
	{
	}

	~NewProductB()
	{
	}

	void Bar()
	{
		std::cout << "NewProductB::Bar" << std::endl;
	}
};

