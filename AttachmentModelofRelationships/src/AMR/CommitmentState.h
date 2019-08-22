#pragma once
#include "NPCState.h"

namespace AMR {

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
}