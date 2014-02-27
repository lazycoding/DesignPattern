#include "Aggregate.h"
#include "ConcreteEnumerator.h"
#include <memory>
using namespace std;
Aggregate::Aggregate()
{
}


Aggregate::~Aggregate()
{
}

std::shared_ptr<IEnumerator<Object>> Aggregate::GetEnumerator()
{
	return make_shared<ConcreteEnumerator>(this);
}