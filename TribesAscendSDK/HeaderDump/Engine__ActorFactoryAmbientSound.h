#pragma once
#include "Engine__ActorFactory.h"
#include "Engine__SoundCue.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ActorFactoryAmbientSound." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ActorFactoryAmbientSound : public ActorFactory
	{
	public:
		ADD_OBJECT(SoundCue, AmbientSoundCue)
	};
}
#undef ADD_OBJECT
