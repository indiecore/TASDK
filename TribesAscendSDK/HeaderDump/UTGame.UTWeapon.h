#pragma once
#include "Engine.SoundCue.h"
#include "UDKBase.UDKWeapon.h"
#include "Engine.UIRoot.TextureCoordinates.h"
#include "Engine.Texture2D.h"
#include "UDKBase.UDKPawn.h"
#include "Core.Object.Color.h"
#include "Engine.ForceFeedbackWaveform.h"
#include "UDKBase.UDKPlayerController.ObjectiveAnnouncementInfo.h"
#include "Engine.ParticleSystem.h"
#include "Engine.AnimSet.h"
#include "Core.Object.Vector.h"
#include "Core.Object.Rotator.h"
#include "Core.Object.InterpCurveFloat.h"
#include "Core.Object.Vector2D.h"
#include "Engine.Canvas.h"
#include "Engine.Material.h"
#include "Engine.HUD.h"
#include "Engine.Actor.ImpactInfo.h"
#include "Engine.Controller.h"
#include "Engine.Weapon.h"
#include "Engine.Pawn.h"
#include "Engine.Actor.h"
#include "Engine.Projectile.h"
#include "UTGame.UTPlayerController.h"
#include "Engine.AnimNodeSequence.h"
#include "UTGame.UTPawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTWeapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTWeapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTWeapon." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTWeapon : public UDKWeapon
	{
	public:
		ADD_VAR(::ByteProperty, AmmoDisplayType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, InventoryGroup, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, UseHintString, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bExportMenuData, 0x1)
		ADD_VAR(::BoolProperty, bAllowFiringWithoutController, 0x40000)
		ADD_VAR(::BoolProperty, bSmallWeapons, 0x8)
		ADD_VAR(::BoolProperty, bUseCustomCoordinates, 0x4)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, SimpleCrossHairCoordinates, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, CustomCrosshairCoordinates, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastHitEnemyTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InventoryWeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GroupWeight, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, CrossHairCoordinates, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CrosshairScaling, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, CrosshairImage)
		ADD_STRUCT(::NonArithmeticProperty<Color>, CrosshairColor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWasLocked, 0x2)
		ADD_VAR(::FloatProperty, LockedStartTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentLockedScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StartLockedScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LockedScaleTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FinalLockedScale, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, LockedCrossHairCoordinates, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ZoomedRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ZoomedTargetFOV, 0xFFFFFFFF)
		ADD_OBJECT(AnimSet, ArmsAnimSet)
		ADD_OBJECT(ForceFeedbackWaveform, WeaponFireWaveForm)
		ADD_VAR(::BoolProperty, bSuppressSounds, 0x40)
		ADD_VAR(::BoolProperty, bMuzzleFlashPSCLoops, 0x400)
		ADD_OBJECT(ScriptClass, MuzzleFlashLightClass)
		ADD_VAR(::NameProperty, MuzzleFlashSocket, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShowAltMuzzlePSCWhenWeaponHidden, 0x200)
		ADD_OBJECT(ParticleSystem, MuzzleFlashAltPSCTemplate)
		ADD_VAR(::BoolProperty, bMuzzleFlashAttached, 0x800)
		ADD_OBJECT(ParticleSystem, MuzzleFlashPSCTemplate)
		ADD_VAR(::FloatProperty, MuzzleFlashDuration, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, WeaponPutDownAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ArmsPutDownAnim, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, WeaponPutDownSnd)
		ADD_VAR(::NameProperty, WeaponEquipAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ArmsEquipAnim, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, WeaponEquipSnd)
		ADD_VAR(::BoolProperty, bPendingShow, 0x100)
		ADD_OBJECT(ScriptClass, AttachmentClass)
		ADD_STRUCT(::NonArithmeticProperty<Color>, MuzzleFlashColor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForceHidden, 0x200000)
		ADD_STRUCT(::VectorProperty, HiddenWeaponsOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PlayerViewOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, SmallWeaponsOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WideScreenOffsetScaling, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BobDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, JumpDamping, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, LastRotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxYawLag, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxPitchLag, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastRotUpdate, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, WidescreenRotationOffset, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, OldRotDiff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldLeadMag, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldMaxDiff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RotChgSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ReturnChgSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentRating, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, AmmoPickupClass)
		ADD_VAR(::IntProperty, MaxAmmoCount, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSplashJump, 0x1000)
		ADD_VAR(::BoolProperty, bUsingAimingHelp, 0x20000)
		ADD_VAR(::FloatProperty, AimingHelpRadius, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ZoomedFireModeNum, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, ZoomInSound)
		ADD_OBJECT(SoundCue, ZoomOutSound)
		ADD_VAR(::FloatProperty, SwitchAbortTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ProjectileSpawnOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponCanvasXPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponCanvasYPct, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, IconCoordinates, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSuperWeapon, 0x10)
		ADD_VAR(::BoolProperty, bNeverForwardPendingFire, 0x20)
		ADD_VAR(::BoolProperty, bUsesOffhand, 0x80)
		ADD_VAR(::BoolProperty, bRecommendSplashDamage, 0x2000)
		ADD_VAR(::BoolProperty, bSniping, 0x4000)
		ADD_VAR(::BoolProperty, bFastRepeater, 0x8000)
		ADD_VAR(::BoolProperty, bLockedAimWhileFiring, 0x10000)
		ADD_VAR(::BoolProperty, bTargetFrictionEnabled, 0x80000)
		ADD_VAR(::BoolProperty, bTargetAdhesionEnabled, 0x100000)
		ADD_VAR(::BoolProperty, bHasLocationSpeech, 0x400000)
		ADD_VAR(::IntProperty, LockerAmmoCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IconX, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IconY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IconWidth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IconHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DroppedPickupOffsetZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ZoomFadeTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PivotTranslation, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, WeaponColor, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, LockerRotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LockerOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, aimerror, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ObjectiveAnnouncementInfo>, NeedToPickUpAnnouncement, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ZoomedTurnSpeedScalePct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetFrictionDistanceMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetFrictionDistancePeak, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetFrictionDistanceMax, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<InterpCurveFloat>, TargetFrictionDistanceCurve, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, TargetFrictionMultiplierRange, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetFrictionPeakRadiusScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetFrictionPeakHeightScale, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, TargetFrictionOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetFrictionZoomedBoostValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetAdhesionTimeMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetAdhesionDistanceMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetAdhesionAimDistY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetAdhesionAimDistZ, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, TargetAdhesionScaleRange, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetAdhesionScaleAmountMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetAdhesionTargetVelocityMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetAdhesionPlayerVelocityMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetAdhesionZoomedBoostValue, 0xFFFFFFFF)
		int GetAmmoCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.GetAmmoCount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool CoversScreenSpace(Vector ScreenLoc, class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.CoversScreenSpace");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = ScreenLoc;
			*(class Canvas**)(params + 12) = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		float GetPowerPerc()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.GetPowerPerc");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float DesireAmmo(bool bDetour)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.DesireAmmo");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bDetour;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void ServerStartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.ServerStartFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdjustWeaponTimingForConsole()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.AdjustWeaponTimingForConsole");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateOverlayMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.CreateOverlayMesh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CalcInventoryWeight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.CalcInventoryWeight");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldSwitchTo(class UTWeapon* InWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.ShouldSwitchTo");
			byte* params = (byte*)malloc(8);
			*(class UTWeapon**)params = InWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetSkin(class Material* NewMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.SetSkin");
			byte* params = (byte*)malloc(4);
			*(class Material**)params = NewMaterial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ActiveRenderOverlays(class HUD* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.ActiveRenderOverlays");
			byte* params = (byte*)malloc(4);
			*(class HUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawWeaponCrosshair(class HUD* HUD)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.DrawWeaponCrosshair");
			byte* params = (byte*)malloc(4);
			*(class HUD**)params = HUD;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawLockedOn(class HUD* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.DrawLockedOn");
			byte* params = (byte*)malloc(4);
			*(class HUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		float GetFireInterval(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.GetFireInterval");
			byte* params = (byte*)malloc(5);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void PlayArmAnimation(ScriptName Sequence, float fDesiredDuration, bool OffHand, bool bLoop, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.PlayArmAnimation");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = Sequence;
			*(float*)(params + 8) = fDesiredDuration;
			*(bool*)(params + 12) = OffHand;
			*(bool*)(params + 16) = bLoop;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 20) = SkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayWeaponAnimation(ScriptName Sequence, float fDesiredDuration, bool bLoop, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.PlayWeaponAnimation");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = Sequence;
			*(float*)(params + 8) = fDesiredDuration;
			*(bool*)(params + 12) = bLoop;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 16) = SkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayFireEffects(byte FireModeNum, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.PlayFireEffects");
			byte* params = (byte*)malloc(13);
			*params = FireModeNum;
			*(Vector*)(params + 4) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopFireEffects(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.StopFireEffects");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShakeView()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.ShakeView");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WeaponCalcCamera(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.WeaponCalcCamera");
			byte* params = (byte*)malloc(28);
			*(float*)params = fDeltaTime;
			*(Vector*)(params + 4) = out_CamLoc;
			*(Rotator*)(params + 16) = out_CamRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_CamLoc = *(Vector*)(params + 4);
			out_CamRot = *(Rotator*)(params + 16);
			free(params);
		}
		void WeaponPlaySound(class SoundCue* Sound, float NoiseLoudness, bool bStopWhenOwnerDestroyed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.WeaponPlaySound");
			byte* params = (byte*)malloc(12);
			*(class SoundCue**)params = Sound;
			*(float*)(params + 4) = NoiseLoudness;
			*(bool*)(params + 8) = bStopWhenOwnerDestroyed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayFiringSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.PlayFiringSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MuzzleFlashTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.MuzzleFlashTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CauseMuzzleFlashLight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.CauseMuzzleFlashLight");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CauseMuzzleFlash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.CauseMuzzleFlash");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopMuzzleFlash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.StopMuzzleFlash");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TimeWeaponPutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.TimeWeaponPutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayWeaponPutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.PlayWeaponPutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TimeWeaponEquipping()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.TimeWeaponEquipping");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetEquipTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.GetEquipTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void PlayWeaponEquip()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.PlayWeaponEquip");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AttachWeaponTo(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshCpnt, ScriptName SocketName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.AttachWeaponTo");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MeshCpnt;
			*(ScriptName*)(params + 4) = SocketName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMuzzleFlashParams(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.SetMuzzleFlashParams");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AttachMuzzleFlash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.AttachMuzzleFlash");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DetachWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.DetachWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DetachMuzzleFlash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.DetachMuzzleFlash");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChangeVisibility(bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.ChangeVisibility");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PerformWeaponChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.PerformWeaponChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetViewAxes(Vector& XAxis, Vector& YAxis, Vector& ZAxis)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.GetViewAxes");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = XAxis;
			*(Vector*)(params + 12) = YAxis;
			*(Vector*)(params + 24) = ZAxis;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			XAxis = *(Vector*)params;
			YAxis = *(Vector*)(params + 12);
			ZAxis = *(Vector*)(params + 24);
			free(params);
		}
		void ServerReselectWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.ServerReselectWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanThrow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.CanThrow");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		byte GetHand()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.GetHand");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		void SetPosition(class UDKPawn* Holder, float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.SetPosition");
			byte* params = (byte*)malloc(8);
			*(class UDKPawn**)params = Holder;
			*(float*)(params + 4) = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldLagRot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.ShouldLagRot");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		int LagRot(int NewValue, int LastValue, float MaxDiff, int Index, float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.LagRot");
			byte* params = (byte*)malloc(24);
			*(int*)params = NewValue;
			*(int*)(params + 4) = LastValue;
			*(float*)(params + 8) = MaxDiff;
			*(int*)(params + 12) = Index;
			*(float*)(params + 16) = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 20);
			free(params);
			return returnVal;
		}
		void AdjustPlayerDamage(int& Damage, class Controller* InstigatedBy, Vector HitLocation, Vector& Momentum, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.AdjustPlayerDamage");
			byte* params = (byte*)malloc(36);
			*(int*)params = Damage;
			*(class Controller**)(params + 4) = InstigatedBy;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Damage = *(int*)params;
			Momentum = *(Vector*)(params + 20);
			free(params);
		}
		float RelativeStrengthVersus(class Pawn* P, float Dist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.RelativeStrengthVersus");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = P;
			*(float*)(params + 4) = Dist;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		float GetWeaponRating()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.GetWeaponRating");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		bool CanAttack(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.CanAttack");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		float BotDesireability(class Actor* PickupHolder, class Pawn* P, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.BotDesireability");
			byte* params = (byte*)malloc(16);
			*(class Actor**)params = PickupHolder;
			*(class Pawn**)(params + 4) = P;
			*(class Controller**)(params + 8) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		bool AmmoMaxed(int Mode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.AmmoMaxed");
			byte* params = (byte*)malloc(8);
			*(int*)params = Mode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		float GetDamageRadius()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.GetDamageRadius");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		bool CanHeal(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.CanHeal");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		float GetOptimalRangeFor(class Actor* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.GetOptimalRangeFor");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		bool FireOnRelease()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.FireOnRelease");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool FocusOnLeader(bool bLeaderFiring)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.FocusOnLeader");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bLeaderFiring;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool RecommendRangedAttack()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.RecommendRangedAttack");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		float SuggestAttackStyle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.SuggestAttackStyle");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float SuggestDefenseStyle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.SuggestDefenseStyle");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float RangedAttackTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.RangedAttackTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		bool SplashJump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.SplashJump");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool ShouldFireWithoutTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.ShouldFireWithoutTarget");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		byte BestMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.BestMode");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		bool IsFullyCharged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.IsFullyCharged");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool ReadyToFire(bool bFinished)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.ReadyToFire");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bFinished;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool StillFiring(byte FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.StillFiring");
			byte* params = (byte*)malloc(5);
			*params = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ConsumeAmmo(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.ConsumeAmmo");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int AddAmmo(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.AddAmmo");
			byte* params = (byte*)malloc(8);
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool HasAmmo(byte FireModeNum, int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.HasAmmo");
			byte* params = (byte*)malloc(9);
			*params = FireModeNum;
			*(int*)(params + 4) = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool HasAnyAmmo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.HasAnyAmmo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool NeedAmmo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.NeedAmmo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void Loaded(bool bUseWeaponMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.Loaded");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bUseWeaponMax;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool DenyPickupQuery(ScriptClass* ItemClass, class Actor* Pickup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.DenyPickupQuery");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = ItemClass;
			*(class Actor**)(params + 4) = Pickup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void WeaponEmpty()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.WeaponEmpty");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool bReadyToFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.bReadyToFire");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		Vector InstantFireStartTrace()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.InstantFireStartTrace");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		Vector InstantFireEndTrace(Vector StartTrace)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.InstantFireEndTrace");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = StartTrace;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		void InstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.InstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ImpactInfo InstantAimHelp(Vector StartTrace, Vector EndTrace, ImpactInfo RealImpact)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.InstantAimHelp");
			byte* params = (byte*)malloc(184);
			*(Vector*)params = StartTrace;
			*(Vector*)(params + 12) = EndTrace;
			*(ImpactInfo*)(params + 24) = RealImpact;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ImpactInfo*)(params + 104);
			free(params);
			return returnVal;
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.ProjectileFire");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Projectile**)params;
			free(params);
			return returnVal;
		}
		void ProcessInstantHit(byte FiringMode, ImpactInfo Impact, int NumHits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.ProcessInstantHit");
			byte* params = (byte*)malloc(85);
			*params = FiringMode;
			*(ImpactInfo*)(params + 4) = Impact;
			*(int*)(params + 84) = NumHits;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetZoomedState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.GetZoomedState");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		bool CheckZoom(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.CheckZoom");
			byte* params = (byte*)malloc(5);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void StartZoom(class UTPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.StartZoom");
			byte* params = (byte*)malloc(4);
			*(class UTPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndZoom(class UTPlayerController* PC, bool bReturningTo3P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.EndZoom");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerController**)params = PC;
			*(bool*)(params + 4) = bReturningTo3P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientEndFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.ClientEndFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.EndFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendToFiringState(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.SendToFiringState");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientWeaponSet(bool bOptionalSet, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.ClientWeaponSet");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bOptionalSet;
			*(bool*)(params + 4) = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.FireAmmunition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreloadTextures(bool bForcePreload)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.PreloadTextures");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bForcePreload;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AllowSwitchTo(class Weapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.AllowSwitchTo");
			byte* params = (byte*)malloc(8);
			*(class Weapon**)params = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool TryPutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.TryPutDown");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void FiringPutDownWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.FiringPutDownWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Vector GetPhysicalFireStartLoc(Vector AimDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.GetPhysicalFireStartLoc");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = AimDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		Vector GetEffectLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.GetEffectLocation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		void RefireCheckTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.RefireCheckTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetupArmsAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.SetupArmsAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class AnimNodeSequence* GetArmAnimNodeSeq()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.GetArmAnimNodeSeq");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class AnimNodeSequence**)params;
			free(params);
			return returnVal;
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetWeaponOverlayFlags(class UTPawn* OwnerPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.SetWeaponOverlayFlags");
			byte* params = (byte*)malloc(4);
			*(class UTPawn**)params = OwnerPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float DetourWeight(class Pawn* Other, float PathWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.DetourWeight");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = Other;
			*(float*)(params + 4) = PathWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		bool RecommendLongRangedAttack()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.RecommendLongRangedAttack");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ThrottleLook(float& aTurn, float& aLookUp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.ThrottleLook");
			byte* params = (byte*)malloc(8);
			*(float*)params = aTurn;
			*(float*)(params + 4) = aLookUp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			aTurn = *(float*)params;
			aLookUp = *(float*)(params + 4);
			free(params);
		}
		void Activate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.Activate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DropFrom(Vector StartLocation, Vector StartVelocity)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.DropFrom");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = StartLocation;
			*(Vector*)(params + 12) = StartVelocity;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientWeaponThrown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.ClientWeaponThrown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanViewAccelerationWhenFiring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.CanViewAccelerationWhenFiring");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void HolderEnteredVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.HolderEnteredVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HolderExitedVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.HolderExitedVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawKillIcon(class Canvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.DrawKillIcon");
			byte* params = (byte*)malloc(20);
			*(class Canvas**)params = Canvas;
			*(float*)(params + 4) = ScreenX;
			*(float*)(params + 8) = ScreenY;
			*(float*)(params + 12) = HUDScaleX;
			*(float*)(params + 16) = HUDScaleY;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool EnableFriendlyWarningCrosshair()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeapon.EnableFriendlyWarningCrosshair");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
