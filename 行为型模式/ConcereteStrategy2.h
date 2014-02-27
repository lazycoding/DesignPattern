#pragma once
#include "Strategy.h"

namespace Strategy
{

	class ConcereteStrategy2 :
		public Strategy
	{
	public:
		ConcereteStrategy2();
		~ConcereteStrategy2();
		void Algorithm();
	};


}