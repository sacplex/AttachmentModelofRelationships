#pragma once
#include "NPCState.h"

class NoKnowledgeState : public NPCState
{
public:
	NoKnowledgeState() {}
	~NoKnowledgeState() {}

	void KnowPlayer() {}
	void TrustPlayer() {}
	void RelyPlayer() {}
	void CommitPlayer() {}
};

