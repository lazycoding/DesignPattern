#pragma once

namespace Strategy
{
	class Strategy
	{
	public:
		virtual ~Strategy(){}
		virtual void Algorithm() = 0;
	};
}