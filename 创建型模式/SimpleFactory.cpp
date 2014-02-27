#include "SimpleFactory.h"
#include "ProductA.h"
#include "ProductB.h"
using namespace std;

shared_ptr<IProduct> SimpleFactory::Create(const char* product_name)
{	
	if (_stricmp(product_name, "ProductA") == 0)
	{
		return make_shared<ProductA>();
	}
	else
	{
		return make_shared<ProductB>();
	}
}