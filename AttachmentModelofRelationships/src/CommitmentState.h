#pragma once
#include "NPCState.h"

class CommitmentState : public NPCState
{
public:
	CommitmentState() {}
	~CommitmentState() {}

	void KnowPlayer() {}
	void TrustPlayer() {}
	void RelyPlayer() {}
	void CommitPlayer() {}
};