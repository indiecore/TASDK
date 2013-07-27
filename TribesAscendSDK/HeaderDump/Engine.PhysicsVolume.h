#pragma once
#include "Engine.Volume.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Controller.h"
#include "Engine.PlayerController.h"
#include "Engine.Pawn.h"
#include "Engine.Info.h"
#include "Engine.VolumeTimer.h"
#include "Engine.SeqAct_Toggle.h"
#include "Engine.SeqAct_SetDamageInstigator.h"
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
	class PhysicsVolume : public Volume
	{
	public:
		class CheckpointRecord
		{
		public:
			ADD_BOOL(bActive, 0, 0x2)
			ADD_BOOL(bPainCausing, 0, 0x1)
		};
		ADD_BOOL(bPainCausing, 532, 0x2)
		ADD_STRUCT(float, DamagePerSec, 544)
		ADD_BOOL(bWaterVolume, 532, 0x1000)
		ADD_OBJECT(PhysicsVolume, NextPhysicsVolume, 580)
		ADD_OBJECT(Controller, DamageInstigator, 576)
		ADD_OBJECT(Info, PainTimer, 572)
		ADD_STRUCT(float, MaxDampingForce, 568)
		ADD_STRUCT(float, RigidBodyDamping, 564)
		ADD_STRUCT(float, PainInterval, 560)
		ADD_STRUCT(float, FluidFriction, 556)
		ADD_STRUCT(int, Priority, 552)
		ADD_OBJECT(ScriptClass, DamageType, 548)
		ADD_STRUCT(float, TerminalVelocity, 540)
		ADD_STRUCT(float, GroundFriction, 536)
		ADD_BOOL(bPhysicsOnContact, 532, 0x800)
		ADD_BOOL(bCrowdAgentsPlayDeathAnim, 532, 0x400)
		ADD_BOOL(bNeutralZone, 532, 0x200)
		ADD_BOOL(bBounceVelocity, 532, 0x100)
		ADD_BOOL(bMoveProjectiles, 532, 0x80)
		ADD_BOOL(bNoInventory, 532, 0x40)
		ADD_BOOL(bDestructive, 532, 0x20)
		ADD_BOOL(BACKUP_bPainCausing, 532, 0x10)
		ADD_BOOL(bEntryPain, 532, 0x8)
		ADD_BOOL(bAIShouldIgnorePain, 532, 0x4)
		ADD_BOOL(bVelocityAffectsWalking, 532, 0x1)
		ADD_STRUCT(Object::Vector, ZoneVelocity, 520)
		float GetGravityZ()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.GetGravityZ");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		Object::Vector GetZoneVelocityForActor(class Actor* TheActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.GetZoneVelocityForActor");
			byte params[16] = { NULL };
			*(class Actor**)&params[0] = TheActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[4];
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
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ActorEnteredVolume(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.ActorEnteredVolume");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ActorLeavingVolume(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.ActorLeavingVolume");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnEnteredVolume(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.PawnEnteredVolume");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnLeavingVolume(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.PawnLeavingVolume");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggle(class SeqAct_Toggle* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.OnToggle");
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CollisionChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.CollisionChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TimerPop(class VolumeTimer* T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.TimerPop");
			byte params[4] = { NULL };
			*(class VolumeTimer**)&params[0] = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.Touch");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CausePainTo(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.CausePainTo");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ModifyPlayer(class Pawn* PlayerPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.ModifyPlayer");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = PlayerPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyPawnBecameViewTarget(class Pawn* P, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.NotifyPawnBecameViewTarget");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(class PlayerController**)&params[4] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetDamageInstigator(class SeqAct_SetDamageInstigator* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.OnSetDamageInstigator");
			byte params[4] = { NULL };
			*(class SeqAct_SetDamageInstigator**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.ShouldSaveForCheckpoint");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void CreateCheckpointRecord(PhysicsVolume::CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.CreateCheckpointRecord");
			byte params[4] = { NULL };
			*(PhysicsVolume::CheckpointRecord*)&params[0] = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(PhysicsVolume::CheckpointRecord*)&params[0];
		}
		void ApplyCheckpointRecord(PhysicsVolume::CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsVolume.ApplyCheckpointRecord");
			byte params[4] = { NULL };
			*(PhysicsVolume::CheckpointRecord*)&params[0] = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(PhysicsVolume::CheckpointRecord*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
