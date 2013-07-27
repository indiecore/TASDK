#pragma once
#include "Engine.SequenceAction.h"
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
namespace UnrealScript
{
	class SeqAct_CameraLookAt : public SequenceAction
	{
	public:
		ADD_STRUCT(float, RemainingTime, 280)
		ADD_STRUCT(float, CameraFOV, 276)
		ADD_STRUCT(float, TotalTime, 272)
		ADD_STRUCT(ScriptString*, TextDisplay, 260)
		ADD_STRUCT(ScriptName, FocusBoneName, 252)
		ADD_STRUCT(Object::Vector2D, InFocusFOV, 244)
		ADD_STRUCT(Object::Vector2D, InterpSpeedRange, 236)
		ADD_BOOL(bCheckLineOfSight, 232, 0x800)
		ADD_BOOL(bUsedTimer, 232, 0x400)
		ADD_BOOL(bDisableInput, 232, 0x200)
		ADD_BOOL(bLeaveCameraRotation, 232, 0x100)
		ADD_BOOL(bToggleGodMode, 232, 0x80)
		ADD_BOOL(bRotatePlayerWithCamera, 232, 0x40)
		ADD_BOOL(bAffectHead, 232, 0x20)
		ADD_BOOL(bIgnoreTrace, 232, 0x10)
		ADD_BOOL(bTurnInPlace, 232, 0x8)
		ADD_BOOL(bAdjustCamera, 232, 0x4)
		ADD_BOOL(bAlwaysFocus, 232, 0x2)
		ADD_BOOL(bAffectCamera, 232, 0x1)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25633);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
