#pragma once
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKVehicleMovementEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKVehicleMovementEffect : public Actor
	{
	public:
		ADD_VAR(::FloatProperty, AirCurrentLevel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AirMaxDelta, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AirEffectScalar, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxVelocityForAirEffect, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinVelocityForAirEffect, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
