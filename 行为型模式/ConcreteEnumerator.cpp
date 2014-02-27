#include "ConcreteEnumerator.h"
#include "Aggregate.h"

ConcreteEnumerator::ConcreteEnumerator(Aggregate* agg) :agg_(agg), current_(0)
{
}


ConcreteEnumerator::~ConcreteEnumerator()
{
}
bool ConcreteEnumerator::MoveNext()
{
	if (current_ < agg_->Count())
	{
		return true;
	}
	return false;
}
Object* ConcreteEnumerator::Current()
{
	return agg_->Get(current_);
}

void ConcreteEnumerator::Reset()
{
	current_ = 0;
}