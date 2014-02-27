#include "ConcreteBuilder.h"
#include "ProductA.h"

ConcreteBuilder::ConcreteBuilder() :product_(std::make_shared<ProductA>())
{	
}


ConcreteBuilder::~ConcreteBuilder()
{
}

void ConcreteBuilder::StepA()
{
	product_->Foo();
}
void ConcreteBuilder::StepB()
{
	product_->Foo();
}
void ConcreteBuilder::StepC()
{
	product_->Foo();
}

std::shared_ptr<IProduct> ConcreteBuilder::GetProduct()
{
	return std::move(product_);
}