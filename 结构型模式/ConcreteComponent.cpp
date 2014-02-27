#include "ConcreteComponent.h"

#include <iostream>
using namespace std;
ConcreteComponent::ConcreteComponent()
{
}


ConcreteComponent::~ConcreteComponent()
{
}

void ConcreteComponent::Operation()
{
	cout << "ConcreteCom" << endl;
}