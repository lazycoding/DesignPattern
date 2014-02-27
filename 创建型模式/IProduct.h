#pragma once
class IProduct
{
public:
	IProduct() = default;
	virtual ~IProduct() = default;
	virtual void Foo() = 0;
};

