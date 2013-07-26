#pragma once
#include "Engine.SoundCue.h"
#include "Engine.ParticleSystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Actor.PhysEffectInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Actor.PhysEffectInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PhysEffectInfo
	{
	public:
		ADD_OBJECT(SoundCue, Sound)
		ADD_OBJECT(ParticleSystem, Effect)
		ADD_VAR(::FloatProperty, ReFireDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Threshold, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
