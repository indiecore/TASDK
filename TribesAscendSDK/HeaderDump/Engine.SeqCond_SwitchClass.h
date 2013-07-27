#pragma once
#include "Engine.SeqCond_SwitchBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqCond_SwitchClass : public SeqCond_SwitchBase
	{
	public:
		struct SwitchClassInfo
		{
		public:
			ADD_STRUCT(byte, bFallThru, 8)
			ADD_STRUCT(ScriptName, ClassName, 0)
		};
		ADD_STRUCT(ScriptArray<SeqCond_SwitchClass::SwitchClassInfo>, ClassArray, 208)
		void VerifyDefaultCaseValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26052);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsFallThruEnabled(int ValueIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26053);
			byte params[8] = { NULL };
			*(int*)params = ValueIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void InsertValueEntry(int InsertIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26056);
			byte params[4] = { NULL };
			*(int*)params = InsertIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveValueEntry(int RemoveIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26058);
			byte params[4] = { NULL };
			*(int*)params = RemoveIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
