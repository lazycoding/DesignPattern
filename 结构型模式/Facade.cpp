#include "Facade.h"
#include "SubSystemA.h"
#include "SubSystemB.h"

Facade::Facade()
{
}


Facade::~Facade()
{
}

void Facade::Foo()
{
	SubSystemA a;
	a.FuncA();
	SubSystemB b;
	b.FuncB();
}

void Facade::Bar()
{
	SubSystemA a;
	a.FuncC();
	SubSystemB b;
	b.FuncD();
}
