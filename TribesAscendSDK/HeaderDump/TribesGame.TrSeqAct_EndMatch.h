#pragma once
#include "Engine.SequenceAction.h"
namespace UnrealScript
{
	class TrSeqAct_EndMatch : public SequenceAction
	{
	public:
		void Activated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110913);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
