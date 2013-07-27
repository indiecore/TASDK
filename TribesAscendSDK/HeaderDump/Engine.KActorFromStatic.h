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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4082);
			byte params[8] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MovableMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class KActorFromStatic**)&params[4];
		}
		void DisablePrecomputedLighting()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19033);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSleepRBPhysics()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19037);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnWakeRBPhysics()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19038);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BecomeStatic()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19039);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MakeStatic()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19040);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyImpulse(Vector ImpulseDir, float ImpulseMag, Vector HitLocation, Actor::TraceHitInfo HitInfo, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19042);
			byte params[60] = { NULL };
			*(Vector*)params = ImpulseDir;
			*(float*)&params[12] = ImpulseMag;
			*(Vector*)&params[16] = HitLocation;
			*(Actor::TraceHitInfo*)&params[28] = HitInfo;
			*(ScriptClass**)&params[56] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceiveImpulse(class Pawn* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19051);
			byte params[28] = { NULL };
			*(class Pawn**)params = Other;
			*(Vector*)&params[4] = HitLocation;
			*(Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Bump(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19057);
			byte params[20] = { NULL };
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Vector*)&params[8] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19061);
			byte params[32] = { NULL };
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19066);
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
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
