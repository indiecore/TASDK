#pragma once
#include "Engine.AnimNodeAimOffset.h"
#include "Core.Object.h"
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
	class UDKAnimNodeJumpLeanOffset : public AnimNodeAimOffset
	{
	public:
		ADD_STRUCT(float, BlendTimeToGo, 356)
		ADD_STRUCT(float, LeanWeightTarget, 352)
		ADD_STRUCT(float, LeanWeight, 348)
		ADD_STRUCT(Object::Vector2D, PreBlendAim, 340)
		ADD_STRUCT(ScriptName, OldAimProfileName, 332)
		ADD_OBJECT(AnimNodeAimOffset, CachedAimNode, 328)
		ADD_BOOL(bOldDoubleJumping, 324, 0x10)
		ADD_BOOL(bDoubleJumping, 324, 0x8)
		ADD_BOOL(bOldDodging, 324, 0x4)
		ADD_BOOL(bDodging, 324, 0x2)
		ADD_BOOL(bMultiplyByZVelocity, 324, 0x1)
		ADD_STRUCT(float, MaxLeanChangeSpeed, 320)
		ADD_STRUCT(float, JumpLeanStrength, 316)
		void SetLeanWeight(float WeightTarget, float BlendTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34603);
			byte params[8] = { NULL };
			*(float*)params = WeightTarget;
			*(float*)&params[4] = BlendTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
