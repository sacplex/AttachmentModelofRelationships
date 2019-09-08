#include "Player.h"

namespace AMR {

	Player::Player()
	{
		greeting = std::make_shared<Greeting>();

		knowledge = std::make_shared<Knowledge>();

		type = "";
		data = "";
	}

	Player::~Player()
	{
		
	}

	void Player::Init(String gameName)
	{
		FileIO fileIO;

		std::cout << "Game Name: " << gameName << std::endl;

		if (fileIO.CheckForExistingPlayerFile((gameName.append(".txt")).c_str()))
		{
			printf("%s%s", gameName.c_str(), " file found\n\n");
			printf("%s", "No need to create game file.\n\n");

			fileIO.ReadFile(gameName.c_str());
			std::vector<std::string> lines = fileIO.GetLines();

			AMR::StringUtil stringUtil;

			for (int i = 0; i < lines.size(); i++)
			{
				if (lines[i].rfind("NAME", 0) == 0)
					knowledge->SetFact("name", stringUtil.Split(lines[i], ":")[1]);

				if (lines[i].rfind("AGE", 0) == 0)
					knowledge->SetFact("age", stringUtil.Split(lines[i], ":")[1]);

				if (lines[i].rfind("GENDER", 0) == 0)
					knowledge->SetFact("gender", stringUtil.Split(lines[i], ":")[1]);

				if (lines[i].rfind("RACE", 0) == 0)
					knowledge->SetFact("race", stringUtil.Split(lines[i], ":")[1]);
			}

			/*std::cout << "State of Player" << std::endl;
			std::cout << "Name: " << name->GetFactData() << std::endl;
			std::cout << "Age: " << age->GetFactData() << std::endl;
			std::cout << "Gender: " << gender->GetFactData() << std::endl;
			std::cout << "Race: " << race->GetFactData() << std::endl;*/
		}
		else
		{
			printf("%s%s", (gameName.append(".txt")).c_str(), " file not found\n\n");
			printf("%s", "Creating game file.\n\n");

			fileIO.WriteANewPlayerFile(gameName.c_str());
			fileIO.WriteHeaderDataToPlayerFile(Player::PLAYER_HEADER, true);
			fileIO.WriteDataToPlayerFile(gameName.c_str());
			fileIO.WriteHeaderDataToPlayerFile(Player::PLAYER_KNOWLEDGE_HEADER);

			fileIO.WriteDataToPlayerFile(Player::PLAYER_KNOWLEDGE_NAME.append(gameName.append("\n")).c_str());
			fileIO.WriteDataToPlayerFile(Player::PLAYER_KNOWLEDGE_AGE.append("unknown\n").c_str());
			fileIO.WriteDataToPlayerFile(Player::PLAYER_KNOWLEDGE_GENDER.append("unknown\n").c_str());
			fileIO.WriteDataToPlayerFile(Player::PLAYER_KNOWLEDGE_RACE.append("unknown\n").c_str());

			fileIO.WriteHeaderDataToPlayerFile(Player::PLAYER_END_TRAILER);

			fileIO.WriteHeaderDataToPlayerFile(Player::PLAYER_TRUST_HEADER);
			fileIO.WriteHeaderDataToPlayerFile(Player::PLAYER_END_TRAILER);
			fileIO.WriteHeaderDataToPlayerFile(Player::PLAYER_RELIABLE_HEADER);
			fileIO.WriteHeaderDataToPlayerFile(Player::PLAYER_END_TRAILER);
			fileIO.WriteHeaderDataToPlayerFile(Player::PLAYER_COMMITMENT_HEADER);
			fileIO.WriteHeaderDataToPlayerFile(Player::PLAYER_END_TRAILER);
		}

		fflush(stdout);
	}

	void Player::SetEnquiry(String enquiry)
	{
		if (greeting == nullptr)
		{
			std::cout << "Greeting is null" << std::endl;
		}
		else
		{
			type = "Question";
			data = greeting->GetGreetingQuestion();
		}
	}

	void Player::SetName(String playerName)
	{
		if (knowledge == nullptr)
			std::cout << "Knowledge is null" << std::endl;
		knowledge->SetFact("name", playerName);
		knowledge->GetFact("name")->setFactQuestion("What is your name?");

		if(knowledge->GetNumberOfFacts() > knowledge->GetFactsThreshold())
			npcPlayerRelationship->KnowledgeExist();
	}

	void Player::SetName(Ref<Fact> playerName)
	{
		knowledge->SetFact(playerName);

		if (knowledge->GetNumberOfFacts() > knowledge->GetFactsThreshold())
			npcPlayerRelationship->KnowledgeExist();
	}

	Ref<Fact> Player::GetName()
	{
		return knowledge->GetFact("name");
	}

	void Player::SetAge(String playerAge)
	{
		knowledge->SetFact("age", playerAge);

		if (knowledge->GetNumberOfFacts() > knowledge->GetFactsThreshold())
			npcPlayerRelationship->KnowledgeExist();
	}

	void Player::SetAge(Ref<Fact> playerAge)
	{
		knowledge->SetFact(playerAge);

		if (knowledge->GetNumberOfFacts() > knowledge->GetFactsThreshold())
			npcPlayerRelationship->KnowledgeExist();
	}

	Ref<Fact> Player::GetAge()
	{
		return age;
	}

	void Player::SetGender(String playerGender)
	{
		knowledge->SetFact("gender", playerGender);

		if (knowledge->GetNumberOfFacts() > knowledge->GetFactsThreshold())
			npcPlayerRelationship->KnowledgeExist();
	}

	void Player::SetGender(Ref<Fact> playerGender)
	{
		knowledge->SetFact(playerGender);

		if (knowledge->GetNumberOfFacts() > knowledge->GetFactsThreshold())
			npcPlayerRelationship->KnowledgeExist();
	}

	Ref<Fact> Player::GetGender()
	{
		return name;
	}

	void Player::SetRace(String playerRace)
	{
		knowledge->SetFact("gender", playerRace);

		if (knowledge->GetNumberOfFacts() > knowledge->GetFactsThreshold())
			npcPlayerRelationship->KnowledgeExist();
	}

	void Player::SetRace(Ref<Fact> playerRace)
	{
		knowledge->SetFact(playerRace);

		if (knowledge->GetNumberOfFacts() > knowledge->GetFactsThreshold())
			npcPlayerRelationship->KnowledgeExist();
	}

	Ref<Fact> Player::GetRace()
	{
		return race;
	}

	Ref<Knowledge> Player::GetKnowledge()
	{
		return knowledge;
	}

	void Player::SetGameName(String gameName)
	{
		Player::gameName = gameName;
	}

	String Player::GetGameName()
	{
		return Player::gameName;
	}

	Ref<Greeting> Player::GetGreeting()
	{
		return greeting;
	}

	bool Player::Check()
	{
		if (type != "" && data != "")
			return true;
		else
			return false;
	}

	String Player::GetType()
	{
		return type;
	}

	String Player::GetData()
	{
		return data;
	}

	void Player::Clear()
	{
		type = "";
		data = "";
	}
}