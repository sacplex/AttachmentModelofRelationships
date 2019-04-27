#pragma once
#include "NPCState.h"

class HasKnowledgeState : public NPCState
{
public:
	HasKnowledgeState() {}
	~HasKnowledgeState() {}

	void KnowPlayer() {}
	void TrustPlayer() {}
	void RelyPlayer() {}
	void CommitPlayer() {}
};