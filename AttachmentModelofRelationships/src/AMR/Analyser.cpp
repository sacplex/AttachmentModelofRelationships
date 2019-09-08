#include "Analyser.h"

namespace AMR {

	Analyser::Analyser(AMR::Ref<AMR::Player> player)
	{
		Analyser::player = player;
	}

	Analyser::~Analyser()
	{
	}

	void Analyser::Run()
	{
		/*if (player->GetKnowledge()->GetFactsThreshold() == player->GetKnowledge()->GetFactsThreshold())
			std::cout << "NPC has reached knowledge threshold" << std::endl;
		else
			std::cout << "NPC has not reached knowledge threshold" << std::endl;*/
	}
}
