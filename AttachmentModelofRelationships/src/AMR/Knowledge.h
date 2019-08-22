#pragma once
#include "Core/Core.h"
#include "Fact.h"

namespace AMR {

	class Knowledge
	{
	private:
		Map<String, Ref<Fact>> facts;
		const int FACTS_THRESHOILD = 4;
		int numberOfFacts;
	public:
		Knowledge();
		~Knowledge();
		void SetFact(Ref<Fact> fact);
		void SetFact(String factType, String factData);
		Ref<Fact> GetFact(String factType);
		int GetNumberOfFacts();
		const int GetFactsThreshold();
	};

}