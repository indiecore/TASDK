#pragma once
#include "Engine.InterpTrack.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackToggle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackToggle : public InterpTrack
	{
	public:
		ADD_VAR(::BoolProperty, bFireEventsWhenJumpingForwards, 0x10)
		ADD_VAR(::BoolProperty, bFireEventsWhenBackwards, 0x8)
		ADD_VAR(::BoolProperty, bFireEventsWhenForwards, 0x4)
		ADD_VAR(::BoolProperty, bActivateWithJustAttachedFlag, 0x2)
		ADD_VAR(::BoolProperty, bActivateSystemEachUpdate, 0x1)
	};
}
#undef ADD_VAR
