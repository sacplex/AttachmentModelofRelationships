#include "Greeting.h"

namespace AMR {

	Greeting::Greeting()
	{
		greetings.push_back("Hello");
		greetings.push_back("Hi");

		questions.emplace_back("Is there something I can help you with?");

		response = "unknown";
	}

	Greeting::~Greeting()
	{
	}

	const char* Greeting::GetGreetingPhase()
	{
		return greetings[0];
	}

	const char* Greeting::GetGreetingQuestion()
	{
		return questions[0];
	}

	void Greeting::SetResponse(String _response)
	{
		response = _response;
	}

	String Greeting::GetResponse()
	{
		return response;
	}

	bool Greeting::DoesResponseExist()
	{
		if (response == "unknown")
			return false;
		else
			return true;
	}
}