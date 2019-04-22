#pragma once
#include <iostream>
class Player
{
public:
	Player();
	~Player();
	void SetName(std::string);
	std::string GetName();
private:
	std::string name;
};

