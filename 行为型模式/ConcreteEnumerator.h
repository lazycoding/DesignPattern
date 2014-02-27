#pragma once
#include "IEnumerator.h"
#include "Object.h"
class Aggregate;
class ConcreteEnumerator :
	public IEnumerator<Object>
{
public:
	ConcreteEnumerator(Aggregate* agg);
	~ConcreteEnumerator();
	bool MoveNext();
	Object* Current();
	void Reset();

private:
	Aggregate* agg_;
	int current_;
};

