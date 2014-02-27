#pragma once
#include "Company.h"
#include <string>
#include <iostream>
class PartB :
	public Company
{
public:
	PartB(const std::string& name);
	~PartB();

	void AddPart(Company* cp)
	{

	}
	void RemovePart(Company* cp)
	{

	}
	void Display(int depth)
	{
		std::string s(depth, '-');
		std::cout << s + name_ << std::endl;
	}
};

