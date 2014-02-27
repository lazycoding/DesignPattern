#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include "Visitor.h"
namespace visitor
{
	class Element;
	class ObjectStructure
	{
	public:
		ObjectStructure()
		{
		}

		~ObjectStructure()
		{
		}

		void Add(const std::shared_ptr<Element>& e)
		{
			ele_.push_back(e);
		}

		void Remove(int index)
		{
			auto iter = ele_.begin();
			std::advance(iter, index);
			ele_.erase(iter);
		}

		void Accpet(Visitor* vis)
		{
			for_each(ele_.begin(), ele_.end(), 
				[&](std::shared_ptr<Element>& element){
				element->Accept(vis);
			});
		}

	private:
		std::vector<std::shared_ptr<Element>> ele_;
	};

}