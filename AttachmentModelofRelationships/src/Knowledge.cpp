#include "Knowledge.h"

Knowledge::Knowledge()
{

}

Knowledge::~Knowledge()
{
	delete fact;
}

void Knowledge::SetFact(char* factData)
{
	if (Knowledge::fact == nullptr)
		fact = new Fact(factData);
	else
		fact->SetFactData(factData);
}

Fact* Knowledge::GetFact()
{
	return fact;
}

