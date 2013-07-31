#pragma once
#include "Engine.Actor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKVehicleMovementEffect : public Actor
	{
	public:
		ADD_STRUCT(float, AirCurrentLevel, 500)
		ADD_STRUCT(float, AirMaxDelta, 496)
		ADD_STRUCT(ScriptName, AirEffectScalar, 488)
		ADD_STRUCT(float, MaxVelocityForAirEffect, 484)
		ADD_STRUCT(float, MinVelocityForAirEffect, 480)
	};
}
#undef ADD_STRUCT
