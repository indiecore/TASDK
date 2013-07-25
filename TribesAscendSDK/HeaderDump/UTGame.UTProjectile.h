#pragma once
#include "UDKBase.UDKProjectile.h"
#include "Engine.MaterialInterface.h"
#include "Engine.ParticleSystem.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.SoundCue.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTProjectile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTProjectile." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTProjectile : public UDKProjectile
	{
	public:
		ADD_VAR(::FloatProperty, GlobalCheckRadiusTweak, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TossZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxExplosionLightDistance, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, ExplosionLightClass)
		ADD_OBJECT(ScriptClass, ProjectileLightClass)
		ADD_VAR(::FloatProperty, MaxEffectDistance, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, DecalDissolveParamName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DurationOfDecal, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DecalHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DecalWidth, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, ExplosionDecal)
		ADD_OBJECT(ParticleSystem, ProjExplosionTemplate)
		ADD_OBJECT(ParticleSystem, ProjFlightTemplate)
		ADD_OBJECT(SoundCue, ExplosionSound)
		ADD_OBJECT(SoundCue, AmbientSound)
		ADD_VAR(::BoolProperty, bAttachExplosionToVehicles, 0x40)
		ADD_VAR(::BoolProperty, bWaitForEffects, 0x20)
		ADD_VAR(::BoolProperty, bSuppressExplosionFX, 0x10)
		ADD_VAR(::BoolProperty, bAdvanceExplosionEffect, 0x8)
		ADD_VAR(::BoolProperty, m_bDestroyProjEffects, 0x4)
		ADD_VAR(::BoolProperty, bImportantAmbientSound, 0x2)
		ADD_VAR(::BoolProperty, bSuppressSounds, 0x1)
		void CreateProjectileLight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.CreateProjectileLight");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Landed(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.Landed");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanSplash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.CanSplash");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInitialState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.SetInitialState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Init(Vector Direction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.Init");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = Direction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessTouch(class Actor* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.ProcessTouch");
			byte* params = (byte*)malloc(28);
			*(class Actor**)params = Other;
			*(Vector*)(params + 4) = HitLocation;
			*(Vector*)(params + 16) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Explode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.Explode");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.SpawnFlightEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetExplosionEffectParameters(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* ProjExplosion)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.SetExplosionEffectParameters");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = ProjExplosion;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class SoundCue* GetExplosionSound(class PhysicalMaterial* HitMaterial, class Actor* HitActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.GetExplosionSound");
			byte* params = (byte*)malloc(12);
			*(class PhysicalMaterial**)params = HitMaterial;
			*(class Actor**)(params + 4) = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SoundCue**)(params + 8);
			free(params);
			return returnVal;
		}
		void SpawnExplosionEffects(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.SpawnExplosionEffects");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldSpawnExplosionLight(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.ShouldSpawnExplosionLight");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void ShutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.ShutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TornOff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.TornOff");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideProjectile()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.HideProjectile");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MyOnParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.MyOnParticleSystemFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CalcCamera(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.CalcCamera");
			byte* params = (byte*)malloc(36);
			*(float*)params = fDeltaTime;
			*(Vector*)(params + 4) = out_CamLoc;
			*(Rotator*)(params + 16) = out_CamRot;
			*(float*)(params + 28) = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_CamLoc = *(Vector*)(params + 4);
			out_CamRot = *(Rotator*)(params + 16);
			out_FOV = *(float*)(params + 28);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		class Actor* GetHomingTarget(class UTProjectile* Seeker, class Controller* InstigatedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.GetHomingTarget");
			byte* params = (byte*)malloc(12);
			*(class UTProjectile**)params = Seeker;
			*(class Controller**)(params + 4) = InstigatedBy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 8);
			free(params);
			return returnVal;
		}
		class Pawn* GetPawnOwner()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.GetPawnOwner");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Pawn**)params;
			free(params);
			return returnVal;
		}
		float CalculateTravelTime(float Dist, float MoveSpeed, float MaxMoveSpeed, float AccelMag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.CalculateTravelTime");
			byte* params = (byte*)malloc(20);
			*(float*)params = Dist;
			*(float*)(params + 4) = MoveSpeed;
			*(float*)(params + 8) = MaxMoveSpeed;
			*(float*)(params + 12) = AccelMag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 16);
			free(params);
			return returnVal;
		}
		float StaticGetTimeToLocation(Vector TargetLoc, Vector StartLoc, class Controller* RequestedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.StaticGetTimeToLocation");
			byte* params = (byte*)malloc(32);
			*(Vector*)params = TargetLoc;
			*(Vector*)(params + 12) = StartLoc;
			*(class Controller**)(params + 24) = RequestedBy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 28);
			free(params);
			return returnVal;
		}
		float GetTimeToLocation(Vector TargetLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.GetTimeToLocation");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = TargetLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		float GetRange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTProjectile.GetRange");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
