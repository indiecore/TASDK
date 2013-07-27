#pragma once
#include "Engine.KActor.h"
#include "Engine.Controller.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.Pawn.h"
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
	class KActorFromStatic : public KActor
	{
	public:
		ADD_STRUCT(float, MaxImpulseSpeed, 716)
		ADD_OBJECT(Actor, MyStaticMeshActor, 712)
		class KActorFromStatic* MakeDynamic(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MovableMesh)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorFromStatic.MakeDynamic");
			byte params[8] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = MovableMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class KActorFromStatic**)&params[4];
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
		void ApplyImpulse(Object::Vector ImpulseDir, float ImpulseMag, Object::Vector HitLocation, Actor::TraceHitInfo HitInfo, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorFromStatic.ApplyImpulse");
			byte params[60] = { NULL };
			*(Object::Vector*)&params[0] = ImpulseDir;
			*(float*)&params[12] = ImpulseMag;
			*(Object::Vector*)&params[16] = HitLocation;
			*(Actor::TraceHitInfo*)&params[28] = HitInfo;
			*(ScriptClass**)&params[56] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceiveImpulse(class Pawn* Other, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorFromStatic.ReceiveImpulse");
			byte params[28] = { NULL };
			*(class Pawn**)&params[0] = Other;
			*(Object::Vector*)&params[4] = HitLocation;
			*(Object::Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Bump(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorFromStatic.Bump");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Object::Vector*)&params[8] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorFromStatic.Touch");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Object::Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorFromStatic.TakeRadiusDamage");
			byte params[44] = { NULL };
			*(class Controller**)&params[0] = InstigatedBy;
			*(float*)&params[4] = BaseDamage;
			*(float*)&params[8] = DamageRadius;
			*(ScriptClass**)&params[12] = DamageType;
			*(float*)&params[16] = Momentum;
			*(Object::Vector*)&params[20] = HurtOrigin;
			*(bool*)&params[32] = bFullDamage;
			*(class Actor**)&params[36] = DamageCauser;
			*(float*)&params[40] = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
