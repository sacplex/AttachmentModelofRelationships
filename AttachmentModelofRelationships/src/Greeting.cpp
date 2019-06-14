#include "Greeting.h"

Greeting::Greeting()
{
	greetings.push_back("Hello");
	greetings.push_back("Hi");
}

Greeting::~Greeting()
{
}

const char* Greeting::GetGreetingPhase()
{
	return greetings[0];
}