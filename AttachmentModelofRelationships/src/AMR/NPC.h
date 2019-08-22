#pragma once
#include <unordered_map>
#include <vector>
#include <iterator>
#include "Player.h"
#include "FileIO.h"

namespace AMR {

	class NPC
	{
	public:
		NPC();
		~NPC();
		void LoadProfile();
		void PrintName();
		void InsertPlayer(std::string);
		void FindPlayer(std::string);
		void CreateOrLoadGameFile(std::string, std::string);
		const char* GetName();
		const char* GetAge();
		const char* GetStudy();
		const char* GetVersion();
		const char* GetGreeting(std::string);
		void ClearPlayers();
	private:
		std::unordered_map<std::string, Player*> players;

		std::string name;
		std::string age;
		std::string study;
		std::string version;
	};

}