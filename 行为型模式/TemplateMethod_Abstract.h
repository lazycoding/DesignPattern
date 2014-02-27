#pragma once

namespace templatemethod
{
	class AbstractClass
	{
	public:
		void TemplateMethod();
		virtual ~AbstractClass();
	protected:
		virtual void PrimitiOperation() = 0;
	};
}