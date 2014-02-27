#pragma once
#include "Company.h"
#include <vector>
#include <iostream>
class CompanyA :
	public Company
{
public:
	CompanyA(const std::string& name);
	~CompanyA();

	void AddPart(Company* cp)
	{
		children_.push_back(cp);
	}
	void RemovePart(Company* cp)
	{
		auto postion = std::find(begin(children_), end(children_), cp);
		children_.erase(postion);
	}
	void Display(int depth)
	{
		std::string s(depth, '-');
		std::cout << s + name_ << std::endl;
		for each (auto child in children_)
		{
			child->Display(depth + 2);
		}
	}

private:
	std::vector<Company*> children_;
};

