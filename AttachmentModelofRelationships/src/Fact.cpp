#include "Fact.h"
Fact::Fact(char* fact)
{
	Fact::fact = fact;
}


Fact::~Fact()
{
}

void Fact::SetFactData(char* factData)
{
	fact = factData;
}

char* Fact::GetFactData()
{
	return Fact::fact;
}
