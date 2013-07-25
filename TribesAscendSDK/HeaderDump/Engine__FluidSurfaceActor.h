#pragma once
#include "Engine__Actor.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.FluidSurfaceActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FluidSurfaceActor : public Actor
	{
	public:
		ADD_OBJECT(ParticleSystem, ProjectileEntryEffect)
	};
}
#undef ADD_OBJECT
