#pragma once
#include "Engine.ParticleSystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKVehicle.VehicleEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKVehicle.VehicleEffect." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class VehicleEffect
	{
	public:
		ADD_VAR(::NameProperty, EffectSocket, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, EffectTemplate_Blue)
		ADD_OBJECT(ParticleSystem, EffectTemplate)
		ADD_VAR(::BoolProperty, bHighDetailOnly, 0x2)
		ADD_VAR(::BoolProperty, bRestartRunning, 0x1)
		ADD_VAR(::NameProperty, EffectEndTag, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, EffectStartTag, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
