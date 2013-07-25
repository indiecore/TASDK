#pragma once
#include "Engine.SequenceEvent.h"
namespace UnrealScript
{
	class TrSeqEvent_StormShield : public SequenceEvent
	{
	public:
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeqEvent_StormShield.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
