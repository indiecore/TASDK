#pragma once
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#include "Engine__HUD.h"
#include "Engine__Actor.h"
#include "Engine__PlayerController.h"
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
		ADD_OBJECT(ScriptClass, CrushedDamageType)
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
		// Here lies the not-yet-implemented method 'DriverLeave'
		// Here lies the not-yet-implemented method 'TryToDrive'
		// Here lies the not-yet-implemented method 'NotifyTeamChanged'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'Suicide'
		// Here lies the not-yet-implemented method 'GetMaxRiseForce'
		// Here lies the not-yet-implemented method 'GetTargetLocation'
		// Here lies the not-yet-implemented method 'TakeRadiusDamage'
		// Here lies the not-yet-implemented method 'DriverRadiusDamage'
		// Here lies the not-yet-implemented method 'PlayerChangedTeam'
		// Here lies the not-yet-implemented method 'SetBaseEyeheight'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'CheatWalk'
		// Here lies the not-yet-implemented method 'CheatGhost'
		// Here lies the not-yet-implemented method 'CheatFly'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'Destroyed_HandleDriver'
		// Here lies the not-yet-implemented method 'CanEnterVehicle'
		// Here lies the not-yet-implemented method 'AnySeatAvailable'
		// Here lies the not-yet-implemented method 'DriverEnter'
		// Here lies the not-yet-implemented method 'PossessedBy'
		// Here lies the not-yet-implemented method 'EntryAnnouncement'
		// Here lies the not-yet-implemented method 'AttachDriver'
		// Here lies the not-yet-implemented method 'DetachDriver'
		// Here lies the not-yet-implemented method 'ContinueOnFoot'
		// Here lies the not-yet-implemented method 'GetExitRotation'
		// Here lies the not-yet-implemented method 'SetInputs'
		// Here lies the not-yet-implemented method 'DriverLeft'
		// Here lies the not-yet-implemented method 'PlaceExitingDriver'
		// Here lies the not-yet-implemented method 'FindAutoExit'
		// Here lies the not-yet-implemented method 'TryExitPos'
		// Here lies the not-yet-implemented method 'UnPossessed'
		// Here lies the not-yet-implemented method 'SetKillInstigator'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'AdjustDriverDamage'
		// Here lies the not-yet-implemented method 'ThrowActiveWeapon'
		// Here lies the not-yet-implemented method 'Died'
		// Here lies the not-yet-implemented method 'DriverDied'
		// Here lies the not-yet-implemented method 'PlayDying'
		// Here lies the not-yet-implemented method 'GetDefaultCameraMode'
		// Here lies the not-yet-implemented method 'FaceRotation'
		// Here lies the not-yet-implemented method 'EncroachedBy'
		// Here lies the not-yet-implemented method 'GetCollisionDamageInstigator'
		// Here lies the not-yet-implemented method 'EncroachingOn'
		// Here lies the not-yet-implemented method 'PancakeOther'
		// Here lies the not-yet-implemented method 'CrushedBy'
		// Here lies the not-yet-implemented method 'GetEntryLocation'
		// Here lies the not-yet-implemented method 'SetDriving'
		// Here lies the not-yet-implemented method 'DrivingStatusChanged'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'NotifyDriverTakeHit'
		// Here lies the not-yet-implemented method 'ZeroMovementVariables'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
