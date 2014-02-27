#pragma once
#include <memory>
template<class T> class IEnumerator;

template<class T>
class IEnumerable
{
public:
	typedef IEnumerator<T> _Enumerator;
	virtual std::shared_ptr<_Enumerator> GetEnumerator() = 0;
};