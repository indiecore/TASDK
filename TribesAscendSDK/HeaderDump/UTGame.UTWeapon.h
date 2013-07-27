#pragma once
#include "Engine.SoundCue.h"
#include "UDKBase.UDKWeapon.h"
#include "UTGame.UTPlayerController.h"
#include "Engine.CameraAnim.h"
#include "Engine.UIRoot.h"
#include "Engine.Texture2D.h"
#include "Core.Object.h"
#include "Engine.ParticleSystem.h"
#include "Engine.AnimSet.h"
#include "UDKBase.UDKPawn.h"
#include "Engine.ForceFeedbackWaveform.h"
#include "UDKBase.UDKPlayerController.h"
#include "Engine.SoundNodeWave.h"
#include "Engine.Canvas.h"
#include "Engine.Material.h"
#include "Engine.HUD.h"
#include "Engine.Controller.h"
#include "Engine.Weapon.h"
#include "Engine.Pawn.h"
#include "Engine.Actor.h"
#include "Engine.Projectile.h"
#include "Engine.AnimNodeSequence.h"
#include "UTGame.UTPawn.h"
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
	class UTWeapon : public UDKWeapon
	{
	public:
		enum EZoomState : byte
		{
			ZST_NotZoomed = 0,
			ZST_ZoomingOut = 1,
			ZST_ZoomingIn = 2,
			ZST_Zoomed = 3,
			ZST_MAX = 4,
		};
		enum AmmoWidgetDisplayStyle : byte
		{
			EAWDS_Numeric = 0,
			EAWDS_BarGraph = 1,
			EAWDS_Both = 2,
			EAWDS_None = 3,
			EAWDS_MAX = 4,
		};
		ADD_STRUCT(UTWeapon::AmmoWidgetDisplayStyle, AmmoDisplayType, 970)
		ADD_STRUCT(byte, InventoryGroup, 969)
		ADD_STRUCT(ScriptString*, UseHintString, 1460)
		ADD_BOOL(bExportMenuData, 748, 0x1)
		ADD_BOOL(bAllowFiringWithoutController, 748, 0x40000)
		ADD_BOOL(bSmallWeapons, 748, 0x8)
		ADD_BOOL(bUseCustomCoordinates, 748, 0x4)
		ADD_STRUCT(UIRoot::TextureCoordinates, SimpleCrossHairCoordinates, 868)
		ADD_STRUCT(UIRoot::TextureCoordinates, CustomCrosshairCoordinates, 936)
		ADD_STRUCT(float, LastHitEnemyTime, 924)
		ADD_STRUCT(float, InventoryWeight, 1012)
		ADD_STRUCT(float, GroupWeight, 1008)
		ADD_STRUCT(UIRoot::TextureCoordinates, CrossHairCoordinates, 852)
		ADD_STRUCT(float, CrosshairScaling, 932)
		ADD_OBJECT(Texture2D, CrosshairImage, 884)
		ADD_STRUCT(Object::Color, CrosshairColor, 928)
		ADD_BOOL(bWasLocked, 748, 0x2)
		ADD_STRUCT(float, LockedStartTime, 920)
		ADD_STRUCT(float, CurrentLockedScale, 904)
		ADD_STRUCT(float, StartLockedScale, 908)
		ADD_STRUCT(float, LockedScaleTime, 916)
		ADD_STRUCT(float, FinalLockedScale, 912)
		ADD_STRUCT(UIRoot::TextureCoordinates, LockedCrossHairCoordinates, 888)
		ADD_STRUCT(float, ZoomedRate, 976)
		ADD_STRUCT(float, ZoomedTargetFOV, 972)
		ADD_OBJECT(AnimSet, ArmsAnimSet, 1040)
		ADD_STRUCT(ScriptArray<ScriptName>, WeaponFireAnim, 1016)
		ADD_STRUCT(ScriptArray<ScriptName>, ArmFireAnim, 1028)
		ADD_STRUCT(ScriptArray<class CameraAnim*>, FireCameraAnim, 788)
		ADD_OBJECT(ForceFeedbackWaveform, WeaponFireWaveForm, 800)
		ADD_BOOL(bSuppressSounds, 748, 0x40)
		ADD_STRUCT(ScriptArray<class SoundCue*>, WeaponFireSnd, 1100)
		ADD_BOOL(bMuzzleFlashPSCLoops, 748, 0x400)
		ADD_OBJECT(ScriptClass, MuzzleFlashLightClass, 1224)
		ADD_STRUCT(ScriptName, MuzzleFlashSocket, 1196)
		ADD_BOOL(bShowAltMuzzlePSCWhenWeaponHidden, 748, 0x200)
		ADD_OBJECT(ParticleSystem, MuzzleFlashAltPSCTemplate, 1212)
		ADD_BOOL(bMuzzleFlashAttached, 748, 0x800)
		ADD_OBJECT(ParticleSystem, MuzzleFlashPSCTemplate, 1208)
		ADD_STRUCT(float, MuzzleFlashDuration, 1228)
		ADD_STRUCT(ScriptName, WeaponPutDownAnim, 1044)
		ADD_STRUCT(ScriptName, ArmsPutDownAnim, 1052)
		ADD_OBJECT(SoundCue, WeaponPutDownSnd, 1112)
		ADD_STRUCT(ScriptName, WeaponEquipAnim, 1060)
		ADD_STRUCT(ScriptName, ArmsEquipAnim, 1068)
		ADD_OBJECT(SoundCue, WeaponEquipSnd, 1116)
		ADD_BOOL(bPendingShow, 748, 0x100)
		ADD_OBJECT(ScriptClass, AttachmentClass, 992)
		ADD_STRUCT(Object::Color, MuzzleFlashColor, 1216)
		ADD_BOOL(bForceHidden, 748, 0x200000)
		ADD_STRUCT(Vector, HiddenWeaponsOffset, 1272)
		ADD_STRUCT(Vector, PlayerViewOffset, 1232)
		ADD_STRUCT(Vector, SmallWeaponsOffset, 1244)
		ADD_STRUCT(float, WideScreenOffsetScaling, 1256)
		ADD_STRUCT(float, BobDamping, 1120)
		ADD_STRUCT(float, JumpDamping, 1124)
		ADD_STRUCT(Rotator, LastRotation, 1140)
		ADD_STRUCT(float, MaxYawLag, 1132)
		ADD_STRUCT(float, MaxPitchLag, 1128)
		ADD_STRUCT(float, LastRotUpdate, 1136)
		ADD_STRUCT(Rotator, WidescreenRotationOffset, 1260)
		ADD_STRUCT(int, OldRotDiff, 1160)
		ADD_STRUCT(float, OldLeadMag, 1152)
		ADD_STRUCT(float, OldMaxDiff, 1168)
		ADD_STRUCT(float, RotChgSpeed, 1176)
		ADD_STRUCT(float, ReturnChgSpeed, 1180)
		ADD_STRUCT(float, CurrentRating, 1312)
		ADD_OBJECT(ScriptClass, AmmoPickupClass, 752)
		ADD_STRUCT(int, MaxAmmoCount, 760)
		ADD_BOOL(bSplashJump, 748, 0x1000)
		ADD_STRUCT(ScriptArray<byte>, bZoomedFireMode, 956)
		ADD_STRUCT(ScriptArray<int>, ShotCost, 764)
		ADD_BOOL(bUsingAimingHelp, 748, 0x20000)
		ADD_STRUCT(float, AimingHelpRadius, 1336)
		ADD_STRUCT(byte, ZoomedFireModeNum, 968)
		ADD_OBJECT(SoundCue, ZoomInSound, 984)
		ADD_OBJECT(SoundCue, ZoomOutSound, 988)
		ADD_STRUCT(float, SwitchAbortTime, 832)
		ADD_STRUCT(ScriptArray<float>, MinReloadPct, 776)
		ADD_STRUCT(float, ProjectileSpawnOffset, 1284)
		ADD_STRUCT(ScriptArray<ScriptName>, EffectSockets, 804)
		ADD_STRUCT(float, WeaponCanvasXPct, 1188)
		ADD_STRUCT(float, WeaponCanvasYPct, 1192)
		ADD_STRUCT(UIRoot::TextureCoordinates, IconCoordinates, 836)
		ADD_BOOL(bSuperWeapon, 748, 0x10)
		ADD_BOOL(bNeverForwardPendingFire, 748, 0x20)
		ADD_BOOL(bUsesOffhand, 748, 0x80)
		ADD_BOOL(bRecommendSplashDamage, 748, 0x2000)
		ADD_BOOL(bSniping, 748, 0x4000)
		ADD_BOOL(bFastRepeater, 748, 0x8000)
		ADD_BOOL(bLockedAimWhileFiring, 748, 0x10000)
		ADD_BOOL(bTargetFrictionEnabled, 748, 0x80000)
		ADD_BOOL(bTargetAdhesionEnabled, 748, 0x100000)
		ADD_BOOL(bHasLocationSpeech, 748, 0x400000)
		ADD_STRUCT(int, LockerAmmoCount, 756)
		ADD_STRUCT(int, IconX, 816)
		ADD_STRUCT(int, IconY, 820)
		ADD_STRUCT(int, IconWidth, 824)
		ADD_STRUCT(int, IconHeight, 828)
		ADD_STRUCT(float, DroppedPickupOffsetZ, 952)
		ADD_STRUCT(float, ZoomFadeTime, 980)
		ADD_STRUCT(Vector, PivotTranslation, 996)
		ADD_STRUCT(ScriptArray<ScriptName>, WeaponIdleAnims, 1076)
		ADD_STRUCT(ScriptArray<ScriptName>, ArmIdleAnims, 1088)
		ADD_STRUCT(Object::Color, WeaponColor, 1184)
		ADD_STRUCT(Rotator, LockerRotation, 1288)
		ADD_STRUCT(Vector, LockerOffset, 1300)
		ADD_STRUCT(float, aimerror, 1316)
		ADD_STRUCT(UDKPlayerController::ObjectiveAnnouncementInfo, NeedToPickUpAnnouncement, 1320)
		ADD_STRUCT(float, ZoomedTurnSpeedScalePct, 1344)
		ADD_STRUCT(float, TargetFrictionDistanceMin, 1348)
		ADD_STRUCT(float, TargetFrictionDistancePeak, 1352)
		ADD_STRUCT(float, TargetFrictionDistanceMax, 1356)
		ADD_STRUCT(Object::InterpCurveFloat, TargetFrictionDistanceCurve, 1360)
		ADD_STRUCT(Object::Vector2D, TargetFrictionMultiplierRange, 1376)
		ADD_STRUCT(float, TargetFrictionPeakRadiusScale, 1384)
		ADD_STRUCT(float, TargetFrictionPeakHeightScale, 1388)
		ADD_STRUCT(Vector, TargetFrictionOffset, 1392)
		ADD_STRUCT(float, TargetFrictionZoomedBoostValue, 1404)
		ADD_STRUCT(float, TargetAdhesionTimeMax, 1408)
		ADD_STRUCT(float, TargetAdhesionDistanceMax, 1412)
		ADD_STRUCT(float, TargetAdhesionAimDistY, 1416)
		ADD_STRUCT(float, TargetAdhesionAimDistZ, 1420)
		ADD_STRUCT(Object::Vector2D, TargetAdhesionScaleRange, 1424)
		ADD_STRUCT(float, TargetAdhesionScaleAmountMin, 1432)
		ADD_STRUCT(float, TargetAdhesionTargetVelocityMin, 1436)
		ADD_STRUCT(float, TargetAdhesionPlayerVelocityMin, 1440)
		ADD_STRUCT(float, TargetAdhesionZoomedBoostValue, 1444)
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, LocationSpeech, 1448)
		int GetAmmoCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37500);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool CoversScreenSpace(Vector ScreenLoc, class Canvas* Canvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39644);
			byte params[20] = { NULL };
			*(Vector*)params = ScreenLoc;
			*(class Canvas**)&params[12] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		float GetPowerPerc()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40297);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float DesireAmmo(bool bDetour)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40504);
			byte params[8] = { NULL };
			*(bool*)params = bDetour;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void ServerStartFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40692);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40695);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdjustWeaponTimingForConsole()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40702);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateOverlayMesh()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40704);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40709);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CalcInventoryWeight()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40712);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldSwitchTo(class UTWeapon* InWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40715);
			byte params[8] = { NULL };
			*(class UTWeapon**)params = InWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SetSkin(class Material* NewMaterial)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40718);
			byte params[4] = { NULL };
			*(class Material**)params = NewMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ActiveRenderOverlays(class HUD* H)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40722);
			byte params[4] = { NULL };
			*(class HUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawWeaponCrosshair(class HUD* HUD)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40726);
			byte params[4] = { NULL };
			*(class HUD**)params = HUD;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawLockedOn(class HUD* H)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40742);
			byte params[4] = { NULL };
			*(class HUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40758);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		float GetFireInterval(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40767);
			byte params[5] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void PlayArmAnimation(ScriptName Sequence, float fDesiredDuration, bool OffHand, bool bLoop, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40770);
			byte params[24] = { NULL };
			*(ScriptName*)params = Sequence;
			*(float*)&params[8] = fDesiredDuration;
			*(bool*)&params[12] = OffHand;
			*(bool*)&params[16] = bLoop;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[20] = SkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayWeaponAnimation(ScriptName Sequence, float fDesiredDuration, bool bLoop, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40781);
			byte params[20] = { NULL };
			*(ScriptName*)params = Sequence;
			*(float*)&params[8] = fDesiredDuration;
			*(bool*)&params[12] = bLoop;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = SkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayFireEffects(byte FireModeNum, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40786);
			byte params[13] = { NULL };
			*params = FireModeNum;
			*(Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopFireEffects(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40791);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShakeView()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40793);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WeaponCalcCamera(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40797);
			byte params[28] = { NULL };
			*(float*)params = fDeltaTime;
			*(Vector*)&params[4] = out_CamLoc;
			*(Rotator*)&params[16] = out_CamRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Vector*)&params[4];
			out_CamRot = *(Rotator*)&params[16];
		}
		void WeaponPlaySound(class SoundCue* Sound, float NoiseLoudness, bool bStopWhenOwnerDestroyed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40801);
			byte params[12] = { NULL };
			*(class SoundCue**)params = Sound;
			*(float*)&params[4] = NoiseLoudness;
			*(bool*)&params[8] = bStopWhenOwnerDestroyed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayFiringSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40806);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MuzzleFlashTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40808);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CauseMuzzleFlashLight()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40811);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CauseMuzzleFlash()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40815);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopMuzzleFlash()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40823);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TimeWeaponPutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40824);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayWeaponPutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40825);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TimeWeaponEquipping()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40829);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetEquipTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40830);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void PlayWeaponEquip()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40833);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AttachWeaponTo(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshCpnt, ScriptName SocketName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40837);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MeshCpnt;
			*(ScriptName*)&params[4] = SocketName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMuzzleFlashParams(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40845);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AttachMuzzleFlash()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40848);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DetachWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40850);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DetachMuzzleFlash()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40852);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChangeVisibility(bool bIsVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40854);
			byte params[4] = { NULL };
			*(bool*)params = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PerformWeaponChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40859);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetViewAxes(Vector& XAxis, Vector& YAxis, Vector& ZAxis)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40860);
			byte params[36] = { NULL };
			*(Vector*)params = XAxis;
			*(Vector*)&params[12] = YAxis;
			*(Vector*)&params[24] = ZAxis;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			XAxis = *(Vector*)params;
			YAxis = *(Vector*)&params[12];
			ZAxis = *(Vector*)&params[24];
		}
		void ServerReselectWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40864);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanThrow()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40865);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		UTPlayerController::EWeaponHand GetHand()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40867);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UTPlayerController::EWeaponHand*)params;
		}
		void SetPosition(class UDKPawn* Holder, float DeltaSeconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40870);
			byte params[8] = { NULL };
			*(class UDKPawn**)params = Holder;
			*(float*)&params[4] = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldLagRot()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40901);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		int LagRot(int NewValue, int LastValue, float MaxDiff, int Index, float DeltaSeconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40903);
			byte params[24] = { NULL };
			*(int*)params = NewValue;
			*(int*)&params[4] = LastValue;
			*(float*)&params[8] = MaxDiff;
			*(int*)&params[12] = Index;
			*(float*)&params[16] = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[20];
		}
		void AdjustPlayerDamage(int& Damage, class Controller* InstigatedBy, Vector HitLocation, Vector& Momentum, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40918);
			byte params[36] = { NULL };
			*(int*)params = Damage;
			*(class Controller**)&params[4] = InstigatedBy;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Damage = *(int*)params;
			Momentum = *(Vector*)&params[20];
		}
		float RelativeStrengthVersus(class Pawn* P, float Dist)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40924);
			byte params[12] = { NULL };
			*(class Pawn**)params = P;
			*(float*)&params[4] = Dist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float GetWeaponRating()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40928);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		bool CanAttack(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40933);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float BotDesireability(class Actor* PickupHolder, class Pawn* P, class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40948);
			byte params[16] = { NULL };
			*(class Actor**)params = PickupHolder;
			*(class Pawn**)&params[4] = P;
			*(class Controller**)&params[8] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		bool AmmoMaxed(int Mode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40960);
			byte params[8] = { NULL };
			*(int*)params = Mode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float GetDamageRadius()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40964);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		bool CanHeal(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40967);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float GetOptimalRangeFor(class Actor* Target)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40970);
			byte params[8] = { NULL };
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		bool FireOnRelease()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40973);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool FocusOnLeader(bool bLeaderFiring)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40975);
			byte params[8] = { NULL };
			*(bool*)params = bLeaderFiring;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool RecommendRangedAttack()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40978);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		float SuggestAttackStyle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40980);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float SuggestDefenseStyle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40982);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float RangedAttackTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40984);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		bool SplashJump()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40986);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool ShouldFireWithoutTarget()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40989);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		byte BestMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40991);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *params;
		}
		bool IsFullyCharged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40995);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool ReadyToFire(bool bFinished)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40997);
			byte params[8] = { NULL };
			*(bool*)params = bFinished;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool StillFiring(byte FireMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41000);
			byte params[5] = { NULL };
			*params = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ConsumeAmmo(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41005);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int AddAmmo(int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41008);
			byte params[8] = { NULL };
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool HasAmmo(byte FireModeNum, int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41013);
			byte params[9] = { NULL };
			*params = FireModeNum;
			*(int*)&params[4] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool HasAnyAmmo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41017);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool NeedAmmo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41020);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void Loaded(bool bUseWeaponMax)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41022);
			byte params[4] = { NULL };
			*(bool*)params = bUseWeaponMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DenyPickupQuery(ScriptClass* ItemClass, class Actor* Pickup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41024);
			byte params[12] = { NULL };
			*(ScriptClass**)params = ItemClass;
			*(class Actor**)&params[4] = Pickup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void WeaponEmpty()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41029);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool bReadyToFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41030);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		Vector InstantFireStartTrace()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41032);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		Vector InstantFireEndTrace(Vector StartTrace)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41034);
			byte params[24] = { NULL };
			*(Vector*)params = StartTrace;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		void InstantFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41037);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Actor::ImpactInfo InstantAimHelp(Vector StartTrace, Vector EndTrace, Actor::ImpactInfo RealImpact)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41047);
			byte params[184] = { NULL };
			*(Vector*)params = StartTrace;
			*(Vector*)&params[12] = EndTrace;
			*(Actor::ImpactInfo*)&params[24] = RealImpact;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Actor::ImpactInfo*)&params[104];
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41059);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Projectile**)params;
		}
		void ProcessInstantHit(byte FiringMode, Actor::ImpactInfo Impact, int NumHits)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41063);
			byte params[85] = { NULL };
			*params = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(int*)&params[84] = NumHits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		UTWeapon::EZoomState GetZoomedState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41070);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UTWeapon::EZoomState*)params;
		}
		bool CheckZoom(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41073);
			byte params[5] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void StartZoom(class UTPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41078);
			byte params[4] = { NULL };
			*(class UTPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndZoom(class UTPlayerController* PC, bool bReturningTo3P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41081);
			byte params[8] = { NULL };
			*(class UTPlayerController**)params = PC;
			*(bool*)&params[4] = bReturningTo3P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientEndFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41085);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41087);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendToFiringState(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41090);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientWeaponSet(bool bOptionalSet, bool bDoNotActivate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41092);
			byte params[8] = { NULL };
			*(bool*)params = bOptionalSet;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41096);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreloadTextures(bool bForcePreload)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41126);
			byte params[4] = { NULL };
			*(bool*)params = bForcePreload;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowSwitchTo(class Weapon* NewWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41128);
			byte params[8] = { NULL };
			*(class Weapon**)params = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool TryPutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41131);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void FiringPutDownWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41136);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Vector GetPhysicalFireStartLoc(Vector AimDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41137);
			byte params[24] = { NULL };
			*(Vector*)params = AimDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		Vector GetEffectLocation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41152);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		void RefireCheckTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41156);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetupArmsAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41157);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class AnimNodeSequence* GetArmAnimNodeSeq()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41168);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class AnimNodeSequence**)params;
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41171);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetWeaponOverlayFlags(class UTPawn* OwnerPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41189);
			byte params[4] = { NULL };
			*(class UTPawn**)params = OwnerPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float DetourWeight(class Pawn* Other, float PathWeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41196);
			byte params[12] = { NULL };
			*(class Pawn**)params = Other;
			*(float*)&params[4] = PathWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		bool RecommendLongRangedAttack()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41206);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ThrottleLook(float& aTurn, float& aLookUp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41208);
			byte params[8] = { NULL };
			*(float*)params = aTurn;
			*(float*)&params[4] = aLookUp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			aTurn = *(float*)params;
			aLookUp = *(float*)&params[4];
		}
		void Activate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41211);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DropFrom(Vector StartLocation, Vector StartVelocity)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41212);
			byte params[24] = { NULL };
			*(Vector*)params = StartLocation;
			*(Vector*)&params[12] = StartVelocity;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientWeaponThrown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41215);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanViewAccelerationWhenFiring()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41216);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void HolderEnteredVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41218);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HolderExitedVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41219);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawKillIcon(class Canvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41224);
			byte params[20] = { NULL };
			*(class Canvas**)params = Canvas;
			*(float*)&params[4] = ScreenX;
			*(float*)&params[8] = ScreenY;
			*(float*)&params[12] = HUDScaleX;
			*(float*)&params[16] = HUDScaleY;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool EnableFriendlyWarningCrosshair()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41232);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
