#include "Player.h"

Player::Player()
{
	greeting = new Greeting();
	fileIO = new FileIO();
}

Player::~Player()
{
	delete greeting;
	delete fileIO;
}

void Player::Init(std::string gameName)
{
	if (fileIO->CheckForExistingPlayerFile(gameName.c_str()))
	{
		printf("%s%s", gameName.c_str(), " file found\n\n");
		printf("%s", "No need to create game file.\n\n");		
	}
	else
	{
		printf("%s%s", gameName.c_str(), " file not found\n\n");
		printf("%s", "Creating game file.\n\n");

		fileIO->WriteANewPlayerFile(gameName.c_str());
		fileIO->WriteHeaderDataToPlayerFile(Player::PLAYER_HEADER);
		fileIO->WriteDataToPlayerFile(gameName.c_str());
	}

	fflush(stdout);
}

void Player::SetName(std::string playerName)
{
	name = playerName;
}

std::string Player::GetName()
{
	return name;
}

void Player::SetGameName(std::string gameName)
{
	Player::gameName = gameName;
}

std::string Player::GetGameName()
{
	return Player::gameName;
}

Greeting* Player::GetGreeting()
{
	return Player::greeting;
}