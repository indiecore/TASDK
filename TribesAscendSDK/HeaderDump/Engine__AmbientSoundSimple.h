#pragma once
#include "Engine__AmbientSound.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AmbientSoundSimple." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AmbientSoundSimple : public AmbientSound
	{
	public:
		ADD_OBJECT(SoundNodeAmbient, SoundNodeInstance)
		ADD_OBJECT(SoundCue, SoundCueInstance)
		ADD_OBJECT(SoundNodeAmbient, AmbientProperties)
	};
}
#undef ADD_OBJECT
