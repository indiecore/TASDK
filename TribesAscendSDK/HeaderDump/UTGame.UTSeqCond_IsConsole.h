#pragma once
#include "Engine.SequenceCondition.h"
namespace UnrealScript
{
	class UTSeqCond_IsConsole : public SequenceCondition
	{
	public:
		void Activated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49197);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
