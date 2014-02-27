#pragma once
#include "TemplateMethod_Abstract.h"

namespace templatemethod{
class ConcreteClass :
	public AbstractClass
{
public:
	ConcreteClass();
	~ConcreteClass();
protected:
	void PrimitiOperation() override;
};

}