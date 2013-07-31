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
	class SkelControlTrail : public SkelControlBase
	{
	public:
		ADD_STRUCT(ScriptArray<Vector>, TrailBoneLocations, 224)
		ADD_STRUCT(Object::Matrix, OldLocalToWorld, 240)
		ADD_STRUCT(float, ThisTimstep, 220)
		ADD_STRUCT(Vector, FakeVelocity, 208)
		ADD_STRUCT(float, StretchLimit, 204)
		ADD_STRUCT(float, TrailRelaxation, 200)
		ADD_BOOL(bHadValidStrength, 196, 0x8)
		ADD_BOOL(bActorSpaceFakeVel, 196, 0x4)
		ADD_BOOL(bLimitStretch, 196, 0x2)
		ADD_BOOL(bInvertChainBoneAxis, 196, 0x1)
		ADD_STRUCT(Object::EAxis, ChainBoneAxis, 192)
		ADD_STRUCT(int, ChainLength, 188)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
