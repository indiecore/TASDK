#pragma once
#include "Engine.KActor.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Engine.ParticleSystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKKActorBreakable." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKKActorBreakable." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKKActorBreakable : public KActor
	{
	public:
		ADD_OBJECT(Controller, InstigatorController)
		ADD_OBJECT(ParticleSystem, BrokenTemplate)
		ADD_VAR(::IntProperty, DOEResetThreshold, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, DmgTypeClass)
		ADD_VAR(::IntProperty, EncroachDamage_Self, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EncroachDamage_Other, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Health, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBroken, 0x20)
		ADD_VAR(::BoolProperty, bBreakWhenCausingDamage, 0x10)
		ADD_VAR(::BoolProperty, bTakeDamageOnEncroachment, 0x8)
		ADD_VAR(::BoolProperty, bResetDOEWhenAsleep, 0x4)
		ADD_VAR(::BoolProperty, bDamageOnEncroachment, 0x2)
		ADD_VAR(::BoolProperty, bHasHealth, 0x1)
		bool OnEncroach(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKKActorBreakable.OnEncroach");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void OnBreakApart()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKKActorBreakable.OnBreakApart");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKKActorBreakable.TakeDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = Damage;
			*(class Controller**)(params + 4) = EventInstigator;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool EncroachingOn(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKKActorBreakable.EncroachingOn");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void BreakApart()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKKActorBreakable.BreakApart");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKKActorBreakable.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
