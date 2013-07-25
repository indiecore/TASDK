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
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'CheckToForceRefPose'
		// Here lies the not-yet-implemented method 'CreateOverlayMesh'
		// Here lies the not-yet-implemented method 'SetSkin'
		// Here lies the not-yet-implemented method 'SetMuzzleFlashParams'
		// Here lies the not-yet-implemented method 'AttachTo'
		// Here lies the not-yet-implemented method 'SetPuttingDownWeapon'
		// Here lies the not-yet-implemented method 'DetachFrom'
		// Here lies the not-yet-implemented method 'MuzzleFlashTimer'
		// Here lies the not-yet-implemented method 'CauseMuzzleFlash'
		// Here lies the not-yet-implemented method 'StopMuzzleFlash'
		// Here lies the not-yet-implemented method 'FirstPersonFireEffects'
		// Here lies the not-yet-implemented method 'StopFirstPersonFireEffects'
		// Here lies the not-yet-implemented method 'ThirdPersonFireEffects'
		// Here lies the not-yet-implemented method 'StopThirdPersonFireEffects'
		// Here lies the not-yet-implemented method 'GetImpactEffect'
		// Here lies the not-yet-implemented method 'AllowImpactEffects'
		// Here lies the not-yet-implemented method 'SetImpactedActor'
		// Here lies the not-yet-implemented method 'PlayImpactEffects'
		// Here lies the not-yet-implemented method 'CheckBulletWhip'
		// Here lies the not-yet-implemented method 'SetWeaponOverlayFlags'
		// Here lies the not-yet-implemented method 'ChangeVisibility'
		// Here lies the not-yet-implemented method 'FireModeUpdated'
		// Here lies the not-yet-implemented method 'GetEffectLocation'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
