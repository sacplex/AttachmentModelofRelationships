#include "NPC.h"

namespace AMR {

	NPC::NPC()
	{
		type = "";
		data = "";

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

	void NPC::Act()
	{
		currentPlayer->Act();
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

	const char* NPC::GetGreetQuestion(String playerName)
	{
		const char* greetingQuestion = players[playerName]->GetGreeting()->GetGreetingQuestion();

		return greetingQuestion;
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

	void NPC::SetNPCResponseType(String _type)
	{
		type = _type;
	}

	void NPC::SetNPCResponseData(String _data)
	{
		data = _data;
	}

	bool NPC::CheckForNPCResponse()
	{
		if (type != "" && data != "")
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	const char* NPC::GetNPCResponseType()
	{
		return type.c_str();
	}

	const char* NPC::GetNPCResponseData()
	{
		return data.c_str();
	}

	void NPC::ClearNPCResponse()
	{
		type = "";
		data = "";
	}

	const char* NPC::GetVersion()
	{
		return version.c_str();
	}

	bool NPC::Check()
	{
		return currentPlayer->Check();
	}

	String NPC::GetType()
	{
		return currentPlayer->GetType();
	}

	String NPC::GetData()
	{
		return currentPlayer->GetData();
	}
	
	void NPC::Clear()
	{
		currentPlayer->Clear();
	}

	void NPC::ClearPlayers()
	{
		players.clear();
	}
}