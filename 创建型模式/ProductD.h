#pragma once
#include "Prototype.h"
#include "Cloneable.h"
#include <string>
class ProductD : public Prototype, public Cloneable
{
public:
	ProductD();
	~ProductD();
	void Name(const std::string& name);
	std::string Name() const;
	Prototype* Clone() const override;

private:
	std::string* name_;
};

