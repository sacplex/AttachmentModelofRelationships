#pragma once
#include "Core/Core.h"
#include "NPCState.h"

namespace AMR {

	class NPCPlayerRelationShip
	{
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