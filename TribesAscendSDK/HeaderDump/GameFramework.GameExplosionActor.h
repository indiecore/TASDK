#pragma once
#include "GameFramework.GamePawn.h"
#include "GameFramework.GameExplosion.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.ParticleSystem.h"
#include "Engine.CameraShake.h"
#include "Engine.PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameExplosionActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GameExplosionActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameExplosionActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameExplosionActor : public Actor
	{
	public:
		ADD_STRUCT(::VectorProperty, ExplosionDirection, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DirectionalExplosionMinDot, 0xFFFFFFFF)
		ADD_OBJECT(Controller, AttacheeController)
		ADD_OBJECT(Actor, Attachee)
		ADD_STRUCT(::VectorProperty, HitLocationFromPhysMaterialTrace, 0xFFFFFFFF)
		ADD_OBJECT(Actor, HitActorFromPhysMaterialTrace)
		ADD_OBJECT(Controller, InstigatorController)
		ADD_OBJECT(GameExplosion, ExplosionTemplate)
		ADD_VAR(::FloatProperty, RadialBlurMaxBlurAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RadialBlurFadeTimeRemaining, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RadialBlurFadeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LightInitialBrightness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LightFadeTimeRemaining, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LightFadeTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDrawDebug, 0x4)
		ADD_VAR(::BoolProperty, bExplodeMoreThanOnce, 0x2)
		ADD_VAR(::BoolProperty, bHasExploded, 0x1)
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class PhysicalMaterial* GetPhysicalMaterial()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.GetPhysicalMaterial");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PhysicalMaterial**)params;
			free(params);
			return returnVal;
		}
		bool DoFullDamageToActor(class Actor* Victim)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.DoFullDamageToActor");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Victim;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsBehindExplosion(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.IsBehindExplosion");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		float BoxDistanceToPoint(Vector Start, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Box'!
void* BBox)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.BoxDistanceToPoint");
			byte* params = (byte*)malloc(44);
			*(Vector*)params = Start;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Box'!
void**)(params + 12) = BBox;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 40);
			free(params);
			return returnVal;
		}
		void DoExplosionDamage(bool bCauseDamage, bool bCauseEffects)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.DoExplosionDamage");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bCauseDamage;
			*(bool*)(params + 4) = bCauseEffects;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetEffectCheckRadius()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.GetEffectCheckRadius");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void SpecialPawnEffectsFor(class GamePawn* VictimPawn, float VictimDist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.SpecialPawnEffectsFor");
			byte* params = (byte*)malloc(8);
			*(class GamePawn**)params = VictimPawn;
			*(float*)(params + 4) = VictimDist;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateExplosionTemplateWithPerMaterialFX(class PhysicalMaterial* PhysMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.UpdateExplosionTemplateWithPerMaterialFX");
			byte* params = (byte*)malloc(4);
			*(class PhysicalMaterial**)params = PhysMaterial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpawnExplosionParticleSystem(class ParticleSystem* Template)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.SpawnExplosionParticleSystem");
			byte* params = (byte*)malloc(4);
			*(class ParticleSystem**)params = Template;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpawnExplosionDecal()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.SpawnExplosionDecal");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnExplosionFogVolume()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.SpawnExplosionFogVolume");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Explode(class GameExplosion* NewExplosionTemplate, Vector Direction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.Explode");
			byte* params = (byte*)malloc(16);
			*(class GameExplosion**)params = NewExplosionTemplate;
			*(Vector*)(params + 4) = Direction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DelayedExplosionDamage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.DelayedExplosionDamage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawDebug()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.DrawDebug");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DoExplosionCameraEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.DoExplosionCameraEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnCameraLensEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.SpawnCameraLensEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class CameraShake* ChooseCameraShake(Vector Epicenter, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameExplosionActor.ChooseCameraShake");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = Epicenter;
			*(class PlayerController**)(params + 12) = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class CameraShake**)(params + 16);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
