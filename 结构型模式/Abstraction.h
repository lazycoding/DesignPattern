#pragma once
#include <memory>
class Implementor;
class Abstraction
{
public:
	Abstraction();
	~Abstraction();
	void Foo();
	void Bar();
private:
	std::shared_ptr<Implementor> impl_;
};

