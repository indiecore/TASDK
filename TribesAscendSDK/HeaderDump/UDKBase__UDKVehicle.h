#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKVehicle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKVehicle : public UDKVehicleBase
	{
	public:
		ADD_VAR(::BoolProperty, bAllowedExit, 0x8000)
		ADD_VAR(::BoolProperty, bEjectKilledBodies, 0x1)
		ADD_STRUCT(::VectorProperty, HUDLocation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, ShowLockedMaxDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastPostRenderTraceTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TeamBeaconMaxDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinRunOverWarningAim, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastRunOverWarningTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinRunOverSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ResetTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExtraReachDownThreshold, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Team, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ObjectiveGetOutDist, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ContrailColorParameterName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, WaterEffectType, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastJumpOutCheck, 0xFFFFFFFF)
		ADD_OBJECT(Controller, KillerController)
		ADD_VAR(::FloatProperty, LastTakeHitTimeout, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.UTTakeHitInfo' for the property named 'LastTakeHitInfo'!
		ADD_OBJECT(MaterialInstanceConstant, DamageMaterialInstance)
		ADD_VAR(::FloatProperty, CustomGravityScaling, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, SmallChunkImpactSound)
		ADD_OBJECT(SoundCue, MediumChunkImpactSound)
		ADD_OBJECT(SoundCue, LargeChunkImpactSound)
		ADD_VAR(::FloatProperty, LastDeathImpactTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeInDestroyablePenetration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DestroyOnPenetrationDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DestroyOnPenetrationThreshold, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, DrivingAnim, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SeatMask, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, WeaponRotation, 0xFFFFFFFF
		ADD_OBJECT(ParticleSystem, WaterGroundEffect)
		ADD_VAR(::NameProperty, GroundEffectDistParameterName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxGroundEffectDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AccumulatedWaterDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WaterDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OccupiedUpsideDownDamagePerSec, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, UpsideDownDamagePerSec, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AccruedFireDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FireDamagePerSec, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FireDamageThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FlippedCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastCheckUpsideDownTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxWheelEffectDistSq, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, CurrentTireMaterial, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RemainingBurn, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForceSpinWarmup, 0x800000)
		ADD_VAR(::BoolProperty, bGrab2, 0x400000)
		ADD_VAR(::BoolProperty, bGrab1, 0x200000)
		ADD_VAR(::BoolProperty, bTrickJumping, 0x100000)
		ADD_VAR(::BoolProperty, bDisableRepulsorsAtMaxFallSpeed, 0x80000)
		ADD_VAR(::BoolProperty, bTeamLocked, 0x40000)
		ADD_VAR(::BoolProperty, bShowLocked, 0x20000)
		ADD_VAR(::BoolProperty, bUseAlternatePaths, 0x10000)
		ADD_VAR(::BoolProperty, bFloatWhenDriven, 0x4000)
		ADD_VAR(::BoolProperty, bJostleWhileDriving, 0x2000)
		ADD_VAR(::BoolProperty, bDeadVehicle, 0x1000)
		ADD_VAR(::BoolProperty, bIsInDestroyablePenetration, 0x800)
		ADD_VAR(::BoolProperty, bTakeWaterDamageWhileDriving, 0x400)
		ADD_VAR(::BoolProperty, bIsScraping, 0x200)
		ADD_VAR(::BoolProperty, bEjectPassengersWhenFlipped, 0x100)
		ADD_VAR(::BoolProperty, bIsBurning, 0x80)
		ADD_VAR(::BoolProperty, bIsDisabled, 0x40)
		ADD_VAR(::BoolProperty, bNoZDamping, 0x20)
		ADD_VAR(::BoolProperty, bNoZDampingInAir, 0x10)
		ADD_VAR(::BoolProperty, bFrontalCollisionWithFixed, 0x8)
		ADD_VAR(::BoolProperty, bFrontalCollision, 0x4)
		ADD_VAR(::BoolProperty, bHomingTarget, 0x2)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
