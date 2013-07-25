#pragma once
#include "Engine__SVehicleSimBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKVehicleSimHoverboard." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKVehicleSimHoverboard." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKVehicleSimHoverboard." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKVehicleSimHoverboard : public SVehicleSimBase
	{
	public:
		ADD_VAR(::FloatProperty, CurrentLookYaw, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SlalomSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HoverboardSlalomMaxAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentSteerOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LandedCountdown, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpinSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AutoSpin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpinHeadingOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TrickJumpWarmup, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TakeoffYaw, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, GroundNormal, 0xFFFFFFFF
		ADD_OBJECT(SoundCue, OverWaterSound)
		ADD_VAR(::FloatProperty, WaterCheckLevel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StopThreshold, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bLeftGround, 0x4)
		ADD_VAR(::BoolProperty, bInAJump, 0x2)
		ADD_VAR(::BoolProperty, bIsOverDeepWater, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveFloat' for the property named 'TurnDampingSpeedFunc'!
		ADD_VAR(::FloatProperty, MaxTurnTorque, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpinTurnTorqueScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TurnTorqueFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxRiseForce, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LatDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxStrafeForce, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LongDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxReverseVelocity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxReverseForce, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxThrustForce, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
