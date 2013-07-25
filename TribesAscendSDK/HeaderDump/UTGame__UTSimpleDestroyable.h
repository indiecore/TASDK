#pragma once
#include "Engine__DynamicSMActor.h"
#include "Engine__StaticMesh.h"
#include "Engine__Actor.h"
#include "Engine__ParticleSystem.h"
#include "Engine__SoundCue.h"
#include "Engine__Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSimpleDestroyable." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTSimpleDestroyable." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTSimpleDestroyable." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTSimpleDestroyable : public DynamicSMActor
	{
	public:
		ADD_VAR(::FloatProperty, TimeToRespawn, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, RespawnStaticMesh)
		ADD_VAR(::FloatProperty, RespawnTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, SpawnPhysMeshAngularVel, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, SpawnPhysMeshLinearVel, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, SpawnPhysMeshLifeSpan, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, SpawnPhysMesh)
		ADD_OBJECT(ParticleSystem, ParticlesOnDestroy)
		ADD_OBJECT(SoundCue, SoundOnDestroy)
		ADD_OBJECT(StaticMesh, MeshOnDestroy)
		ADD_VAR(::BoolProperty, bDestroyed, 0x8)
		ADD_VAR(::BoolProperty, bDestroyOnVehicleTouch, 0x4)
		ADD_VAR(::BoolProperty, bDestroyOnPlayerTouch, 0x2)
		ADD_VAR(::BoolProperty, bDestroyOnDamage, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSimpleDestroyable.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GoBoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSimpleDestroyable.GoBoom");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RespawnDestructible()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSimpleDestroyable.RespawnDestructible");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSimpleDestroyable.TakeDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = DamageAmount;
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
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSimpleDestroyable.Touch");
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
		void CheckRespawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSimpleDestroyable.CheckRespawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
