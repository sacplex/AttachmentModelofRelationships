#include "Player.h"

namespace AMR {

	Player::Player()
	{
		greeting = new Greeting();

		knowledge = std::make_shared<Knowledge>();
	}

	Player::~Player()
	{
		delete greeting;
	}

	void Player::Init(std::string gameName)
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

	void Player::SetName(String playerName)
	{
		if (knowledge == nullptr)
			std::cout << "Knowledge is null" << std::endl;
		knowledge->SetFact("name", playerName);
		knowledge->GetFact("name")->setFactQuestion("What is your name?");
	}

	void Player::SetName(Ref<Fact> playerName)
	{
		knowledge->SetFact(playerName);
	}

	Ref<Fact> Player::GetName()
	{
		return knowledge->GetFact("name");
	}

	void Player::SetAge(String playerAge)
	{
		knowledge->SetFact("age", playerAge);
	}

	void Player::SetAge(Ref<Fact> playerAge)
	{
		knowledge->SetFact(playerAge);
	}

	Ref<Fact> Player::GetAge()
	{
		return age;
	}

	void Player::SetGender(String playerGender)
	{
		knowledge->SetFact("gender", playerGender);
	}

	void Player::SetGender(Ref<Fact> playerGender)
	{
		knowledge->SetFact(playerGender);
	}

	Ref<Fact> Player::GetGender()
	{
		return name;
	}

	void Player::SetRace(std::string playerRace)
	{
		knowledge->SetFact("gender", playerRace);
	}

	void Player::SetRace(Ref<Fact> playerRace)
	{
		knowledge->SetFact(playerRace);
	}

	Ref<Fact> Player::GetRace()
	{
		return race;
	}

	Ref<Knowledge> Player::GetKnowledge()
	{
		return knowledge;
	}

	void Player::SetGameName(std::string gameName)
	{
		Player::gameName = gameName;
	}

	std::string Player::GetGameName()
	{
		return Player::gameName;
	}

	Greeting* Player::GetGreeting()
	{
		return Player::greeting;
	}

}