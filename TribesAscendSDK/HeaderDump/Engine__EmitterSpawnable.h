#pragma once
#include "Engine__Emitter.h"
#include "Engine__ParticleSystem.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.EmitterSpawnable." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class EmitterSpawnable : public Emitter
	{
	public:
		ADD_OBJECT(ParticleSystem, ParticleTemplate)
		// Here lies the not-yet-implemented method 'SetTemplate'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
	};
}
#undef ADD_OBJECT
