#pragma once
#include "Engine.SkelControlSingleBone.h"
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
	class TrSkelControl_Suspension : public SkelControlSingleBone
	{
	public:
		ADD_STRUCT(int, WheelIndex, 284)
		ADD_STRUCT(float, CurrentRot, 280)
		ADD_STRUCT(float, MaxRotRate, 276)
		ADD_STRUCT(float, MinRot, 272)
		ADD_STRUCT(float, MaxRot, 268)
		ADD_STRUCT(float, RotScale, 264)
		ADD_STRUCT(float, RotIgnore, 260)
		ADD_STRUCT(float, MinTrans, 256)
		ADD_STRUCT(float, MaxTrans, 252)
		ADD_STRUCT(float, TransOffset, 248)
		ADD_STRUCT(float, TransScale, 244)
		ADD_STRUCT(float, TransIgnore, 240)
		ADD_BOOL(m_bApplyTranslation, 236, 0x2)
		ADD_BOOL(m_bApplyRotation, 236, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
