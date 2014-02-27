#pragma once

namespace visitor
{
	class ConcreteElementA;
	class ConcreteElementB;
	class Visitor
	{
	public:
		virtual ~Visitor(){}
		virtual void VisitConcreteElementA(ConcreteElementA*) = 0;
		virtual void VisitConcreteElementB(ConcreteElementB*) = 0;
	};
}