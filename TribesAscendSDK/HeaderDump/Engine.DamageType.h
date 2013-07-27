#pragma once
#include "Core.Object.h"
#include "Engine.ForceFeedbackWaveform.h"
#include "Engine.Vehicle.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class DamageType : public Object
	{
	public:
		ADD_OBJECT(ForceFeedbackWaveform, DamagedFFWaveform, 88)
		ADD_STRUCT(float, FracturedMeshDamage, 96)
		ADD_OBJECT(ForceFeedbackWaveform, KilledFFWaveform, 92)
		ADD_STRUCT(float, VehicleMomentumScaling, 84)
		ADD_STRUCT(float, VehicleDamageScaling, 80)
		ADD_STRUCT(float, RadialDamageImpulse, 76)
		ADD_STRUCT(float, KDeathUpKick, 72)
		ADD_STRUCT(float, KDeathVel, 68)
		ADD_STRUCT(float, KDamageImpulse, 64)
		ADD_BOOL(bRadialDamageVelChange, 60, 0x10)
		ADD_BOOL(bCausesFracture, 60, 0x8)
		ADD_BOOL(bExtraMomentumZ, 60, 0x4)
		ADD_BOOL(bCausedByWorld, 60, 0x2)
		ADD_BOOL(bArmorStops, 60, 0x1)
		float VehicleDamageScalingFor(class Vehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DamageType.VehicleDamageScalingFor");
			byte params[8] = { NULL };
			*(class Vehicle**)&params[0] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
