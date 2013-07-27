#pragma once
#include "Engine.SkelControl_CCD_IK.h"
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
	class TrSkelControlFootPlacement_CCD : public SkelControl_CCD_IK
	{
	public:
		ADD_STRUCT(float, FootAdjustHeightLastTick, 320)
		ADD_STRUCT(float, OffContactFootAdjustInterpSpeed, 316)
		ADD_STRUCT(float, OnContactFootAdjustInterpSpeed, 312)
		ADD_STRUCT(Vector, FootUpDirLastTick, 300)
		ADD_STRUCT(float, FootOrientInterpSpeed, 296)
		ADD_STRUCT(float, MaxFootOrientAdjust, 292)
		ADD_STRUCT(float, MaxDownAdjustment, 288)
		ADD_STRUCT(float, MaxUpAdjustment, 284)
		ADD_BOOL(bFootOnGroundLastTick, 280, 0x8)
		ADD_BOOL(bOnlyEnableForUpAdjustment, 280, 0x4)
		ADD_BOOL(bOrientFootToGround, 280, 0x2)
		ADD_BOOL(bInvertFootUpAxis, 280, 0x1)
		ADD_STRUCT(Rotator, FootRotOffset, 268)
		ADD_STRUCT(Object::EAxis, FootUpAxis, 264)
		ADD_STRUCT(float, FootOffset, 260)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
