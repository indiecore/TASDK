#pragma once
#include "Engine.ParticleSystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrVehicle_BaseFlying.FlyingParticleEffects." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrVehicle_BaseFlying.FlyingParticleEffects." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FlyingParticleEffects
	{
	public:
		ADD_OBJECT(ParticleSystem, ParticleTemplate)
		ADD_VAR(::NameProperty, SocketToAttach, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsAttachedToBoost, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
