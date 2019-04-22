#include "Player.h"

Player::Player()
{
}


Player::~Player()
{
}

void Player::SetName(std::string playerName)
{
	name = playerName;
}

std::string Player::GetName()
{
	return name;
}