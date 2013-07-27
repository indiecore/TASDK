#pragma once
#include "Engine.SkelControlSingleBone.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_HoverboardSuspension : public SkelControlSingleBone
	{
	public:
		ADD_STRUCT(float, CurrentRot, 268)
		ADD_STRUCT(float, MaxRotRate, 264)
		ADD_STRUCT(float, MaxRot, 260)
		ADD_STRUCT(float, RotScale, 256)
		ADD_STRUCT(float, MinTrans, 252)
		ADD_STRUCT(float, MaxTrans, 248)
		ADD_STRUCT(float, TransOffset, 244)
		ADD_STRUCT(float, TransScale, 240)
		ADD_STRUCT(float, TransIgnore, 236)
	};
}
#undef ADD_STRUCT
