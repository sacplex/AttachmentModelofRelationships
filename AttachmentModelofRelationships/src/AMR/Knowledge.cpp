#include "Knowledge.h"

namespace AMR {

	Knowledge::Knowledge()
	{

	}

	Knowledge::~Knowledge()
	{
		facts.clear();
	}

	void Knowledge::SetFact(Ref<Fact> fact)
	{
		String data = fact->GetFactData();
		Ref<Fact> theFact = std::make_shared<Fact>();
		theFact->SetFactData(fact->GetFactName(), fact->GetFactData());

		facts[fact->GetFactName()] = theFact;

		numberOfFacts++;
	}

	void Knowledge::SetFact(String factName, String factData)
	{
		Ref<Fact> theFact = std::make_shared<Fact>();
		theFact->SetFactData(factName, factData);
		facts[factName] = theFact;

		numberOfFacts++;
	}

	Ref<Fact> Knowledge::GetFact(String factType)
	{
		return facts[factType];
	}

	int Knowledge::GetNumberOfFacts()
	{
		return numberOfFacts;
	}

	const int Knowledge::GetFactsThreshold()
	{
		return FACTS_THRESHOILD;
	}
}