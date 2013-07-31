#pragma once
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.DynamicSMActor.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.SeqAct_Toggle.h"
#include "Engine.SeqAct_Teleport.h"
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
namespace UnrealScript
{
	class KActor : public DynamicSMActor
	{
	public:
		ADD_STRUCT(Rotator, InitialRotation, 700)
		ADD_STRUCT(Vector, InitialLocation, 688)
		ADD_STRUCT(Vector, ReplicatedDrawScale3D, 676)
		ADD_STRUCT(float, AngErrorAccumulator, 672)
		ADD_STRUCT(Actor::RigidBodyState, RBState, 608)
		ADD_STRUCT(float, MaxPhysicsVelocity, 604)
		ADD_STRUCT(float, StayUprightMaxTorque, 600)
		ADD_STRUCT(float, StayUprightTorqueFactor, 596)
		ADD_STRUCT(Actor::PhysEffectInfo, SlideEffectInfo, 580)
		ADD_STRUCT(float, LastSlideTime, 576)
		ADD_STRUCT(Actor::PhysEffectInfo, ImpactEffectInfo, 552)
		ADD_STRUCT(float, LastImpactTime, 548)
		ADD_BOOL(bDisableClientSidePawnInteractions, 532, 0x80)
		ADD_BOOL(bNeedsRBStateReplication, 532, 0x40)
		ADD_BOOL(bLimitMaxPhysicsVelocity, 532, 0x20)
		ADD_BOOL(bEnableStayUprightSpring, 532, 0x10)
		ADD_BOOL(bSlideActive, 532, 0x8)
		ADD_BOOL(bCurrentSlide, 532, 0x4)
		ADD_BOOL(bWakeOnLevelStart, 532, 0x2)
		ADD_BOOL(bDamageAppliesImpulse, 532, 0x1)
		class PhysicalMaterial* GetKActorPhysMaterial()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18980);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PhysicalMaterial**)params;
		}
		void ResolveRBState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18982);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18983);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18984);
			byte params[4] = { NULL };
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18986);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPhysicalCollisionProperties()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18987);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnedByKismet()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18989);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18990);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyImpulse(Vector ImpulseDir, float ImpulseMag, Vector HitLocation, Actor::TraceHitInfo HitInfo, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18993);
			byte params[60] = { NULL };
			*(Vector*)params = ImpulseDir;
			*(float*)&params[12] = ImpulseMag;
			*(Vector*)&params[16] = HitLocation;
			*(Actor::TraceHitInfo*)&params[28] = HitInfo;
			*(ScriptClass**)&params[56] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19000);
			byte params[68] = { NULL };
			*(int*)params = Damage;
			*(class Controller**)&params[4] = EventInstigator;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19008);
			byte params[44] = { NULL };
			*(class Controller**)params = InstigatedBy;
			*(float*)&params[4] = BaseDamage;
			*(float*)&params[8] = DamageRadius;
			*(ScriptClass**)&params[12] = DamageType;
			*(float*)&params[16] = Momentum;
			*(Vector*)&params[20] = HurtOrigin;
			*(bool*)&params[32] = bFullDamage;
			*(class Actor**)&params[36] = DamageCauser;
			*(float*)&params[40] = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19020);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnTeleport(class SeqAct_Teleport* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19022);
			byte params[4] = { NULL };
			*(class SeqAct_Teleport**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19028);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
