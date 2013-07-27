#pragma once
#include "Engine.SkelControlLimb.h"
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
	class SkelControlFootPlacement : public SkelControlLimb
	{
	public:
		ADD_STRUCT(float, MaxFootOrientAdjust, 284)
		ADD_STRUCT(float, MaxDownAdjustment, 280)
		ADD_STRUCT(float, MaxUpAdjustment, 276)
		ADD_BOOL(bOnlyEnableForUpAdjustment, 272, 0x4)
		ADD_BOOL(bOrientFootToGround, 272, 0x2)
		ADD_BOOL(bInvertFootUpAxis, 272, 0x1)
		ADD_STRUCT(Object::Rotator, FootRotOffset, 260)
		ADD_STRUCT(Object::EAxis, FootUpAxis, 256)
		ADD_STRUCT(float, FootOffset, 252)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
