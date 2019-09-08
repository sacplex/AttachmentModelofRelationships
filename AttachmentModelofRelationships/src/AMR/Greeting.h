#pragma once
#include <iostream>
#include <vector>

#include "Core/Core.h"

namespace AMR {

	class Greeting
	{
	private:
		std::vector<const char*> greetings;
		std::vector<const char*> questions;

		String response;
	public:
		Greeting();
		~Greeting();
		const char* GetGreetingPhase();
		const char* GetGreetingQuestion();

		void SetResponse(String response);
		String GetResponse();
		bool DoesResponseExist();
	};

}