#pragma once
class Fact
{
private:
	char* fact;
public:
	Fact(char* fact);
	~Fact();
	void SetFactData(char*);
	char* GetFactData();
};

