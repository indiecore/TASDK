#pragma once
#include "Engine.AnimNodeBlendPerBone.h"
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
	class UDKAnimBlendByWeapon : public AnimNodeBlendPerBone
	{
	public:
		ADD_STRUCT(float, BlendTime, 312)
		ADD_STRUCT(ScriptName, LoopingAnim, 304)
		ADD_BOOL(bLooping, 300, 0x1)
		void AnimFire(ScriptName FireSequence, bool bAutoFire, float AnimRate, float SpecialBlendTime, ScriptName LoopSequence)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34556);
			byte params[28] = { NULL };
			*(ScriptName*)params = FireSequence;
			*(bool*)&params[8] = bAutoFire;
			*(float*)&params[12] = AnimRate;
			*(float*)&params[16] = SpecialBlendTime;
			*(ScriptName*)&params[20] = LoopSequence;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AnimStopFire(float SpecialBlendTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34563);
			byte params[4] = { NULL };
			*(float*)params = SpecialBlendTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
