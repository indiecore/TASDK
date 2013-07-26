#pragma once
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " InterpTrackInstHeadTracking.ActorToLookAt." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty InterpTrackInstHeadTracking.ActorToLookAt." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ActorToLookAt
	{
	public:
		ADD_VAR(::BoolProperty, CurrentlyBeingLookedAt, 0x1)
		ADD_VAR(::FloatProperty, StartTimeBeingLookedAt, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastKnownDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EnteredTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Rating, 0xFFFFFFFF)
		ADD_OBJECT(Actor, Actor)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
