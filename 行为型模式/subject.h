#pragma once
#include "Observer.h"
#include <vector>
#include <algorithm>
class Subject
{
public:
	Subject()
	{
	}

	virtual ~Subject()
	{
	}

	void Attach(Observer* ob)
	{
		observers_.push_back(ob);
	}

	void Detach(Observer* ob)
	{
		auto it = std::remove_if(observers_.begin(), observers_.end(),
			[&](Observer* observer)->bool{
			return observer == ob;
		});
		if (it != observers_.end())
		{
			observers_.erase(it);
		}
	}

	void Notify()
	{
		for_each(observers_.begin(), observers_.end(), 
			[](Observer* observer){
			observer->Update();
		}
		);
	}
private:
	std::vector<Observer*> observers_;
};
