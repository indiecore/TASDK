#pragma once
#include "Engine.SequenceCondition.h"
namespace UnrealScript
{
	class UTSeqCond_DoTutorial : public SequenceCondition
	{
	public:
		void Activated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49173);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
