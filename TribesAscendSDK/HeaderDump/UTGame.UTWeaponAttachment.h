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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42331);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckToForceRefPose()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42332);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateOverlayMesh()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42333);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSkin(class Material* NewMaterial)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42334);
			byte params[4] = { NULL };
			*(class Material**)params = NewMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMuzzleFlashParams(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42338);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AttachTo(class UTPawn* OwnerPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42340);
			byte params[4] = { NULL };
			*(class UTPawn**)params = OwnerPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPuttingDownWeapon(bool bNowPuttingDown)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42342);
			byte params[4] = { NULL };
			*(bool*)params = bNowPuttingDown;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachFrom(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshCpnt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42344);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MeshCpnt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MuzzleFlashTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42346);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CauseMuzzleFlash()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42347);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopMuzzleFlash()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42349);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FirstPersonFireEffects(class Weapon* PawnWeapon, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42350);
			byte params[16] = { NULL };
			*(class Weapon**)params = PawnWeapon;
			*(Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopFirstPersonFireEffects(class Weapon* PawnWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42353);
			byte params[4] = { NULL };
			*(class Weapon**)params = PawnWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ThirdPersonFireEffects(Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42355);
			byte params[12] = { NULL };
			*(Vector*)params = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopThirdPersonFireEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42358);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		UDKPawn::MaterialImpactEffect GetImpactEffect(class PhysicalMaterial* HitMaterial)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42359);
			byte params[52] = { NULL };
			*(class PhysicalMaterial**)params = HitMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UDKPawn::MaterialImpactEffect*)&params[4];
		}
		bool AllowImpactEffects(class Actor* HitActor, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42364);
			byte params[32] = { NULL };
			*(class Actor**)params = HitActor;
			*(Vector*)&params[4] = HitLocation;
			*(Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void SetImpactedActor(class Actor* HitActor, Vector HitLocation, Vector HitNormal, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42369);
			byte params[56] = { NULL };
			*(class Actor**)params = HitActor;
			*(Vector*)&params[4] = HitLocation;
			*(Vector*)&params[16] = HitNormal;
			*(Actor::TraceHitInfo*)&params[28] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayImpactEffects(Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42374);
			byte params[12] = { NULL };
			*(Vector*)params = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckBulletWhip(Vector FireDir, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42389);
			byte params[24] = { NULL };
			*(Vector*)params = FireDir;
			*(Vector*)&params[12] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetWeaponOverlayFlags(class UTPawn* OwnerPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42394);
			byte params[4] = { NULL };
			*(class UTPawn**)params = OwnerPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangeVisibility(bool bIsVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42400);
			byte params[4] = { NULL };
			*(bool*)params = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FireModeUpdated(byte FiringMode, bool bViaReplication)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42402);
			byte params[5] = { NULL };
			*params = FiringMode;
			*(bool*)&params[4] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Vector GetEffectLocation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42405);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
