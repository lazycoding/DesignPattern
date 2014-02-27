#pragma once
#include "IEumnerable.h"
#include "Object.h"
#include <vector>
class Aggregate : public IEnumerable<Object>
{
public:
	Aggregate();
	~Aggregate();
	int Count() const
	{
		return vec_.size();
	}
	Object* Get(int index)
	{
		return &(vec_[index]);
	}

	std::shared_ptr<IEnumerator<Object>> GetEnumerator() override;

private:
	std::vector<Object> vec_;
};

