#pragma once
#include "NPCState.h"

namespace AMR {

	class NPCPlayerRelationShip
	{
	public:
		NPCPlayerRelationShip();
		~NPCPlayerRelationShip();

		void KnowledgeExist();
		void AccurateMentalRepresentation();
		void PerformsTask();
		void PerformsSelflessTask();

		NPCState* GetNoKnowledgeState();
		NPCState* GetHasKnowledgeState();
		NPCState* GetTrustedState();
		NPCState* GetReiableState();
		NPCState* GetCommitmentState();

		void SetStateOfNPC(NPCState*);

	private:
		NPCState *m_StateOfNPC;
		NPCState *m_NoKnowledgeState;
		NPCState *m_HasKnowledgeState;
		NPCState *m_TrustedState;
		NPCState *m_ReliableState;
		NPCState *m_CommitmentState;
	};

}