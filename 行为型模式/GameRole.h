#pragma once
#include <memory>
class RoleStateMemento;
class GameRole
{
public:
	GameRole();
	~GameRole();

	std::shared_ptr<RoleStateMemento> SaveState();
	void RecoveryState(const std::shared_ptr<RoleStateMemento>& state);

	void Dead();
private:
	int health_;
	int defence_;
	int attack_;
};

