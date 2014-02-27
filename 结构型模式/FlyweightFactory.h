#pragma once
#include <string>
#include <map>
class Flyweight;
class FlyweightFactory
{
public:
	FlyweightFactory();
	~FlyweightFactory();
	Flyweight* GetFlyweight(const std::string&);
	int GetInstanceCount() const;
private:
	std::map<std::string, Flyweight*> flyweights_;
};

