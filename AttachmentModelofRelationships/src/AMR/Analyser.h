#pragma once

#include <iostream>

#include "Core/Core.h"

#include "Player.h"

namespace AMR {

	class Analyser
	{
	private:
		Ref<Player> player;
		
	public:
		Analyser(AMR::Ref<AMR::Player> player);
		~Analyser();
		void Run();
	};

}
