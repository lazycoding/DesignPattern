#pragma once
#include <memory>
#include <vector>
#include "Command.h"
class Invoker
{
public:
	Invoker();
	~Invoker();

	void AddCommand(const std::shared_ptr<Command>& command)
	{
		commands_.push_back(command);
	}

	void Remove(const std::shared_ptr<Command>& command)
	{
		auto it = std::find(begin(commands_), end(commands_), command);
		if (it != end(commands_))
		{
			commands_.erase(it);
		}
	}

	void DoCommand()
	{
		for (size_t i = 0; i < commands_.size(); i++)
		{
			commands_[i]->Execute();
		}
	}
private:
	std::vector<std::shared_ptr<Command>>  commands_;
};

