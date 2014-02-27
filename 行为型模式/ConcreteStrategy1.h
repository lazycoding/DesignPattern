#pragma once
#include "Strategy.h"

namespace Strategy
{

	class ConcreteStrategy1 :
		public Strategy
	{
	public:
		ConcreteStrategy1();
		~ConcreteStrategy1();
		void Algorithm();
	};

}