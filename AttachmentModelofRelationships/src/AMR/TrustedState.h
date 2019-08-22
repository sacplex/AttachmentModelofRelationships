#pragma once
#include "NPCState.h"

namespace AMR {

	class TrustedState : public NPCState
	{
	public:
		TrustedState() {}
		~TrustedState() {}

		void KnowPlayer() {}
		void TrustPlayer() {}
		void RelyPlayer() {}
		void CommitPlayer() {}
	};

}