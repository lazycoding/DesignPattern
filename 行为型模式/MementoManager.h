#pragma once
#include "RoleStateMemento.h"
class MementoManager
{
public:
	MementoManager();
	~MementoManager();
	void SetRoleStateMemento(std::shared_ptr<RoleStateMemento>&);
	std::shared_ptr<RoleStateMemento> GetRoleStateMemento() const;
private:
	std::shared_ptr<RoleStateMemento> memento_;
};

