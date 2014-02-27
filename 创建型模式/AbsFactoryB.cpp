#include "AbsFactoryB.h"
#include "ProductB.h"
#include "NewProductB.h"
std::shared_ptr<INewProduct> AbsFactoryB::CreateNewProduct()
{
	return std::shared_ptr<INewProduct>(new NewProductB);
}

std::shared_ptr<IProduct> AbsFactoryB::CreateProduct()
{
	return std::shared_ptr<IProduct>(new ProductB);
}