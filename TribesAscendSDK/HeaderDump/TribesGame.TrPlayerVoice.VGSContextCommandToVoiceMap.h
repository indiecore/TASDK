#pragma once
#include "Engine.SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrPlayerVoice.VGSContextCommandToVoiceMap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrPlayerVoice.VGSContextCommandToVoiceMap." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class VGSContextCommandToVoiceMap
	{
	public:
		ADD_OBJECT(SoundCue, Sound)
		ADD_VAR(::BoolProperty, bIsEnemyLocation, 0x1)
		ADD_VAR(::ByteProperty, ContextLocation, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ContextActor, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
