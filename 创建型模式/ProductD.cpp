#include "ProductD.h"
using std::string;

ProductD::ProductD() :name_(new string)
{
	
}


ProductD::~ProductD()
{
	delete name_;
	name_ = nullptr;
}

Prototype* ProductD::Clone() const
{
	ProductD* d = new ProductD;
	*(d->name_) = *name_;
	return d;
}

void ProductD::Name(const string& name)
{
	*name_ = name;
}

string ProductD::Name() const
{
	return *name_;
}