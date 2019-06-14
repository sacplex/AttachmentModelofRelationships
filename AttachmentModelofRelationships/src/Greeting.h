#pragma once
#include <iostream>
#include <vector>

class Greeting
{
private:
	std::vector<const char*> greetings;
public:
	Greeting();
	~Greeting();
	const char* GetGreetingPhase();
};

