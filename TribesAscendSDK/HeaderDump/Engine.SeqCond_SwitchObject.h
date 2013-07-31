#pragma once
#include "Engine.SeqCond_SwitchBase.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SeqCond_SwitchObject : public SeqCond_SwitchBase
	{
	public:
		struct SwitchObjectCase
		{
		public:
			ADD_BOOL(bDefaultValue, 4, 0x2)
			ADD_BOOL(bFallThru, 4, 0x1)
			ADD_OBJECT(Object, ObjectValue, 0)
		};
		ADD_STRUCT(ScriptArray<SeqCond_SwitchObject::SwitchObjectCase>, SupportedValues, 208)
		void VerifyDefaultCaseValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26066);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsFallThruEnabled(int ValueIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26068);
			byte params[8] = { NULL };
			*(int*)params = ValueIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void InsertValueEntry(int InsertIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26071);
			byte params[4] = { NULL };
			*(int*)params = InsertIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveValueEntry(int RemoveIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26073);
			byte params[4] = { NULL };
			*(int*)params = RemoveIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
