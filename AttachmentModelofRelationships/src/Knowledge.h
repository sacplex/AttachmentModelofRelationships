#pragma once
#include "Fact.h"

class Knowledge
{
private:
	Fact *fact;
public:
	Knowledge();
	~Knowledge();
	void SetFact(char* factData);
	Fact * GetFact();
};
