#include "AbsFactoryA.h"
#include "ProductA.h"
#include "NewProduct.h"
std::shared_ptr<INewProduct> AbsFactoryA::CreateNewProduct()
{
	return std::make_shared<NewProduct>();
}

std::shared_ptr<IProduct> AbsFactoryA::CreateProduct()
{
	return std::make_shared<ProductA>();
}