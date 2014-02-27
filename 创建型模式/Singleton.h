#pragma once
#include <memory>
template<class T>
class Singleton
{
public:	
	virtual ~Singleton(){
		instance = nullptr; 
	}

	template<typename... Args>
	static T* Instance(Args... args)
	{
		if (!Singleton::instance)
		{
			instance = new T(args...);
		}
		return instance;
	}

	void Release()
	{
		delete instance;
	}
protected:
	Singleton() = default;
	
private:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) =delete;	
	static T* instance;
};

template<class T>
T* Singleton<T>::instance = nullptr;


#define SINGLETON(_Ty) class _Ty : public Singleton<_Ty> \
{														 \
	friend class Singleton<_Ty>;						 \

#define SINGLETON_END	};

#define SINGLETON_DEF(_Ty) SINGLETON(_Ty)

SINGLETON_DEF(SingletonTest)
public:
	SingletonTest() :count_(0){}
	~SingletonTest()
	{
		count_ = 0;
	}
	void Foo(){ ++count_; }
private:
	int count_;
SINGLETON_END