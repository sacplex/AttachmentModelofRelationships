#include "NPCPlayerRelationShip.h"

#include "NoKnowledgeState.h"
#include "HasKnowledgeState.h"
#include "TrustedState.h"
#include "ReliableState.h"
#include "CommitmentState.h"

namespace AMR {

	NPCPlayerRelationShip::NPCPlayerRelationShip()
	{
		m_NoKnowledgeState = new NoKnowledgeState();
		m_HasKnowledgeState = new HasKnowledgeState();
		m_TrustedState = new TrustedState();
		m_ReliableState = new ReliableState();
		m_CommitmentState = new CommitmentState();

		m_StateOfNPC = m_NoKnowledgeState;
	}

	NPCPlayerRelationShip::~NPCPlayerRelationShip()
	{
		delete m_NoKnowledgeState;
		delete m_HasKnowledgeState;
		delete m_TrustedState;
		delete m_ReliableState;
		delete m_CommitmentState;

		delete m_StateOfNPC;
	}

	void NPCPlayerRelationShip::KnowledgeExist()
	{
		m_StateOfNPC->KnowPlayer();
	}

	void NPCPlayerRelationShip::AccurateMentalRepresentation()
	{
		m_StateOfNPC->TrustPlayer();
	}

	void NPCPlayerRelationShip::PerformsTask()
	{
		m_StateOfNPC->RelyPlayer();
	}

	void NPCPlayerRelationShip::PerformsSelflessTask()
	{
		m_StateOfNPC->CommitPlayer();
	}

	NPCState * NPCPlayerRelationShip::GetNoKnowledgeState()
	{
		return m_NoKnowledgeState;
	}

	NPCState * NPCPlayerRelationShip::GetHasKnowledgeState()
	{
		return m_HasKnowledgeState;
	}

	NPCState * NPCPlayerRelationShip::GetTrustedState()
	{
		return m_TrustedState;
	}

	NPCState * NPCPlayerRelationShip::GetReiableState()
	{
		return m_ReliableState;
	}

	NPCState * NPCPlayerRelationShip::GetCommitmentState()
	{
		return m_CommitmentState;
	}

	void NPCPlayerRelationShip::SetStateOfNPC(NPCState * npcState)
	{
		m_StateOfNPC = npcState;
	}

}