#pragma once
#include "Engine.Controller.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.FractureMaterial.h"
#include "Engine.SoundCue.h"
#include "Engine.ParticleSystem.h"
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
	class ApexDestructibleActor : public Actor
	{
	public:
		ADD_STRUCT(ScriptArray<class FractureMaterial*>, FractureMaterials, 484)
		ADD_STRUCT(ScriptArray<byte>, VisibilityFactors, 500)
		ADD_STRUCT(ScriptArray<class SoundCue*>, FractureSounds, 512)
		ADD_STRUCT(ScriptArray<class ParticleSystem*>, FractureParticleEffects, 524)
		ADD_BOOL(bFractureMaterialOverride, 480, 0x1)
		void SpawnFractureEmitter(class ParticleSystem* EmitterTemplate, Object::Vector SpawnLocation, Object::Vector SpawnDirection)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ApexDestructibleActor.SpawnFractureEmitter");
			byte params[28] = { NULL };
			*(class ParticleSystem**)&params[0] = EmitterTemplate;
			*(Object::Vector*)&params[4] = SpawnLocation;
			*(Object::Vector*)&params[16] = SpawnDirection;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		void TakeDamage(int Damage, class Controller* EventInstigator, Object::Vector HitLocation, Object::Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ApexDestructibleActor.TakeDamage");
			byte params[68] = { NULL };
			*(int*)&params[0] = Damage;
			*(class Controller**)&params[4] = EventInstigator;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Object::Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ApexDestructibleActor.TakeRadiusDamage");
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
#undef ADD_BOOL
#undef ADD_STRUCT
