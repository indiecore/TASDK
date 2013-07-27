#pragma once
#include "Engine.SkelControlBase.h"
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
	class UDKSkelControl_LockRotation : public SkelControlBase
	{
	public:
		ADD_STRUCT(ScriptName, RotationSpaceBoneName, 220)
		ADD_STRUCT(SkelControlBase::EBoneControlSpace, LockRotationSpace, 216)
		ADD_STRUCT(Rotator, MaxDelta, 204)
		ADD_STRUCT(Rotator, LockRotation, 192)
		ADD_BOOL(bLockRoll, 188, 0x4)
		ADD_BOOL(bLockYaw, 188, 0x2)
		ADD_BOOL(bLockPitch, 188, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
