#pragma once
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Engine.ParticleSystem.h"
#include "Core.Object.Vector.h"
#include "Engine.Actor.TraceHitInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ApexDestructibleActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ApexDestructibleActor : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bFractureMaterialOverride, 0x1)
		void SpawnFractureEmitter(class ParticleSystem* EmitterTemplate, Vector SpawnLocation, Vector SpawnDirection)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ApexDestructibleActor.SpawnFractureEmitter");
			byte* params = (byte*)malloc(28);
			*(class ParticleSystem**)params = EmitterTemplate;
			*(Vector*)(params + 4) = SpawnLocation;
			*(Vector*)(params + 16) = SpawnDirection;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CacheFractureEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ApexDestructibleActor.CacheFractureEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ApexDestructibleActor.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ApexDestructibleActor.TakeDamage");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ApexDestructibleActor.TakeRadiusDamage");
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
