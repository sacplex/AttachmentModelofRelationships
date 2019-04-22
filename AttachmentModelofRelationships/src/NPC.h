#pragma once
#include <unordered_map>
#include "Player.h"

class NPC
{
public:
	NPC();
	~NPC();
	void PrintName();
	void InsertPlayer(std::string);
	void FindPlayer(std::string);
	void ClearPlayers();
private:
	const char* name;
	std::unordered_map<std::string, Player*> players;
};

