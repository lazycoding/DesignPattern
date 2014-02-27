#pragma once
#include "Visitor.h"
#include "ConcreteElementA.h"
#include "concreteelementb.h"
namespace visitor
{
	class ConcreteVisitor :
		public Visitor
	{
	public:
		ConcreteVisitor();
		~ConcreteVisitor();
		virtual void VisitConcreteElementA(ConcreteElementA* ca)
		{
			//do something...
		}
		virtual void VisitConcreteElementB(ConcreteElementB* cb)
		{
			//do something...
		}
	};

}