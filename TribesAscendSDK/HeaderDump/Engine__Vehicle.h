#pragma once
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Vehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Vehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Vehicle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Vehicle : public Pawn
	{
	public:
		ADD_OBJECT(Pawn, Driver)
		ADD_VAR(::FloatProperty, TurnTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VehicleMovingTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AIMoveCheckTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldThrottle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OnlySteeringStartTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldSteering, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StuckTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ThrottleTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, StuckCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceCrushPenetration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinCrushSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MomentumMult, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DriverDamageMult, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, TargetLocationAdjustment, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, Rise, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Throttle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Steering, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ExitOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, ExitRadius, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDoExtraNetRelevancyTraces, 0x1000)
		ADD_VAR(::BoolProperty, bIgnoreStallZ, 0x800)
		ADD_VAR(::BoolProperty, bRetryPathfindingWithDriver, 0x400)
		ADD_VAR(::BoolProperty, bAvoidReversing, 0x200)
		ADD_VAR(::BoolProperty, bDuckObstacles, 0x100)
		ADD_VAR(::BoolProperty, bScriptedRise, 0x80)
		ADD_VAR(::BoolProperty, bHasHandbrake, 0x40)
		ADD_VAR(::BoolProperty, bFollowLookDir, 0x20)
		ADD_VAR(::BoolProperty, bSeparateTurretFocus, 0x10)
		ADD_VAR(::BoolProperty, bTurnInPlace, 0x8)
		ADD_VAR(::BoolProperty, bAttachDriver, 0x4)
		ADD_VAR(::BoolProperty, bDriverIsVisible, 0x2)
		ADD_VAR(::BoolProperty, bDriving, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
