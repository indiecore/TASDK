#pragma once
#include "Engine.SequenceCondition.h"
namespace UnrealScript
{
	class SeqCond_SwitchBase : public SequenceCondition
	{
	public:
		void VerifyDefaultCaseValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqCond_SwitchBase.VerifyDefaultCaseValue");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsFallThruEnabled(int ValueIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqCond_SwitchBase.IsFallThruEnabled");
			byte* params = (byte*)malloc(8);
			*(int*)params = ValueIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void InsertValueEntry(int InsertIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqCond_SwitchBase.InsertValueEntry");
			byte* params = (byte*)malloc(4);
			*(int*)params = InsertIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveValueEntry(int RemoveIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqCond_SwitchBase.RemoveValueEntry");
			byte* params = (byte*)malloc(4);
			*(int*)params = RemoveIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
