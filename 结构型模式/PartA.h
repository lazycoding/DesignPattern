#pragma once
#include "Company.h"
#include <iostream>
#include <string>
class PartA :
	public Company
{
public:
	PartA(const std::string& name);
	~PartA();

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

