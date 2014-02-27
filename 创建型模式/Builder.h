#pragma once
#include <memory>
class IProduct;
class Builder
{
public:

	Builder()
	{
	}

	virtual ~Builder()
	{
	}
	
	virtual void StepA() = 0;
	virtual void StepB() = 0;
	virtual void StepC() = 0;
	virtual std::shared_ptr<IProduct> GetProduct() = 0;
};

