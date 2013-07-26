#pragma once
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Engine.Actor.PhysEffectInfo.h"
#include "Engine.DynamicSMActor.h"
#include "Core.Object.Rotator.h"
#include "Core.Object.Vector.h"
#include "Engine.Actor.TraceHitInfo.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.Actor.RigidBodyState.h"
#include "Engine.SeqAct_Toggle.h"
#include "Engine.SeqAct_Teleport.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.KActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.KActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class KActor : public DynamicSMActor
	{
	public:
		ADD_STRUCT(::RotatorProperty, InitialRotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, InitialLocation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ReplicatedDrawScale3D, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AngErrorAccumulator, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RigidBodyState>, RBState, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxPhysicsVelocity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StayUprightMaxTorque, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StayUprightTorqueFactor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<PhysEffectInfo>, SlideEffectInfo, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastSlideTime, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<PhysEffectInfo>, ImpactEffectInfo, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastImpactTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDisableClientSidePawnInteractions, 0x80)
		ADD_VAR(::BoolProperty, bNeedsRBStateReplication, 0x40)
		ADD_VAR(::BoolProperty, bLimitMaxPhysicsVelocity, 0x20)
		ADD_VAR(::BoolProperty, bEnableStayUprightSpring, 0x10)
		ADD_VAR(::BoolProperty, bSlideActive, 0x8)
		ADD_VAR(::BoolProperty, bCurrentSlide, 0x4)
		ADD_VAR(::BoolProperty, bWakeOnLevelStart, 0x2)
		ADD_VAR(::BoolProperty, bDamageAppliesImpulse, 0x1)
		class PhysicalMaterial* GetKActorPhysMaterial()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActor.GetKActorPhysMaterial");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PhysicalMaterial**)params;
			free(params);
			return returnVal;
		}
		void ResolveRBState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActor.ResolveRBState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActor.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActor.FellOutOfWorld");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActor.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPhysicalCollisionProperties()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActor.SetPhysicalCollisionProperties");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnedByKismet()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActor.SpawnedByKismet");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActor.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ApplyImpulse(Vector ImpulseDir, float ImpulseMag, Vector HitLocation, TraceHitInfo HitInfo, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActor.ApplyImpulse");
			byte* params = (byte*)malloc(60);
			*(Vector*)params = ImpulseDir;
			*(float*)(params + 12) = ImpulseMag;
			*(Vector*)(params + 16) = HitLocation;
			*(TraceHitInfo*)(params + 28) = HitInfo;
			*(ScriptClass**)(params + 56) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActor.TakeDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = Damage;
			*(class Controller**)(params + 4) = EventInstigator;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			*(TraceHitInfo*)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActor.TakeRadiusDamage");
			byte* params = (byte*)malloc(44);
			*(class Controller**)params = InstigatedBy;
			*(float*)(params + 4) = BaseDamage;
			*(float*)(params + 8) = DamageRadius;
			*(ScriptClass**)(params + 12) = DamageType;
			*(float*)(params + 16) = Momentum;
			*(Vector*)(params + 20) = HurtOrigin;
			*(bool*)(params + 32) = bFullDamage;
			*(class Actor**)(params + 36) = DamageCauser;
			*(float*)(params + 40) = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActor.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnTeleport(class SeqAct_Teleport* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActor.OnTeleport");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Teleport**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActor.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
