#include "NPC.h"

NPC::NPC()
{
	name = "Owl";
}

NPC::~NPC()
{
	printf("%s%s", "Deleting NPC: ", name);
}

void NPC::PrintName()
{
	printf("%s%s%s", "NPC name: ", name, "\n\n");
}

void NPC::InsertPlayer(std::string playerName)
{
	Player *player = new Player();
	player->SetName(playerName);

	players.insert(std::make_pair(playerName, player));
}

void NPC::FindPlayer(std::string playerName)
{

	if (players.find(playerName) == players.end())
		printf("%s%s", playerName.c_str(), " not found\n\n");

	// If key found then iterator to that key is returned 
	else
		printf("%s%s", playerName.c_str(), " found\n\n");

	fflush(stdout);
}

void NPC::ClearPlayers()
{
	players.clear();
}