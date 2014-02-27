#pragma once
#include <iostream>
using namespace std;
class Observer
{
public:
	Observer()
	{
	}

	virtual ~Observer()
	{
	}

	virtual void Update() = 0;
};


class ObserverA : public Observer
{
public:
	void Update()
	{
		cout << "ObserverA.update" << endl;
	}
};


class ObserverB : public Observer
{
public:
	void Update()
	{
		cout << "ObserverB.update" << endl;
	}
};