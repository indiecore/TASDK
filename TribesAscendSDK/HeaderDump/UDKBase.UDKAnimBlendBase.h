#pragma once
#include "Engine.AnimNodeBlendList.h"
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
namespace UnrealScript
{
	class UDKAnimBlendBase : public AnimNodeBlendList
	{
	public:
		ADD_STRUCT(ScriptArray<float>, ChildBlendTimes, 280)
		ADD_BOOL(bTickAnimInScript, 292, 0x1)
		ADD_STRUCT(float, BlendTime, 276)
		float GetBlendTime(int ChildIndex, bool bGetDefault)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34482);
			byte params[12] = { NULL };
			*(int*)params = ChildIndex;
			*(bool*)&params[4] = bGetDefault;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float GetAnimDuration(int ChildIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34486);
			byte params[8] = { NULL };
			*(int*)params = ChildIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void TickAnim(float DeltaSeconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34489);
			byte params[4] = { NULL };
			*(float*)params = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
