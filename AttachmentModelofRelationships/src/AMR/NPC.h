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
	public:
		NPC();
		~NPC();
		void LoadProfile();
		void PrintName();
		void InsertPlayer(String);
		void FindPlayer(String);
		void CreateOrLoadGameFile(String, String);
		const char* GetName();
		const char* GetNameQuestion();
		const char* GetAge();
		const char* GetStudy();
		const char* GetVersion();
		const char* GetGreeting(String);
		void ClearPlayers();
	
	};

}