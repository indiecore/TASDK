#pragma once
#include "Engine.SkelControlSingleBone.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_HoverboardSwing : public SkelControlSingleBone
	{
	public:
		ADD_STRUCT(ScriptArray<float>, SwingHistory, 244)
		ADD_STRUCT(float, CurrentSwing, 268)
		ADD_STRUCT(float, MaxUseVel, 264)
		ADD_STRUCT(float, MaxSwing, 260)
		ADD_STRUCT(float, SwingScale, 256)
		ADD_STRUCT(int, SwingHistorySlot, 240)
		ADD_STRUCT(int, SwingHistoryWindow, 236)
	};
}
#undef ADD_STRUCT
