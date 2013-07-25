#pragma once
#include "Engine__Actor.h"
#include "Engine__KActor.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.KActorFromStatic." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.KActorFromStatic." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class KActorFromStatic : public KActor
	{
	public:
		ADD_VAR(::FloatProperty, MaxImpulseSpeed, 0xFFFFFFFF)
		ADD_OBJECT(Actor, MyStaticMeshActor)
		class KActorFromStatic* MakeDynamic(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MovableMesh)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorFromStatic.MakeDynamic");
			byte* params = (byte*)malloc(8);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MovableMesh;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class KActorFromStatic**)(params + 4);
			free(params);
			return returnVal;
		}
		void DisablePrecomputedLighting()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorFromStatic.DisablePrecomputedLighting");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSleepRBPhysics()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorFromStatic.OnSleepRBPhysics");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnWakeRBPhysics()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorFromStatic.OnWakeRBPhysics");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BecomeStatic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorFromStatic.BecomeStatic");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MakeStatic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorFromStatic.MakeStatic");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyImpulse(Vector ImpulseDir, float ImpulseMag, Vector HitLocation, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorFromStatic.ApplyImpulse");
			byte* params = (byte*)malloc(60);
			*(Vector*)params = ImpulseDir;
			*(float*)(params + 12) = ImpulseMag;
			*(Vector*)(params + 16) = HitLocation;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 28) = HitInfo;
			*(ScriptClass**)(params + 56) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReceiveImpulse(class Pawn* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorFromStatic.ReceiveImpulse");
			byte* params = (byte*)malloc(28);
			*(class Pawn**)params = Other;
			*(Vector*)(params + 4) = HitLocation;
			*(Vector*)(params + 16) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Bump(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorFromStatic.Bump");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = OtherComp;
			*(Vector*)(params + 8) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorFromStatic.Touch");
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
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorFromStatic.TakeRadiusDamage");
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
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
