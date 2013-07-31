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
	class UDKSkelControl_HugGround : public SkelControlSingleBone
	{
	public:
		ADD_STRUCT(float, LastUpdateTime, 268)
		ADD_STRUCT(float, MaxTranslationPerSec, 264)
		ADD_STRUCT(float, ZDistFromParentBone, 260)
		ADD_STRUCT(float, XYDistFromParentBone, 256)
		ADD_BOOL(bOppositeFromParent, 252, 0x1)
		ADD_STRUCT(ScriptName, ParentBone, 244)
		ADD_STRUCT(float, MaxDist, 240)
		ADD_STRUCT(float, DesiredGroundDist, 236)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
