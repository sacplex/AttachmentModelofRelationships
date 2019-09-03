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

		std::vector<String> lines = fileIO.GetLines();

		String delimiter = ":";
		name = lines[0];
		age = lines[1];
		study = lines[2];
		version = lines[3];
	}

	void NPC::PrintName()
	{
		std::cout << "NPC name: " << name << std::endl;
	}

	void NPC::InsertPlayer(String playerName)
	{
		Ref<Player> player = std::make_shared<Player>();
		player->SetName(playerName);
		players.insert(std::make_pair(playerName, player));
	}

	void NPC::CreateOrLoadGameFile(String gameName, String playerName)
	{
		players[playerName]->Init(gameName);
	}

	void NPC::FindPlayer(String playerName)
	{
		if (players.find(playerName) == players.end())
		{
			printf("%s%s", playerName.c_str(), " not found\n\n");
		}			
		// If key found then iterator to that key is returned 
		else
		{
			currentPlayer = players[playerName];
			printf("%s%s", playerName.c_str(), " found\n\n");
		}

		fflush(stdout);
	}

	const char* NPC::GetGreeting(String playerName)
	{
		const char* greeting = players[playerName]->GetGreeting()->GetGreetingPhase();

		return greeting;
	}

	const char* NPC::GetName()
	{
		return name.c_str();
	}

	const char* NPC::GetNameQuestion()
	{
		return currentPlayer->GetName()->GetFactQuestion().c_str();
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