#pragma once

namespace AMR {

	class NPCState
	{
	public:
		NPCState() {}
		virtual ~NPCState() {}

		virtual void KnowPlayer() {}
		virtual void TrustPlayer() {}
		virtual void RelyPlayer() {}
		virtual void CommitPlayer() {}
	};

}