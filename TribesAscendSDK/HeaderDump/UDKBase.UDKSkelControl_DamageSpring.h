#pragma once
#include "UDKBase.UDKSkelControl_Damage.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_DamageSpring : public UDKSkelControl_Damage
	{
	public:
		ADD_STRUCT(float, MomentumPortion, 444)
		ADD_STRUCT(float, LastHitTime, 440)
		ADD_STRUCT(Vector, LastHitMomentum, 428)
		ADD_STRUCT(float, RandomPortion, 424)
		ADD_STRUCT(Rotator, CurrentAngle, 412)
		ADD_STRUCT(float, AVModifier, 408)
		ADD_STRUCT(float, SpringStiffness, 404)
		ADD_STRUCT(float, Falloff, 400)
		ADD_STRUCT(Rotator, MinAngle, 388)
		ADD_STRUCT(Rotator, MaxAngle, 376)
	};
}
#undef ADD_STRUCT
