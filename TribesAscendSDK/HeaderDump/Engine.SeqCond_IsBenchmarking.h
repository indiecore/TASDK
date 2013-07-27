#pragma once
#include "Engine.SequenceCondition.h"
namespace UnrealScript
{
	class SeqCond_IsBenchmarking : public SequenceCondition
	{
	public:
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqCond_IsBenchmarking.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
