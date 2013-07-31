#pragma once
#include "GameFramework.SeqEvent_MobileZoneBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_MobileInput : public SeqEvent_MobileZoneBase
	{
	public:
		ADD_STRUCT(float, CurrentY, 288)
		ADD_STRUCT(float, CurrentX, 284)
		ADD_STRUCT(float, CenterY, 280)
		ADD_STRUCT(float, CenterX, 276)
		ADD_STRUCT(float, YAxisValue, 272)
		ADD_STRUCT(float, XAxisValue, 268)
	};
}
#undef ADD_STRUCT
