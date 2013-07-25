#pragma once
#include "Engine__ParticleSystem.h"
#include "Engine__Actor.h"
#include "UTGame__UTPawn.h"
#include "Engine__SoundCue.h"
#include "Engine__PhysicalMaterial.h"
#include "Engine__Material.h"
#include "Engine__Weapon.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTWeaponAttachment." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTWeaponAttachment." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTWeaponAttachment." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTWeaponAttachment : public Actor
	{
	public:
		ADD_VAR(::FloatProperty, MaxFireEffectDistance, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, WeapAnimType, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AltFireAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, FireAnim, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DistFactorForRefPose, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDecalRangeSq, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, WeaponClass)
		ADD_VAR(::FloatProperty, MaxImpactEffectDistance, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, BulletWhip)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.MaterialImpactEffect' for the property named 'DefaultAltImpactEffect'!
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.MaterialImpactEffect' for the property named 'DefaultImpactEffect'!
		ADD_VAR(::NameProperty, AttachmentSocket, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MuzzleFlashDuration, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, MuzzleFlashLightClass)
		ADD_VAR(::BoolProperty, bMakeSplash, 0x8)
		ADD_VAR(::BoolProperty, bSuppressSounds, 0x4)
		ADD_VAR(::BoolProperty, bAlignToSurfaceNormal, 0x2)
		ADD_VAR(::BoolProperty, bMuzzleFlashPSCLoops, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'MuzzleFlashColor'!
		ADD_OBJECT(ParticleSystem, MuzzleFlashAltPSCTemplate)
		ADD_OBJECT(ParticleSystem, MuzzleFlashPSCTemplate)
		ADD_VAR(::NameProperty, MuzzleFlashSocket, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, SplashEffect)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckToForceRefPose()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.CheckToForceRefPose");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateOverlayMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.CreateOverlayMesh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSkin(class Material* NewMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.SetSkin");
			byte* params = (byte*)malloc(4);
			*(class Material**)params = NewMaterial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMuzzleFlashParams(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.SetMuzzleFlashParams");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AttachTo(class UTPawn* OwnerPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.AttachTo");
			byte* params = (byte*)malloc(4);
			*(class UTPawn**)params = OwnerPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPuttingDownWeapon(bool bNowPuttingDown)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.SetPuttingDownWeapon");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNowPuttingDown;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DetachFrom(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshCpnt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.DetachFrom");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MeshCpnt;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MuzzleFlashTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.MuzzleFlashTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CauseMuzzleFlash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.CauseMuzzleFlash");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopMuzzleFlash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.StopMuzzleFlash");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FirstPersonFireEffects(class Weapon* PawnWeapon, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.FirstPersonFireEffects");
			byte* params = (byte*)malloc(16);
			*(class Weapon**)params = PawnWeapon;
			*(Vector*)(params + 4) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopFirstPersonFireEffects(class Weapon* PawnWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.StopFirstPersonFireEffects");
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = PawnWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ThirdPersonFireEffects(Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.ThirdPersonFireEffects");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopThirdPersonFireEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.StopThirdPersonFireEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		
// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.MaterialImpactEffect'!
void* GetImpactEffect(class PhysicalMaterial* HitMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.GetImpactEffect");
			byte* params = (byte*)malloc(52);
			*(class PhysicalMaterial**)params = HitMaterial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.MaterialImpactEffect'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		bool AllowImpactEffects(class Actor* HitActor, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.AllowImpactEffects");
			byte* params = (byte*)malloc(32);
			*(class Actor**)params = HitActor;
			*(Vector*)(params + 4) = HitLocation;
			*(Vector*)(params + 16) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void SetImpactedActor(class Actor* HitActor, Vector HitLocation, Vector HitNormal, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.SetImpactedActor");
			byte* params = (byte*)malloc(56);
			*(class Actor**)params = HitActor;
			*(Vector*)(params + 4) = HitLocation;
			*(Vector*)(params + 16) = HitNormal;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 28) = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayImpactEffects(Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.PlayImpactEffects");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CheckBulletWhip(Vector FireDir, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.CheckBulletWhip");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = FireDir;
			*(Vector*)(params + 12) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetWeaponOverlayFlags(class UTPawn* OwnerPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.SetWeaponOverlayFlags");
			byte* params = (byte*)malloc(4);
			*(class UTPawn**)params = OwnerPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ChangeVisibility(bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.ChangeVisibility");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FireModeUpdated(byte FiringMode, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.FireModeUpdated");
			byte* params = (byte*)malloc(5);
			*params = FiringMode;
			*(bool*)(params + 4) = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector GetEffectLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.GetEffectLocation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
