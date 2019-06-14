#pragma once
#include <iostream>

#include "Greeting.h"
#include "FileIO.h"

class Player
{
private:
	const char* PLAYER_HEADER = "# PLAYER NAME";

	const char* PLAYER_KNOWLEDGE_HEADER = "# KNOWLEDGE";
	const char* PLAYER_TRUST_HEADER = "# TRUST";
	const char* PLAYER_RELIABLE_HEADER = "# RELIABLE";
	const char* PLAYER_COMMITMENT_HEADER = "# COMMITMENT";

	std::string PLAYER_KNOWLEDGE_NAME = "NAME:";
	std::string PLAYER_KNOWLEDGE_AGE = "AGE:";
	std::string PLAYER_KNOWLEDGE_GENDER = "GENDER:";
	std::string PLAYER_KNOWLEDGE_RACE = "RACE:";

	std::string name;
	std::string gameName;
	Greeting *greeting;
	FileIO *fileIO;
public:
	Player();
	~Player();
	void Init(std::string);
	void SetName(std::string);
	std::string GetName();
	void SetGameName(std::string);
	std::string GetGameName();
	Greeting* GetGreeting();
};

