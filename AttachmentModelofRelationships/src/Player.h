#pragma once
#include <iostream>

#include "Greeting.h"
#include "FileIO.h"

class Player
{
private:
	std::string name;
	std::string gameName;
	const char* PLAYER_HEADER = "# PLAYER NAME";
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

