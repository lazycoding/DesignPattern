#pragma once

namespace visitor
{
	class Visitor;
	class Element
	{
	public:
		Element()
		{
		}

		virtual ~Element()
		{
		}
		
		virtual void Accept(Visitor*) = 0;

	};

}