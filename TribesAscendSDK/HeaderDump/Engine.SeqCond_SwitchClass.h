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
		class SwitchClassInfo
		{
		public:
			ADD_STRUCT(byte, bFallThru, 8)
			ADD_STRUCT(ScriptName, ClassName, 0)
		};
		ADD_STRUCT(ScriptArray<SeqCond_SwitchClass::SwitchClassInfo>, ClassArray, 208)
		void VerifyDefaultCaseValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqCond_SwitchClass.VerifyDefaultCaseValue");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsFallThruEnabled(int ValueIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqCond_SwitchClass.IsFallThruEnabled");
			byte params[8] = { NULL };
			*(int*)&params[0] = ValueIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void InsertValueEntry(int InsertIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqCond_SwitchClass.InsertValueEntry");
			byte params[4] = { NULL };
			*(int*)&params[0] = InsertIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveValueEntry(int RemoveIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqCond_SwitchClass.RemoveValueEntry");
			byte params[4] = { NULL };
			*(int*)&params[0] = RemoveIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
