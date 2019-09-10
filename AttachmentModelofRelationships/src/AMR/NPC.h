#pragma once
#include <unordered_map>
#include <vector>
#include <iterator>

#include "Core/Core.h"
#include "Player.h"
#include "FileIO.h"

namespace AMR {

	class NPC
	{
	private:
		Map<String, Ref<Player>> players;
		Ref<Player> currentPlayer;

		String name;
		String age;
		String study;
		String version;

		String type;
		String data;
	public:
		NPC();
		~NPC();
		void LoadProfile();
		void PrintName();
		void Act();
		void InsertPlayer(String);
		void FindPlayer(String);
		void CreateOrLoadGameFile(String, String);
		const char* GetName();
		const char* GetNameQuestion();
		const char* GetAge();
		const char* GetStudy();
		const char* GetVersion();
		const char* GetGreeting(String);
		const char* GetGreetQuestion(String);
		bool CheckForNPCResponse();
		void SetNPCResponseType(String);
		void SetNPCResponseData(String);
		const char* GetNPCResponseType();
		const char* GetNPCResponseData();
		bool Check();
		String GetType();
		String GetData();
		void Clear();
		void ClearNPCResponse();
		void ClearPlayers();		
	};

}