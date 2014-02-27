#pragma once
#include <memory>

class State;
class Context
{
public:
	Context();
	~Context();
	void Request();
	int GetTime() const
	{
		return time_;
	}
	void SetState(const std::shared_ptr<State>& state)
	{
		current_state_ = state;
	}
	void IncreaseTime()
	{
		++time_;
	}
private:
	std::shared_ptr<State> current_state_;
	int time_;
};

