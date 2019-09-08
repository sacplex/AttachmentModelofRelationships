#pragma once
#include <iostream>
#include <vector>

#include "Core/Core.h"
#include "Fact.h"
#include "FileIO.h"
#include "Greeting.h"
#include "Knowledge.h"
#include "NPCPlayerRelationShip.h"
#include "Util/StringUtil.h"

namespace AMR {

	class Player
	{
	private:
		const char* PLAYER_HEADER = "# PLAYER NAME";

		const char* PLAYER_KNOWLEDGE_HEADER = "# KNOWLEDGE";
		const char* PLAYER_TRUST_HEADER = "# TRUST";
		const char* PLAYER_RELIABLE_HEADER = "# RELIABLE";
		const char* PLAYER_COMMITMENT_HEADER = "# COMMITMENT";

		const char* PLAYER_END_TRAILER = "# END";

		std::string PLAYER_KNOWLEDGE_NAME = "NAME:";
		std::string PLAYER_KNOWLEDGE_AGE = "AGE:";
		std::string PLAYER_KNOWLEDGE_GENDER = "GENDER:";
		std::string PLAYER_KNOWLEDGE_RACE = "RACE:";

		Ref<NPCPlayerRelationShip> npcPlayerRelationship;

		Ref<Greeting> greeting;
		Ref<Knowledge> knowledge;

		Ref<Fact> name;
		Ref<Fact> age;
		Ref<Fact> gender;
		Ref<Fact> race;

		String gameName;
		String type;
		String data;
		
		FileIO *fileIO;
	public:
		Player();
		~Player();
		void Init(String);
		void SetName(String);
		void SetName(Ref<Fact> playerName);
		void SetAge(String);
		void SetAge(Ref<Fact> playerAge);
		void SetGender(String);
		void SetGender(Ref<Fact> playergender);
		void SetRace(String);
		void SetRace(Ref<Fact> playerRace);
		Ref<Fact> GetName();
		Ref<Fact> GetAge();
		Ref<Fact> GetGender();
		Ref<Fact> GetRace();
		void SetEnquiry(String enquiry);
		Ref<Knowledge> GetKnowledge();
		void SetGameName(String);

		String GetGameName();
		Ref<Greeting> GetGreeting();

		bool Check();
		String GetType();
		String GetData();
		void Clear();
	};

}