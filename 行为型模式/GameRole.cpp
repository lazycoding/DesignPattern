#include "GameRole.h"
#include "RoleStateMemento.h"
using namespace std;

GameRole::GameRole() :health_(100), attack_(100), defence_(100)
{
}


GameRole::~GameRole()
{
}

shared_ptr<RoleStateMemento> GameRole::SaveState()
{
	return shared_ptr<RoleStateMemento>(new RoleStateMemento(health_, attack_, defence_));
}

void GameRole::RecoveryState(const shared_ptr<RoleStateMemento>& state)
{
	health_ = state->health_;
	attack_ = state->attack_;
	defence_ = state->defence_;
}

void GameRole::Dead()
{
	health_ = 0;
	attack_ = 0;
	defence_ = 0;
}