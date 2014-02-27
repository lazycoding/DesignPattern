#pragma once
template<class T>
class IEnumerator
{
public:
	virtual bool MoveNext() = 0;
	virtual T* Current() = 0;
	virtual void Reset() = 0;
};