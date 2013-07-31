#pragma once
#include "Engine.AmbientSound.h"
#include "Engine.SoundNodeAmbient.h"
#include "Engine.SoundCue.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class AmbientSoundSimple : public AmbientSound
	{
	public:
		ADD_OBJECT(SoundNodeAmbient, SoundNodeInstance, 496)
		ADD_OBJECT(SoundCue, SoundCueInstance, 492)
		ADD_OBJECT(SoundNodeAmbient, AmbientProperties, 488)
	};
}
#undef ADD_OBJECT
