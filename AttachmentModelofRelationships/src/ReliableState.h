#pragma once
#include "NPCState.h"

class ReliableState : public NPCState
{
public:
	ReliableState() {}
	~ReliableState() {}

	void KnowPlayer() {}
	void TrustPlayer() {}
	void RelyPlayer() {}
	void CommitPlayer() {}
};