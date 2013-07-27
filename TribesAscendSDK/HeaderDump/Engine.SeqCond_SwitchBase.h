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
			byte params[8] = { NULL };
			*(int*)&params[0] = ValueIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void InsertValueEntry(int InsertIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqCond_SwitchBase.InsertValueEntry");
			byte params[4] = { NULL };
			*(int*)&params[0] = InsertIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveValueEntry(int RemoveIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqCond_SwitchBase.RemoveValueEntry");
			byte params[4] = { NULL };
			*(int*)&params[0] = RemoveIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
