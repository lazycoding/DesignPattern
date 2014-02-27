#include "ConcreteDecoratorA.h"
#include <iostream>
using namespace std;

ConcreteDecoratorA::ConcreteDecoratorA(Component* component)
:Decorator(component)
{
}


ConcreteDecoratorA::~ConcreteDecoratorA()
{
}

void ConcreteDecoratorA::Operation()
{
	component_->Operation();
	OtherOperation();
}

void ConcreteDecoratorA::OtherOperation()
{
	cout << "DecoratorA operation" << endl;
}