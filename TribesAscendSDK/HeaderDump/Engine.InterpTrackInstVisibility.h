#pragma once
#include "Engine.InterpTrackInst.h"
#include "Engine.InterpTrackVisibility.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class InterpTrackInstVisibility : public InterpTrackInst
	{
	public:
		ADD_STRUCT(float, LastUpdatePosition, 64)
		ADD_STRUCT(InterpTrackVisibility::EVisibilityTrackAction, Action, 60)
	};
}
#undef ADD_STRUCT
