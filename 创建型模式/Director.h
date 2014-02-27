#pragma once
class Builder;
class Director
{
public:
	Director(Builder*);
	~Director();
	void Construct();
private:
	Builder* builder_;
};

