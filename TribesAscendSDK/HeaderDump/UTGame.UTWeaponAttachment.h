#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "UDKBase.UDKPawn.h"
#include "Engine.ParticleSystem.h"
#include "UTGame.UTPawn.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.SoundCue.h"
#include "Engine.Material.h"
#include "Engine.Weapon.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTWeaponAttachment : public Actor
	{
	public:
		ADD_STRUCT(float, MaxFireEffectDistance, 668)
		ADD_STRUCT(ScriptArray<UDKPawn::MaterialImpactEffect>, ImpactEffects, 540)
		ADD_STRUCT(ScriptArray<UDKPawn::MaterialImpactEffect>, AltImpactEffects, 552)
		ADD_STRUCT(UTPawn::EWeapAnimType, WeapAnimType, 700)
		ADD_STRUCT(ScriptName, AltFireAnim, 692)
		ADD_STRUCT(ScriptName, FireAnim, 684)
		ADD_STRUCT(float, DistFactorForRefPose, 680)
		ADD_STRUCT(float, MaxDecalRangeSq, 676)
		ADD_OBJECT(ScriptClass, WeaponClass, 672)
		ADD_STRUCT(float, MaxImpactEffectDistance, 664)
		ADD_OBJECT(SoundCue, BulletWhip, 660)
		ADD_STRUCT(UDKPawn::MaterialImpactEffect, DefaultAltImpactEffect, 612)
		ADD_STRUCT(UDKPawn::MaterialImpactEffect, DefaultImpactEffect, 564)
		ADD_STRUCT(ScriptName, AttachmentSocket, 532)
		ADD_STRUCT(float, MuzzleFlashDuration, 524)
		ADD_OBJECT(ScriptClass, MuzzleFlashLightClass, 516)
		ADD_BOOL(bMakeSplash, 512, 0x8)
		ADD_BOOL(bSuppressSounds, 512, 0x4)
		ADD_BOOL(bAlignToSurfaceNormal, 512, 0x2)
		ADD_BOOL(bMuzzleFlashPSCLoops, 512, 0x1)
		ADD_STRUCT(Object::Color, MuzzleFlashColor, 508)
		ADD_OBJECT(ParticleSystem, MuzzleFlashAltPSCTemplate, 504)
		ADD_OBJECT(ParticleSystem, MuzzleFlashPSCTemplate, 500)
		ADD_STRUCT(ScriptName, MuzzleFlashSocket, 488)
		ADD_OBJECT(ScriptClass, SplashEffect, 476)
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
			byte params[4] = { NULL };
			*(class Material**)&params[0] = NewMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMuzzleFlashParams(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.SetMuzzleFlashParams");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = PSC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AttachTo(class UTPawn* OwnerPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.AttachTo");
			byte params[4] = { NULL };
			*(class UTPawn**)&params[0] = OwnerPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPuttingDownWeapon(bool bNowPuttingDown)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.SetPuttingDownWeapon");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNowPuttingDown;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachFrom(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshCpnt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.DetachFrom");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = MeshCpnt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		void FirstPersonFireEffects(class Weapon* PawnWeapon, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.FirstPersonFireEffects");
			byte params[16] = { NULL };
			*(class Weapon**)&params[0] = PawnWeapon;
			*(Object::Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopFirstPersonFireEffects(class Weapon* PawnWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.StopFirstPersonFireEffects");
			byte params[4] = { NULL };
			*(class Weapon**)&params[0] = PawnWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ThirdPersonFireEffects(Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.ThirdPersonFireEffects");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopThirdPersonFireEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.StopThirdPersonFireEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		UDKPawn::MaterialImpactEffect GetImpactEffect(class PhysicalMaterial* HitMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.GetImpactEffect");
			byte params[52] = { NULL };
			*(class PhysicalMaterial**)&params[0] = HitMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UDKPawn::MaterialImpactEffect*)&params[4];
		}
		bool AllowImpactEffects(class Actor* HitActor, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.AllowImpactEffects");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = HitActor;
			*(Object::Vector*)&params[4] = HitLocation;
			*(Object::Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void SetImpactedActor(class Actor* HitActor, Object::Vector HitLocation, Object::Vector HitNormal, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.SetImpactedActor");
			byte params[56] = { NULL };
			*(class Actor**)&params[0] = HitActor;
			*(Object::Vector*)&params[4] = HitLocation;
			*(Object::Vector*)&params[16] = HitNormal;
			*(Actor::TraceHitInfo*)&params[28] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayImpactEffects(Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.PlayImpactEffects");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckBulletWhip(Object::Vector FireDir, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.CheckBulletWhip");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = FireDir;
			*(Object::Vector*)&params[12] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetWeaponOverlayFlags(class UTPawn* OwnerPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.SetWeaponOverlayFlags");
			byte params[4] = { NULL };
			*(class UTPawn**)&params[0] = OwnerPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangeVisibility(bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.ChangeVisibility");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FireModeUpdated(byte FiringMode, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.FireModeUpdated");
			byte params[5] = { NULL };
			params[0] = FiringMode;
			*(bool*)&params[4] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector GetEffectLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponAttachment.GetEffectLocation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
