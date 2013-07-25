#pragma once
#include "Engine__SequenceAction.h"
namespace UnrealScript
{
	class SeqAct_MobileSaveLoadValue : public SequenceAction
	{
	public:
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqAct_MobileSaveLoadValue.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
