#pragma once
#include "Engine__VolumeTimer.h"
#include "Engine__Pawn.h"
#include "Engine__Controller.h"
#include "Engine__Volume.h"
#include "Engine__Info.h"
#include "Engine__SeqAct_SetDamageInstigator.h"
#include "Engine__Actor.h"
#include "Engine__SeqAct_Toggle.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PhysicsVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.PhysicsVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PhysicsVolume." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PhysicsVolume : public Volume
	{
	public:
		ADD_VAR(::BoolProperty, bPainCausing, 0x2)
		ADD_VAR(::FloatProperty, DamagePerSec, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaterVolume, 0x1000)
		ADD_OBJECT(PhysicsVolume, NextPhysicsVolume)
		ADD_OBJECT(Controller, DamageInstigator)
		ADD_OBJECT(Info, PainTimer)
		ADD_VAR(::FloatProperty, MaxDampingForce, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RigidBodyDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PainInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FluidFriction, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Priority, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, DamageType)
		ADD_VAR(::FloatProperty, TerminalVelocity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GroundFriction, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPhysicsOnContact, 0x800)
		ADD_VAR(::BoolProperty, bCrowdAgentsPlayDeathAnim, 0x400)
		ADD_VAR(::BoolProperty, bNeutralZone, 0x200)
		ADD_VAR(::BoolProperty, bBounceVelocity, 0x100)
		ADD_VAR(::BoolProperty, bMoveProjectiles, 0x80)
		ADD_VAR(::BoolProperty, bNoInventory, 0x40)
		ADD_VAR(::BoolProperty, bDestructive, 0x20)
		ADD_VAR(::BoolProperty, BACKUP_bPainCausing, 0x10)
		ADD_VAR(::BoolProperty, bEntryPain, 0x8)
		ADD_VAR(::BoolProperty, bAIShouldIgnorePain, 0x4)
		ADD_VAR(::BoolProperty, bVelocityAffectsWalking, 0x1)
		ADD_STRUCT(::VectorProperty, ZoneVelocity, 0xFFFFFFFF
		// Here lies the not-yet-implemented method 'GetGravityZ'
		// Here lies the not-yet-implemented method 'GetZoneVelocityForActor'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'PhysicsChangedFor'
		// Here lies the not-yet-implemented method 'ActorEnteredVolume'
		// Here lies the not-yet-implemented method 'ActorLeavingVolume'
		// Here lies the not-yet-implemented method 'PawnEnteredVolume'
		// Here lies the not-yet-implemented method 'PawnLeavingVolume'
		// Here lies the not-yet-implemented method 'OnToggle'
		// Here lies the not-yet-implemented method 'CollisionChanged'
		// Here lies the not-yet-implemented method 'TimerPop'
		// Here lies the not-yet-implemented method 'Touch'
		// Here lies the not-yet-implemented method 'CausePainTo'
		// Here lies the not-yet-implemented method 'ModifyPlayer'
		// Here lies the not-yet-implemented method 'NotifyPawnBecameViewTarget'
		// Here lies the not-yet-implemented method 'OnSetDamageInstigator'
		// Here lies the not-yet-implemented method 'ShouldSaveForCheckpoint'
		// Here lies the not-yet-implemented method 'CreateCheckpointRecord'
		// Here lies the not-yet-implemented method 'ApplyCheckpointRecord'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
