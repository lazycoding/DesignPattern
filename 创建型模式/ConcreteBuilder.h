#pragma once
#include "Builder.h"
class ConcreteBuilder :
	public Builder
{
public:
	ConcreteBuilder();
	~ConcreteBuilder();
	void StepA();
	void StepB();
	void StepC();
	std::shared_ptr<IProduct> GetProduct();

private:
	std::shared_ptr<IProduct> product_;
};

