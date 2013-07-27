#pragma once
#include "Engine.InterpTrack.h"
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
	class InterpTrackVisibility : public InterpTrack
	{
	public:
		enum EVisibilityTrackCondition : byte
		{
			EVTC_Always = 0,
			EVTC_GoreEnabled = 1,
			EVTC_GoreDisabled = 2,
			EVTC_MAX = 3,
		};
		enum EVisibilityTrackAction : byte
		{
			EVTA_Hide = 0,
			EVTA_Show = 1,
			EVTA_Toggle = 2,
			EVTA_MAX = 3,
		};
		class VisibilityTrackKey
		{
		public:
			ADD_STRUCT(InterpTrackVisibility::EVisibilityTrackCondition, ActiveCondition, 5)
			ADD_STRUCT(InterpTrackVisibility::EVisibilityTrackAction, Action, 4)
			ADD_STRUCT(float, Time, 0)
		};
		ADD_STRUCT(ScriptArray<InterpTrackVisibility::VisibilityTrackKey>, VisibilityTrack, 128)
		ADD_BOOL(bFireEventsWhenJumpingForwards, 140, 0x4)
		ADD_BOOL(bFireEventsWhenBackwards, 140, 0x2)
		ADD_BOOL(bFireEventsWhenForwards, 140, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
