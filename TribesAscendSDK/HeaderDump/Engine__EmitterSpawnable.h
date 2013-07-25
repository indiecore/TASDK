#pragma once
#include "Engine__Emitter.h"
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
	};
}
#undef ADD_OBJECT
