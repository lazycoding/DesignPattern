#pragma once
#include <string>
class Request
{
public:
	Request();
	~Request();
	Request(int type, const std::string& desc)
		:type_(type), desc_(desc)
	{

	}
	int Type() const
	{
		return type_;
	}
	std::string Desc() const
	{
		return desc_;
	}

private:
	int type_;
	std::string desc_;
};

