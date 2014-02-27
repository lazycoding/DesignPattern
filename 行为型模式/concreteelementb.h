#pragma once
#include "Element.h"
#include "Visitor.h"
namespace visitor
{
	class ConcreteElementB : public Element
	{
	public:
		ConcreteElementB()
		{
		}

		~ConcreteElementB()
		{
		}

		void Accept(Visitor* visitor)
		{
			visitor->VisitConcreteElementB(this);
		}

		void OperationB()
		{

		}

	private:

	};

}