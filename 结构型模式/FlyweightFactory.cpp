#include "FlyweightFactory.h"
#include "concreteflyweight.h"

FlyweightFactory::FlyweightFactory()
{
}


FlyweightFactory::~FlyweightFactory()
{
	for each (auto  var in flyweights_)
	{
		delete var.second;
		var.second = nullptr;
	}
	flyweights_.clear();
}

Flyweight* FlyweightFactory::GetFlyweight(const std::string& key)
{
	if (flyweights_.find(key) == end(flyweights_))
	{
		flyweights_[key] = new ConcreteFlyweight();
	}
	return flyweights_[key];
}

int FlyweightFactory::GetInstanceCount() const
{
	return flyweights_.size();
}
