#pragma once
#include "Engine.SequenceAction.h"
namespace UnrealScript
{
	class TrSeqAct_EndMatch : public SequenceAction
	{
	public:
		void Activated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeqAct_EndMatch.Activated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
