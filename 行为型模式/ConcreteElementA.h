#pragma once
#include "Element.h"
#include "Visitor.h"
namespace visitor
{
	class ConcreteElementA:public Element
	{
	public:
		ConcreteElementA()
		{
		}

		~ConcreteElementA()
		{
		}

		void Accept(Visitor* visitor)
		{			
			visitor->VisitConcreteElementA(this);
		}

		void OperationA()
		{

		}
	private:

	};

}