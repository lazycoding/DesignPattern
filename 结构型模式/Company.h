#pragma once
#include <string>
class Company
{
public:

	Company(const std::string& name) :name_(name)
	{
	}

	virtual ~Company()
	{
	}

	virtual void AddPart(Company*) = 0;
	virtual void RemovePart(Company*) = 0;
	virtual void Display(int depth) = 0;

protected:
	std::string name_;
};

