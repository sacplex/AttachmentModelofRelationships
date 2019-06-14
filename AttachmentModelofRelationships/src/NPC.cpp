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

void NPC::CreateOrLoadGameFile(std::string gameName, std::string playerName)
{
	players[playerName]->Init(gameName);
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

const char* NPC::GetGreeting(std::string playerName)
{
	const char* greeting = players[playerName]->GetGreeting()->GetGreetingPhase();

	return greeting;
}

void NPC::ClearPlayers()
{
	players.clear();
}