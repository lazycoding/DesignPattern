#pragma once
#include "Adaptee.h"
class Adapter
{
public:

	Adapter()
	{
	}

	~Adapter()
	{
	}

	void Foo()
	{
		ada_.Fooo();
	}

	void Bar()
	{
		ada_.Barr();
	}

private:
	Adaptee ada_;
};

