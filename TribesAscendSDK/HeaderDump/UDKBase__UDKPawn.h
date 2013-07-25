#pragma once
#include "Engine__SoundCue.h"
#include "UDKBase__UDKCarriedObject.h"
#include "GameFramework__GamePawn.h"
#include "Engine__Material.h"
#include "Engine__AnimNodeAimOffset.h"
#include "Engine__SkelControlSingleBone.h"
#include "Engine__SkelControlLimb.h"
#include "Engine__SkelControlFootPlacement.h"
#include "GameFramework__GameSkelCtrl_Recoil.h"
#include "Engine__MaterialInterface.h"
#include "Engine__Actor.h"
#include "Engine__PlayerController.h"
#include "Engine__Canvas.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKPawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKPawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKPawn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKPawn : public GamePawn
	{
	public:
		ADD_VAR(::BoolProperty, bNotifyStopFalling, 0x40)
		ADD_VAR(::BoolProperty, bReadyToDoubleJump, 0x1)
		ADD_STRUCT(::VectorProperty, HUDLocation, 0xFFFFFFFF
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'CurrentSkelAim'!
		ADD_VAR(::IntProperty, MaxYawAim, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RootYawSpeed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RootYaw, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TakeHitPhysicsBlendOutSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CrouchMeshZOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SwimmingZOffsetSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SwimmingZOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FeignDeathPhysicsBlendOutSpeed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxLeanRoll, 0xFFFFFFFF)
		ADD_OBJECT(AnimNodeAimOffset, FlyingDirOffset)
		ADD_VAR(::FloatProperty, SlopeBoostFriction, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StartedFallingTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TeamBeaconMaxDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastPostRenderTraceTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SaturationParameterName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, DamageParameterName, 0xFFFFFFFF)
		ADD_OBJECT(SkelControlLimb, RightHandIK)
		ADD_OBJECT(SkelControlLimb, LeftHandIK)
		ADD_OBJECT(SkelControlFootPlacement, RightLegControl)
		ADD_OBJECT(SkelControlFootPlacement, LeftLegControl)
		ADD_VAR(::FloatProperty, MaxFootPlacementDistSquared, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ZSmoothingRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldLocationZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CrouchTranslationOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BaseTranslationOffset, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, RightFootControlName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, LeftFootControlName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, RightFootBone, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, LeftFootBone, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FallSpeedThreshold, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, FallImpactSound)
		ADD_VAR(::NameProperty, TorsoBoneName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StartFallImpactTime, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, CompressedBodyMatColor, 0xFFFFFFFF
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'BodyMatColor'!
		ADD_VAR(::FloatProperty, ClientBodyMatDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RemainingBodyMatDuration, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'CurrentBodyMatColor'!
		ADD_VAR(::FloatProperty, BodyMatFadeDuration, 0xFFFFFFFF)
		ADD_OBJECT(GameSkelCtrl_Recoil, RightRecoilNode)
		ADD_OBJECT(GameSkelCtrl_Recoil, LeftRecoilNode)
		ADD_OBJECT(GameSkelCtrl_Recoil, GunRecoilNode)
		ADD_OBJECT(AnimNodeAimOffset, AimNode)
		ADD_OBJECT(SkelControlSingleBone, RootRotControl)
		ADD_OBJECT(MaterialInterface, OverlayMaterialInstance)
		ADD_OBJECT(Material, ReplicatedBodyMaterial)
		ADD_OBJECT(SoundCue, WeaponAmbientSoundCue)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.DrivenWeaponPawnInfo' for the property named 'DrivenWeaponPawn'!
		ADD_OBJECT(SoundCue, PawnAmbientSoundCue)
		ADD_VAR(::FloatProperty, OldZ, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, MeshTranslationOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, SmoothNetUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NoSmoothNetUpdateDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxSmoothNetUpdateDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HeadScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FireRateMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastTakeHitTimeout, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.UTTakeHitInfo' for the property named 'LastTakeHitInfo'!
		ADD_VAR(::ByteProperty, WeaponOverlayFlags, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, BigTeleportCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinTimeBetweenEmotes, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastEmoteTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.PlayEmoteInfo' for the property named 'EmoteRepInfo'!
		ADD_VAR(::FloatProperty, CustomGravityScaling, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MultiJumpBoost, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxMultiJump, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MultiJumpRemaining, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDoubleJumpHeight, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bTearOffGibs, 0x10000)
		ADD_VAR(::BoolProperty, bUpdateEyeheight, 0x8000)
		ADD_VAR(::BoolProperty, bBlendOutTakeHitPhysics, 0x4000)
		ADD_VAR(::BoolProperty, bPostRenderOtherTeam, 0x2000)
		ADD_VAR(::BoolProperty, bEnableFootPlacement, 0x1000)
		ADD_VAR(::BoolProperty, bCanPlayFallingImpacts, 0x800)
		ADD_VAR(::BoolProperty, bPlayingFeignDeathRecovery, 0x400)
		ADD_VAR(::BoolProperty, bPuttingDownWeapon, 0x200)
		ADD_VAR(::BoolProperty, bSmoothNetUpdates, 0x100)
		ADD_VAR(::BoolProperty, bIsInvisible, 0x80)
		ADD_VAR(::BoolProperty, bFeigningDeath, 0x20)
		ADD_VAR(::BoolProperty, bIsHoverboardAnimPawn, 0x10)
		ADD_VAR(::BoolProperty, bNoJumpAdjust, 0x8)
		ADD_VAR(::BoolProperty, bCanDoubleJump, 0x4)
		ADD_VAR(::BoolProperty, bRequiresDoubleJump, 0x2)
		// Here lies the not-yet-implemented method 'GetBoundingCylinder'
		// Here lies the not-yet-implemented method 'RestorePreRagdollCollisionComponent'
		// Here lies the not-yet-implemented method 'EnsureOverlayComponentLast'
		// Here lies the not-yet-implemented method 'GetTargetLocation'
		// Here lies the not-yet-implemented method 'IsInvisible'
		// Here lies the not-yet-implemented method 'HoldGameObject'
		// Here lies the not-yet-implemented method 'StoppedFalling'
		// Here lies the not-yet-implemented method 'EndCrouch'
		// Here lies the not-yet-implemented method 'StartCrouch'
		// Here lies the not-yet-implemented method 'SuggestJumpVelocity'
		// Here lies the not-yet-implemented method 'SetHUDLocation'
		// Here lies the not-yet-implemented method 'NativePostRenderFor'
		// Here lies the not-yet-implemented method 'SetWeaponAttachmentVisibility'
		// Here lies the not-yet-implemented method 'SetHandIKEnabled'
		// Here lies the not-yet-implemented method 'StartFeignDeathRecoveryAnim'
		// Here lies the not-yet-implemented method 'TakeHitBlendedOut'
		// Here lies the not-yet-implemented method 'UpdateEyeHeight'
		// Here lies the not-yet-implemented method 'StuckFalling'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
