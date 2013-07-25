#pragma once
#include "Engine__InterpTrack.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackVisibility." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackVisibility : public InterpTrack
	{
	public:
		ADD_VAR(::BoolProperty, bFireEventsWhenJumpingForwards, 0x4)
		ADD_VAR(::BoolProperty, bFireEventsWhenBackwards, 0x2)
		ADD_VAR(::BoolProperty, bFireEventsWhenForwards, 0x1)
	};
}
#undef ADD_VAR
