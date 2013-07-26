#pragma once
#include "Engine.Volume.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Engine.PlayerController.h"
#include "Engine.Pawn.h"
#include "Engine.Info.h"
#include "Core.Object.Vector.h"
#include "Engine.VolumeTimer.h"
#include "Engine.SeqAct_Toggle.h"
#include "Engine.SeqAct_SetDamageInstigator.h"
#include "Engine.PhysicsVolume.CheckpointRecord.h"
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
		ADD_STRUCT(::VectorProperty, ZoneVelocity, 0xFFFFFFFF)
		float GetGravityZ()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.GetGravityZ");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		Vector GetZoneVelocityForActor(class Actor* TheActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.GetZoneVelocityForActor");
			byte* params = (byte*)malloc(16);
			*(class Actor**)params = TheActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 4);
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PhysicsChangedFor(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.PhysicsChangedFor");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ActorEnteredVolume(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.ActorEnteredVolume");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ActorLeavingVolume(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.ActorLeavingVolume");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PawnEnteredVolume(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.PawnEnteredVolume");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PawnLeavingVolume(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.PawnLeavingVolume");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnToggle(class SeqAct_Toggle* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CollisionChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.CollisionChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TimerPop(class VolumeTimer* T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.TimerPop");
			byte* params = (byte*)malloc(4);
			*(class VolumeTimer**)params = T;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.Touch");
			byte* params = (byte*)malloc(32);
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = OtherComp;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CausePainTo(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.CausePainTo");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ModifyPlayer(class Pawn* PlayerPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.ModifyPlayer");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = PlayerPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyPawnBecameViewTarget(class Pawn* P, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.NotifyPawnBecameViewTarget");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			*(class PlayerController**)(params + 4) = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnSetDamageInstigator(class SeqAct_SetDamageInstigator* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.OnSetDamageInstigator");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_SetDamageInstigator**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.ShouldSaveForCheckpoint");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void CreateCheckpointRecord(CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.CreateCheckpointRecord");
			byte* params = (byte*)malloc(4);
			*(CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(CheckpointRecord*)params;
			free(params);
		}
		void ApplyCheckpointRecord(CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.ApplyCheckpointRecord");
			byte* params = (byte*)malloc(4);
			*(CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(CheckpointRecord*)params;
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
