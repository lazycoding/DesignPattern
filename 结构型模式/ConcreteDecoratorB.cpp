#include "ConcreteDecoratorB.h"
#include <iostream>
using namespace std;

ConcreteDecoratorB::ConcreteDecoratorB(Component* component)
:Decorator(component)
{
}


ConcreteDecoratorB::~ConcreteDecoratorB()
{
}

void ConcreteDecoratorB::Operation()
{
	OtherOperation();
	component_->Operation();
}

void ConcreteDecoratorB::OtherOperation()
{
	cout << "Decorator B" << endl;
}