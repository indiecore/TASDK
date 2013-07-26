#pragma once
#include "GameFramework.GamePawn.h"
#include "Core.Object.Vector.h"
#include "Engine.AnimNodeAimOffset.h"
#include "Core.Object.Vector2D.h"
#include "Core.Object.LinearColor.h"
#include "Engine.SkelControlLimb.h"
#include "Engine.SkelControlFootPlacement.h"
#include "Engine.SoundCue.h"
#include "Core.Object.Rotator.h"
#include "GameFramework.GameSkelCtrl_Recoil.h"
#include "Engine.SkelControlSingleBone.h"
#include "Engine.MaterialInterface.h"
#include "Engine.Material.h"
#include "UDKBase.UDKPawn.DrivenWeaponPawnInfo.h"
#include "UDKBase.UDKPawn.UTTakeHitInfo.h"
#include "UDKBase.UDKPawn.PlayEmoteInfo.h"
#include "Engine.Actor.h"
#include "UDKBase.UDKCarriedObject.h"
#include "Engine.PlayerController.h"
#include "Engine.Canvas.h"
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
		ADD_STRUCT(::VectorProperty, HUDLocation, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, CurrentSkelAim, 0xFFFFFFFF)
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
		ADD_STRUCT(::RotatorProperty, CompressedBodyMatColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, BodyMatColor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClientBodyMatDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RemainingBodyMatDuration, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, CurrentBodyMatColor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BodyMatFadeDuration, 0xFFFFFFFF)
		ADD_OBJECT(GameSkelCtrl_Recoil, RightRecoilNode)
		ADD_OBJECT(GameSkelCtrl_Recoil, LeftRecoilNode)
		ADD_OBJECT(GameSkelCtrl_Recoil, GunRecoilNode)
		ADD_OBJECT(AnimNodeAimOffset, AimNode)
		ADD_OBJECT(SkelControlSingleBone, RootRotControl)
		ADD_OBJECT(MaterialInterface, OverlayMaterialInstance)
		ADD_OBJECT(Material, ReplicatedBodyMaterial)
		ADD_OBJECT(SoundCue, WeaponAmbientSoundCue)
		ADD_STRUCT(::NonArithmeticProperty<DrivenWeaponPawnInfo>, DrivenWeaponPawn, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, PawnAmbientSoundCue)
		ADD_VAR(::FloatProperty, OldZ, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, MeshTranslationOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SmoothNetUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NoSmoothNetUpdateDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxSmoothNetUpdateDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HeadScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FireRateMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastTakeHitTimeout, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<UTTakeHitInfo>, LastTakeHitInfo, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, WeaponOverlayFlags, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, BigTeleportCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinTimeBetweenEmotes, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastEmoteTime, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<PlayEmoteInfo>, EmoteRepInfo, 0xFFFFFFFF)
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
		void GetBoundingCylinder(float& CollisionRadius, float& CollisionHeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.GetBoundingCylinder");
			byte* params = (byte*)malloc(8);
			*(float*)params = CollisionRadius;
			*(float*)(params + 4) = CollisionHeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			CollisionRadius = *(float*)params;
			CollisionHeight = *(float*)(params + 4);
			free(params);
		}
		void RestorePreRagdollCollisionComponent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.RestorePreRagdollCollisionComponent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnsureOverlayComponentLast()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.EnsureOverlayComponentLast");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Vector GetTargetLocation(class Actor* RequestedBy, bool bRequestAlternateLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.GetTargetLocation");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = RequestedBy;
			*(bool*)(params + 4) = bRequestAlternateLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 8);
			free(params);
			return returnVal;
		}
		bool IsInvisible()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.IsInvisible");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void HoldGameObject(class UDKCarriedObject* UDKGameObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.HoldGameObject");
			byte* params = (byte*)malloc(4);
			*(class UDKCarriedObject**)params = UDKGameObj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StoppedFalling()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.StoppedFalling");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndCrouch(float HeightAdjust)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.EndCrouch");
			byte* params = (byte*)malloc(4);
			*(float*)params = HeightAdjust;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartCrouch(float HeightAdjust)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.StartCrouch");
			byte* params = (byte*)malloc(4);
			*(float*)params = HeightAdjust;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool SuggestJumpVelocity(Vector& JumpVelocity, Vector Destination, Vector Start, bool bRequireFallLanding)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.SuggestJumpVelocity");
			byte* params = (byte*)malloc(44);
			*(Vector*)params = JumpVelocity;
			*(Vector*)(params + 12) = Destination;
			*(Vector*)(params + 24) = Start;
			*(bool*)(params + 36) = bRequireFallLanding;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			JumpVelocity = *(Vector*)params;
			auto returnVal = *(bool*)(params + 40);
			free(params);
			return returnVal;
		}
		void SetHUDLocation(Vector NewHUDLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.SetHUDLocation");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = NewHUDLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NativePostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.NativePostRenderFor");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetWeaponAttachmentVisibility(bool bAttachmentVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.SetWeaponAttachmentVisibility");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bAttachmentVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetHandIKEnabled(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.SetHandIKEnabled");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartFeignDeathRecoveryAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.StartFeignDeathRecoveryAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeHitBlendedOut()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.TakeHitBlendedOut");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateEyeHeight(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.UpdateEyeHeight");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StuckFalling()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.StuckFalling");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
