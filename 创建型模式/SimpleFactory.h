#pragma once
#include <memory>
class IProduct;
class SimpleFactory
{
public:
	static std::shared_ptr<IProduct> Create(const char* product_name);
};

