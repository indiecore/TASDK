#pragma once
#include "Engine.SequenceCondition.h"
namespace UnrealScript
{
	class SeqCond_SwitchBase : public SequenceCondition
	{
	public:
		void VerifyDefaultCaseValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26039);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsFallThruEnabled(int ValueIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26040);
			byte params[8] = { NULL };
			*(int*)params = ValueIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void InsertValueEntry(int InsertIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26043);
			byte params[4] = { NULL };
			*(int*)params = InsertIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveValueEntry(int RemoveIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26045);
			byte params[4] = { NULL };
			*(int*)params = RemoveIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
