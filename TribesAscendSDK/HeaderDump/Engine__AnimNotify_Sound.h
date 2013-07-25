#pragma once
#include "Engine__AnimNotify.h"
#include "Engine__SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNotify_Sound." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AnimNotify_Sound." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimNotify_Sound : public AnimNotify
	{
	public:
		ADD_VAR(::FloatProperty, PitchMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VolumeMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PercentToPlay, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BoneName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIgnoreIfActorHidden, 0x2)
		ADD_VAR(::BoolProperty, bFollowActor, 0x1)
		ADD_OBJECT(SoundCue, SoundCue)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
