#pragma once
#include "Engine.SequenceAction.h"
namespace UnrealScript
{
	class SeqAct_ToggleHUD : public SequenceAction
	{
	public:
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25992);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
