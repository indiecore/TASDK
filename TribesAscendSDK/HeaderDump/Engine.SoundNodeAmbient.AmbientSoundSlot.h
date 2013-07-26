#pragma once
#include "Engine.SoundNodeWave.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SoundNodeAmbient.AmbientSoundSlot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty SoundNodeAmbient.AmbientSoundSlot." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AmbientSoundSlot
	{
	public:
		ADD_VAR(::FloatProperty, Weight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VolumeScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PitchScale, 0xFFFFFFFF)
		ADD_OBJECT(SoundNodeWave, Wave)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
