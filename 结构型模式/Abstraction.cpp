#include "Abstraction.h"
#include "Implementor.h"

Abstraction::Abstraction() 
:impl_(std::make_shared<Implementor>())
{
}


Abstraction::~Abstraction()
{
}

void Abstraction::Foo()
{
	impl_->Foo();
}

void Abstraction::Bar()
{
	impl_->Bar();
}