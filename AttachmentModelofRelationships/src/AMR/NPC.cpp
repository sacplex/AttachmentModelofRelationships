#include "NPC.h"

namespace AMR {

	NPC::NPC()
	{
		LoadProfile();
	}

	NPC::~NPC()
	{
		printf("%s%s", "Deleting NPC: ", name);
	}

	void NPC::LoadProfile()
	{
		FileIO fileIO;

		fileIO.ReadFile("NPC_Profile.txt");

		std::vector<std::string> lines = fileIO.GetLines();

		std::string delimiter = ":";
		name = lines[0];
		age = lines[1];
		study = lines[2];
		version = lines[3];
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

	const char* NPC::GetName()
	{
		return name.c_str();
	}

	const char* NPC::GetAge()
	{
		return age.c_str();
	}

	const char* NPC::GetStudy()
	{
		return study.c_str();
	}

	const char* NPC::GetVersion()
	{
		return version.c_str();
	}

	void NPC::ClearPlayers()
	{
		players.clear();
	}
}