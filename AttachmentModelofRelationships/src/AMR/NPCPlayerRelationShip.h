#pragma once
#include "Core/Core.h"
#include "NPCState.h"

namespace AMR {

	class NPCPlayerRelationShip
	{
	public:
		const int GREETING = 0;
		const int KNOWLEDGE = 1;
		const int TRUST = 2;
		const int RELIABLE = 3;
		const int COMMITMENT = 4;
		enum State { greeting, knowledge, trust, reliable, commitment };
		int state = GREETING;
	private:		

		Ref<NPCState> m_StateOfNPC;
		Ref<NPCState> m_GreetState;
		Ref<NPCState> m_HasKnowledgeState;
		Ref<NPCState> m_TrustedState;
		Ref<NPCState> m_ReliableState;
		Ref<NPCState> m_CommitmentState;
	public:
		NPCPlayerRelationShip();
		~NPCPlayerRelationShip();

		void KnowledgeExist();
		void AccurateMentalRepresentation();
		void PerformsTask();
		void PerformsSelflessTask();

		Ref<NPCState> GetGreetState();
		Ref<NPCState> GetHasKnowledgeState();
		Ref<NPCState> GetTrustedState();
		Ref<NPCState> GetReiableState();
		Ref<NPCState> GetCommitmentState();

		void SetStateOfNPC(Ref<NPCState> state);
		Ref<NPCState> GetStateOfNPC();
	};

}