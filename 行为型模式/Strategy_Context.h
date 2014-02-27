#pragma once
#include <memory>

namespace Strategy
{
	class Strategy;
	class Context
	{
	public:
		Context(const std::shared_ptr<Strategy>& strategy)
			:strategy_(strategy)
		{}
		int GetResult(){ return 0; }
		void SetStrategy(const std::shared_ptr<Strategy>& strategy)
		{
			strategy_ = strategy;
		}
	private:
		std::shared_ptr<Strategy> strategy_;
	};
}