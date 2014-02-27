#pragma once
#include <memory>
class RoleStateMemento
{
	friend class GameRole;	
public:
	~RoleStateMemento();

private:
	RoleStateMemento(int health, int attack, int defence);
	int health_;
	int attack_;
	int defence_;
};

