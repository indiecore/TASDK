#pragma once
#include "Engine__AmbientSoundSimple.h"
#include "Engine__SeqAct_Toggle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AmbientSoundSimpleToggleable." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AmbientSoundSimpleToggleable : public AmbientSoundSimple
	{
	public:
		ADD_VAR(::FloatProperty, FadeOutVolumeLevel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeOutDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeInVolumeLevel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeInDuration, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIgnoreAutoPlay, 0x4)
		ADD_VAR(::BoolProperty, bFadeOnToggle, 0x2)
		ADD_VAR(::BoolProperty, bCurrentlyPlaying, 0x1)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'StartPlaying'
		// Here lies the not-yet-implemented method 'StopPlaying'
		// Here lies the not-yet-implemented method 'OnToggle'
		// Here lies the not-yet-implemented method 'CreateCheckpointRecord'
		// Here lies the not-yet-implemented method 'ApplyCheckpointRecord'
	};
}
#undef ADD_VAR
