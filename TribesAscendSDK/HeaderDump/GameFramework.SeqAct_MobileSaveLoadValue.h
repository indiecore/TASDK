#pragma once
#include "Engine.SequenceAction.h"
namespace UnrealScript
{
	class SeqAct_MobileSaveLoadValue : public SequenceAction
	{
	public:
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqAct_MobileSaveLoadValue.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
