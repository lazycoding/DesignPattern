#pragma once
class Prototype;
class Cloneable
{
public:

	Cloneable()
	{
	}

	virtual ~Cloneable()
	{
	}

	virtual Prototype* Clone() const = 0;

private:
	Cloneable(const Cloneable&) = delete;
	Cloneable& operator=(const Cloneable&) =delete;
};

