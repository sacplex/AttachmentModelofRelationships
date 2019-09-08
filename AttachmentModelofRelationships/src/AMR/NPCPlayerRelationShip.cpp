#include "NPCPlayerRelationShip.h"

#include "NoKnowledgeState.h"
#include "HasKnowledgeState.h"
#include "TrustedState.h"
#include "ReliableState.h"
#include "CommitmentState.h"

#include "NPC.h"

namespace AMR {

	NPCPlayerRelationShip::NPCPlayerRelationShip()
	{
		m_GreetState = std::make_shared<NPCState>();
		m_HasKnowledgeState = std::make_shared<NPCState>();
		m_TrustedState = std::make_shared<NPCState>();
		m_ReliableState = std::make_shared<NPCState>();
		m_CommitmentState = std::make_shared<NPCState>();

		m_StateOfNPC = m_GreetState;
	}

	NPCPlayerRelationShip::~NPCPlayerRelationShip()
	{
	}

	void NPCPlayerRelationShip::KnowledgeExist()
	{
		m_StateOfNPC = m_HasKnowledgeState;
	}

	void NPCPlayerRelationShip::AccurateMentalRepresentation()
	{
		m_StateOfNPC = m_TrustedState;
	}

	void NPCPlayerRelationShip::PerformsTask()
	{
		m_StateOfNPC = m_ReliableState;
	}

	void NPCPlayerRelationShip::PerformsSelflessTask()
	{
		m_StateOfNPC = m_CommitmentState;
	}

	Ref<NPCState> NPCPlayerRelationShip::GetGreetState()
	{
		return m_GreetState;
	}

	Ref<NPCState> NPCPlayerRelationShip::GetHasKnowledgeState()
	{
		return m_HasKnowledgeState;
	}

	Ref<NPCState> NPCPlayerRelationShip::GetTrustedState()
	{
		return m_TrustedState;
	}

	Ref<NPCState> NPCPlayerRelationShip::GetReiableState()
	{
		return m_ReliableState;
	}

	Ref<NPCState> NPCPlayerRelationShip::GetCommitmentState()
	{
		return m_CommitmentState;
	}

	void NPCPlayerRelationShip::SetStateOfNPC(Ref<NPCState> npcState)
	{
		m_StateOfNPC = npcState;
	}

	Ref<NPCState> NPCPlayerRelationShip::GetStateOfNPC()
	{
		return m_StateOfNPC;
	}
}