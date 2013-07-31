#pragma once
#include "Engine.SequenceCondition.h"
namespace UnrealScript
{
	class SeqCond_IsBenchmarking : public SequenceCondition
	{
	public:
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26028);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
