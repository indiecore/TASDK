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
	class InterpTrackToggle : public InterpTrack
	{
	public:
		enum ETrackToggleAction : byte
		{
			ETTA_Off = 0,
			ETTA_On = 1,
			ETTA_Toggle = 2,
			ETTA_Trigger = 3,
			ETTA_MAX = 4,
		};
		struct ToggleTrackKey
		{
		public:
			ADD_STRUCT(InterpTrackToggle::ETrackToggleAction, ToggleAction, 4)
			ADD_STRUCT(float, Time, 0)
		};
		ADD_STRUCT(ScriptArray<InterpTrackToggle::ToggleTrackKey>, ToggleTrack, 128)
		ADD_BOOL(bFireEventsWhenJumpingForwards, 140, 0x10)
		ADD_BOOL(bFireEventsWhenBackwards, 140, 0x8)
		ADD_BOOL(bFireEventsWhenForwards, 140, 0x4)
		ADD_BOOL(bActivateWithJustAttachedFlag, 140, 0x2)
		ADD_BOOL(bActivateSystemEachUpdate, 140, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
