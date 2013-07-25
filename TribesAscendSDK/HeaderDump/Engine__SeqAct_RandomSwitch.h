#pragma once
#include "Engine__SeqAct_Switch.h"
namespace UnrealScript
{
	class SeqAct_RandomSwitch : public SeqAct_Switch
	{
	public:
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_RandomSwitch.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
