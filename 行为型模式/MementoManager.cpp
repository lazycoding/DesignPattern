#include "MementoManager.h"


MementoManager::MementoManager()
{
}


MementoManager::~MementoManager()
{
}

void MementoManager::SetRoleStateMemento(std::shared_ptr<RoleStateMemento>& memento)
{
	memento_ = memento;
}
std::shared_ptr<RoleStateMemento> MementoManager::GetRoleStateMemento() const
{
	return memento_;
}