#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKBot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKBot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKBot." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKBot : public AIController
	{
	public:
		ADD_VAR(::FloatProperty, MultiJumpZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DodgeToGoalPct, 0xFFFFFFFF)
		ADD_OBJECT(Actor, FearSpots)
		ADD_VAR(::FloatProperty, DodgeLandZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentAimError, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastErrorUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ErrorUpdateFrequency, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastAimUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AimUpdateFrequency, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastIterativeCheck, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, BlockedAimTarget)
		ADD_OBJECT(NavigationPoint, SquadRouteGoal)
		ADD_STRUCT(::VectorProperty, TrackedVelocity, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, BaseTrackingReactionTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TrackingReactionTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastSeenTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastSeeingPos, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, LastSeenPos, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, MonitorMaxDistSq, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, MonitoredPawn)
		ADD_STRUCT(::VectorProperty, MonitorStartLoc, 0xFFFFFFFF
		ADD_OBJECT(Projectile, WarningProjectile)
		ADD_VAR(::FloatProperty, WarningDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RespawnPredictionTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HearingThreshold, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AcquisitionYawRate, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ImpactVelocity, 0xFFFFFFFF
		ADD_OBJECT(Pawn, CurrentlyTrackedEnemy)
		ADD_OBJECT(Vehicle, LastBlockingVehicle)
		ADD_OBJECT(Pawn, VisibleEnemy)
		ADD_VAR(::FloatProperty, EnemyVisibilityTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ScriptedFireMode, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUsePreviousSquadRoute, 0x4000)
		ADD_VAR(::BoolProperty, bUsingSquadRoute, 0x2000)
		ADD_VAR(::BoolProperty, bAllowRouteReuse, 0x1000)
		ADD_VAR(::BoolProperty, bNeedDelayedLeaveVehicle, 0x800)
		ADD_VAR(::BoolProperty, bEnemyAcquired, 0x400)
		ADD_VAR(::BoolProperty, bInDodgeMove, 0x200)
		ADD_VAR(::BoolProperty, bPlannedJump, 0x100)
		ADD_VAR(::BoolProperty, bJumpOverWall, 0x80)
		ADD_VAR(::BoolProperty, bLeadTarget, 0x40)
		ADD_VAR(::BoolProperty, bEnemyIsVisible, 0x20)
		ADD_VAR(::BoolProperty, bEnemyInfoValid, 0x10)
		ADD_VAR(::BoolProperty, bTargetAlternateLoc, 0x8)
		ADD_VAR(::BoolProperty, bForceRefreshRoute, 0x4)
		ADD_VAR(::BoolProperty, bScriptSpecialJumpCost, 0x2)
		ADD_VAR(::BoolProperty, bExecutingWhatToDoNext, 0x1)
		ADD_OBJECT(Actor, TemporaryFocus)
		ADD_OBJECT(UDKSquadAI, Squad)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
