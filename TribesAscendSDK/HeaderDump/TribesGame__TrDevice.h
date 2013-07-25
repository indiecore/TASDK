#pragma once
#include "Engine__Actor.h"
#include "UTGame__UTWeapon.h"
#include "Engine__ParticleSystem.h"
#include "Engine__MaterialInstanceConstant.h"
#include "TribesGame__TrDeviceContentData.h"
#include "UDKBase__UDKPawn.h"
#include "Engine__AnimSet.h"
#include "Engine__CameraShake.h"
#include "Engine__Material.h"
#include "TribesGame__TrAnimNodeBlendByDeviceAnim.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__SoundCue.h"
#include "TribesGame__TrDeployable.h"
#include "TribesGame__TrProj_Tracer.h"
#include "Engine__Weapon.h"
#include "Engine__Projectile.h"
#include "TribesGame__TrPawn.h"
#include "UTGame__UTPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDevice." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice : public UTWeapon
	{
	public:
		ADD_VAR(::IntProperty, m_nCarriedAmmo, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nIconIndex, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, UpgradeDescription, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DBXPActivityId, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, InfoPanelDescription, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, InfoPanelDamage, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, InfoPanelRadius, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, InfoPanelFireRate, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, InfoPanelClipSize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DBWeaponId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nReticuleIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bAllowFireWhileZoomed, 0x100000)
		ADD_STRUCT(::VectorProperty, m_vClientSideFireOffset, 0xFFFFFFFF)
		ADD_OBJECT(TrDeviceContentData, m_ContentData)
		ADD_VAR(::StrProperty, m_sContentDataClassName, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrDevice.DeviceUpgrade' for the property named 'BaseMod'!
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo' for the property named 'm_InGamePaperDollInfo'!
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo' for the property named 'm_MainMenuPaperDollInfo'!
		ADD_STRUCT(::VectorProperty, m_TinyWeaponsOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTimeBeforeInactiveReload, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastActiveTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nTetherCounter, 0xFFFFFFFF)
		ADD_OBJECT(AnimSet, m_NoAmmoAnimSet)
		ADD_VAR(::FloatProperty, m_fFireIntervalForLastShotInClip, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fClientSideHitLeeway, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_ZoomOverlayMaterial)
		ADD_VAR(::NameProperty, m_nmZoomMaterialEffectName, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vZoomMeshOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fZoomRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDesiredZoomFOV, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_ShotsFired, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vPositionPivotOffset, 0xFFFFFFFF)
		ADD_OBJECT(CameraShake, m_FireCameraShake)
		ADD_OBJECT(Material, r_ReplicatedMaterial)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'm_v2WeaponLagSmoothingFactor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'm_v2WeaponLagInterpSpeed'!
		ADD_VAR(::IntProperty, m_nMaxWeaponLagPitch, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nMaxWeaponLagYaw, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'm_v2WeaponLagAimOffset'!
		ADD_VAR(::FloatProperty, m_fMaxKickbackDistanceY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxKickbackDistanceX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fKickbackBlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastKickbackTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'm_v2KickbackAmount'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'm_v2MinMaxKickbackY'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'm_v2MinMaxKickbackX'!
		ADD_VAR(::IntProperty, m_nCreditCost, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, m_TracerBeamTemplate)
		ADD_VAR(::FloatProperty, m_fShowTracerDistance, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nTracerInterval, 0xFFFFFFFF)
		ADD_OBJECT(TrAnimNodeBlendByDeviceAnim, m_DeviceAnimNode)
		ADD_VAR(::FloatProperty, m_fLockTargetTime, 0xFFFFFFFF)
		ADD_OBJECT(Actor, c_LockedActor)
		ADD_VAR(::FloatProperty, c_fLockTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrDevice.ReplicatedAmmoCount' for the property named 'r_AmmoCount'!
		ADD_VAR(::IntProperty, s_iCheatCountAmmo, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, m_ZoomOutSoundCue)
		ADD_OBJECT(SoundCue, m_ZoomInSoundCue)
		ADD_OBJECT(SoundCue, m_DryFireSoundCue)
		ADD_OBJECT(SoundCue, m_ReloadAmmoSoundCue)
		ADD_VAR(::FloatProperty, m_fPctTimeBeforeReload, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fReloadTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_RemainingAmmoInClip, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nMaxCarriedAmmo, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLowAmmoWarning, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nAltReticuleIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fQuickRetrieveEquipTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAccuracyCorrectionRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAimingModeAccuracyBonus, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAccuracyLossMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAccuracyLossOnShot, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAccuracyLossOnWeaponSwitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAccuracyLossOnJump, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDefaultAccuracy, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bTinyWeaponsEnabled, 0x4000000)
		ADD_VAR(::BoolProperty, r_bIsReloading, 0x2000000)
		ADD_VAR(::BoolProperty, m_bResumeZoomOnReloadEnd, 0x1000000)
		ADD_VAR(::BoolProperty, m_bEndZoomOnReload, 0x800000)
		ADD_VAR(::BoolProperty, m_bUseMeshZoomOffset, 0x400000)
		ADD_VAR(::BoolProperty, m_bCanZoom, 0x200000)
		ADD_VAR(::BoolProperty, m_bAllowHoldDownFire, 0x80000)
		ADD_VAR(::BoolProperty, m_bWantsToFire, 0x40000)
		ADD_VAR(::BoolProperty, m_bIsPassive, 0x20000)
		ADD_VAR(::BoolProperty, m_bIsKickbackAdditive, 0x10000)
		ADD_VAR(::BoolProperty, m_bSpawnTracerBeams, 0x8000)
		ADD_VAR(::BoolProperty, m_bSpawnTracers, 0x4000)
		ADD_VAR(::BoolProperty, m_bUsesDeployMode, 0x2000)
		ADD_VAR(::BoolProperty, c_bLocking, 0x1000)
		ADD_VAR(::BoolProperty, m_bForceReplicateAmmoOnFire, 0x800)
		ADD_VAR(::BoolProperty, r_bReadyToFire, 0x400)
		ADD_VAR(::BoolProperty, m_bCanEarlyAbortReload, 0x200)
		ADD_VAR(::BoolProperty, m_bReloadBulletInChamber, 0x100)
		ADD_VAR(::BoolProperty, m_bPendingReload, 0x80)
		ADD_VAR(::BoolProperty, m_bReloadSingles, 0x40)
		ADD_VAR(::BoolProperty, m_bAllowReloads, 0x20)
		ADD_VAR(::BoolProperty, m_bLowAmmoOn, 0x10)
		ADD_VAR(::BoolProperty, m_bRequireAimMode, 0x8)
		ADD_VAR(::BoolProperty, m_bHighlightEnemies, 0x4)
		ADD_VAR(::BoolProperty, m_bEquipEffectsApplied, 0x2)
		ADD_VAR(::BoolProperty, m_bAllowMultipleTargets, 0x1)
		ADD_VAR(::FloatProperty, m_fConeAttackAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDamageRadius, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_TracerType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_eEquipAt, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DBWeaponTypeId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DBWeaponBaseId, 0xFFFFFFFF)
		float CalcHUDAimChargePercent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CalcHUDAimChargePercent");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetAccuracy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetAccuracy");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		byte GetFireModeNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetFireModeNum");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		bool IsValidTarget(class Actor* Target, int nFireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.IsValidTarget");
			byte* params = (byte*)malloc(12);
			*(class Actor**)params = Target;
			*(int*)(params + 4) = nFireMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool IsEnemy(class Actor* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.IsEnemy");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsInsideCone(Vector SourceLookDir, class Actor* TargetActor, Vector StartCone, float MinCosine)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.IsInsideCone");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = SourceLookDir;
			*(class Actor**)(params + 12) = TargetActor;
			*(Vector*)(params + 16) = StartCone;
			*(float*)(params + 28) = MinCosine;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		bool ShouldAddToImpactList(class Actor* HitActor, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* ImpactList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ShouldAddToImpactList");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = HitActor;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = ImpactList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void TickInHandWeapon(float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.TickInHandWeapon");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetLock()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ResetLock");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Actor* GetLockedTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetLockedTarget");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)params;
			free(params);
			return returnVal;
		}
		class TrDeployable* SpawnPet(bool bPet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.SpawnPet");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bPet;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrDeployable**)(params + 4);
			free(params);
			return returnVal;
		}
		float GetTargetAccuracy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetTargetAccuracy");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void RestoreAccuracy(float fTimeStep)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.RestoreAccuracy");
			byte* params = (byte*)malloc(4);
			*(float*)params = fTimeStep;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RestoreKickback(float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.RestoreKickback");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsInLOS(class Actor* TouchedActor, Vector ExpectedLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.IsInLOS");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = TouchedActor;
			*(Vector*)(params + 4) = ExpectedLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void AttachHandsMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.AttachHandsMesh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class TrDeviceContentData* LoadMeshData()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.LoadMeshData");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrDeviceContentData**)params;
			free(params);
			return returnVal;
		}
		int ValidateClientReportedHit(byte FiringMode, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* Impact, bool bHeadShot, bool bDeviceIsFiring)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ValidateClientReportedHit");
			byte* params = (byte*)malloc(93);
			*params = FiringMode;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 4) = Impact;
			*(bool*)(params + 84) = bHeadShot;
			*(bool*)(params + 88) = bDeviceIsFiring;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 92);
			free(params);
			return returnVal;
		}
		int ValidateClientReportedHitInternal(byte FiringMode, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* Impact, bool bHeadShot, bool bDeviceIsFiring)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ValidateClientReportedHitInternal");
			byte* params = (byte*)malloc(93);
			*params = FiringMode;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 4) = Impact;
			*(bool*)(params + 84) = bHeadShot;
			*(bool*)(params + 88) = bDeviceIsFiring;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 92);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetObjectReferencerName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetObjectReferencerName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetObjectReferencerPackageName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetObjectReferencerPackageName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int AddAmmo(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.AddAmmo");
			byte* params = (byte*)malloc(8);
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ReplicateAmmoOnWeaponFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ReplicateAmmoOnWeaponFire");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ConsumeAmmo_Internal(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ConsumeAmmo_Internal");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ConsumeAmmo(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ConsumeAmmo");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Actor* GetTraceOwner()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetTraceOwner");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)params;
			free(params);
			return returnVal;
		}
		void AttachWeaponTo(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshCpnt, ScriptName SocketName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.AttachWeaponTo");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MeshCpnt;
			*(ScriptName*)(params + 4) = SocketName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CreateFirstPersonHandsMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CreateFirstPersonHandsMesh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChangeVisibility(bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ChangeVisibility");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CentralUpdateHandsMesh(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CentralUpdateHandsMesh");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateHandsMesh(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.UpdateHandsMesh");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CreateOverlayMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CreateOverlayMesh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayWeaponEquip()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PlayWeaponEquip");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPlayRetrieveAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.OnPlayRetrieveAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayWeaponPutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PlayWeaponPutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WeaponEmpty()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.WeaponEmpty");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchToWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.OnSwitchToWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchAwayFromWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.OnSwitchAwayFromWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientWeaponSet(bool bOptionalSet, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ClientWeaponSet");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bOptionalSet;
			*(bool*)(params + 4) = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayFireEffects(byte FireModeNum, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PlayFireEffects");
			byte* params = (byte*)malloc(13);
			*params = FireModeNum;
			*(Vector*)(params + 4) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayFireAnimation(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PlayFireAnimation");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShakeView()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ShakeView");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldFireTracer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ShouldFireTracer");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool ShouldFireTracerBeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ShouldFireTracerBeam");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SpawnTracerBeam(Vector Start, Vector End)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.SpawnTracerBeam");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = Start;
			*(Vector*)(params + 12) = End;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class TrProj_Tracer* SpawnTracerEffect(Vector HitLocation, float HitDistance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.SpawnTracerEffect");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitLocation;
			*(float*)(params + 12) = HitDistance;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrProj_Tracer**)(params + 16);
			free(params);
			return returnVal;
		}
		class TrProj_Tracer* GetTracer(Vector SpawnLocation, Rotator SpawnRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetTracer");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = SpawnLocation;
			*(Rotator*)(params + 12) = SpawnRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrProj_Tracer**)(params + 24);
			free(params);
			return returnVal;
		}
		int GetNumRoundsCurrentlyInClip()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetNumRoundsCurrentlyInClip");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool HasAmmo(byte FireModeNum, int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.HasAmmo");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.HasAnyAmmo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool AllowSwitchTo(class Weapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.AllowSwitchTo");
			byte* params = (byte*)malloc(8);
			*(class Weapon**)params = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		float CalculateRangeDamageFalloff(float Dist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CalculateRangeDamageFalloff");
			byte* params = (byte*)malloc(8);
			*(float*)params = Dist;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void InstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.InstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessInstantHit(byte FiringMode, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* Impact, int NumHits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ProcessInstantHit");
			byte* params = (byte*)malloc(85);
			*params = FiringMode;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 4) = Impact;
			*(int*)(params + 84) = NumHits;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerNotifyHit(byte FiringMode, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* Impact, bool bHeadShot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ServerNotifyHit");
			byte* params = (byte*)malloc(85);
			*params = FiringMode;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 4) = Impact;
			*(bool*)(params + 84) = bHeadShot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessInstantHit_Internal(byte FiringMode, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* Impact, bool bHeadShot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ProcessInstantHit_Internal");
			byte* params = (byte*)malloc(85);
			*params = FiringMode;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 4) = Impact;
			*(bool*)(params + 84) = bHeadShot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float ModifyInstantHitDamage(byte FiringMode, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* Impact, float Damage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ModifyInstantHitDamage");
			byte* params = (byte*)malloc(89);
			*params = FiringMode;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 4) = Impact;
			*(float*)(params + 84) = Damage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 88);
			free(params);
			return returnVal;
		}
		void ProcessEffect(class Actor* Target, byte FiringMode, byte efType, bool bRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ProcessEffect");
			byte* params = (byte*)malloc(10);
			*(class Actor**)params = Target;
			*(params + 4) = FiringMode;
			*(params + 5) = efType;
			*(bool*)(params + 8) = bRemove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool UsesPower()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.UsesPower");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsDeviceCoolingDown(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.IsDeviceCoolingDown");
			byte* params = (byte*)malloc(5);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void EnterDeployMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.EnterDeployMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ExitDeployMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ExitDeployMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleActivate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ToggleActivate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PayAccuracyForJump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PayAccuracyForJump");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PayAccuracyForWeaponSwitch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PayAccuracyForWeaponSwitch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PayAccuracyForShot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PayAccuracyForShot");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Rotator AddSpreadWithAccuracy(Rotator BaseAim, float fAccuracy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.AddSpreadWithAccuracy");
			byte* params = (byte*)malloc(28);
			*(Rotator*)params = BaseAim;
			*(float*)(params + 12) = fAccuracy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 16);
			free(params);
			return returnVal;
		}
		Rotator ApplyKickbackToAim(Rotator Aim)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ApplyKickbackToAim");
			byte* params = (byte*)malloc(24);
			*(Rotator*)params = Aim;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 12);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* GetCurrentKickbackAmount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetCurrentKickbackAmount");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params;
			free(params);
			return returnVal;
		}
		bool AddKickback()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.AddKickback");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		Rotator GetAdjustedAim(Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetAdjustedAim");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 12);
			free(params);
			return returnVal;
		}
		bool ShowWeaponRedLowAmmoIndicator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ShowWeaponRedLowAmmoIndicator");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool NeedToVisitInventoryStation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.NeedToVisitInventoryStation");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		int GetAmmoCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetAmmoCount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void UpdateLowAmmoWarning()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.UpdateLowAmmoWarning");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptClass* GetProjectileClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetProjectileClass");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)params;
			free(params);
			return returnVal;
		}
		Vector GetClientSideProjectileFireStartLoc(Vector AimDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetClientSideProjectileFireStartLoc");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = AimDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ProjectileFire");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Projectile**)params;
			free(params);
			return returnVal;
		}
		void DestroyOldestProjectileOverLimit(class Projectile* newProjectile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.DestroyOldestProjectileOverLimit");
			byte* params = (byte*)malloc(4);
			*(class Projectile**)params = newProjectile;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.FireAmmunition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float MaxRange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.MaxRange");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetWeaponRange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetWeaponRange");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		Rotator GetAimForCamera(Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetAimForCamera");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 12);
			free(params);
			return returnVal;
		}
		bool CanClientRequestReloadNow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CanClientRequestReloadNow");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void HolderEnteredVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.HolderEnteredVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetReloadTime(class PlayerReplicationInfo* PRI, byte EquipPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetReloadTime");
			byte* params = (byte*)malloc(9);
			*(class PlayerReplicationInfo**)params = PRI;
			*(params + 4) = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		void ClearMeshAnimSeqNodes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ClearMeshAnimSeqNodes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CacheMeshAnimSeqNodes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CacheMeshAnimSeqNodes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SuppressAnimNotifies(bool bSuppress)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.SuppressAnimNotifies");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bSuppress;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsReloading()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.IsReloading");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void RequestReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.RequestReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnClientReloaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.OnClientReloaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PerformInactiveReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PerformInactiveReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int CalcAmountToLoad()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CalcAmountToLoad");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void ClientFinishedReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ClientFinishedReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResumeZoomOnReloadEnd()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ResumeZoomOnReloadEnd");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayReloadAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PlayReloadAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnableWeaponReadyToFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.EnableWeaponReadyToFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReloadComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.OnReloadComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginAReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.BeginAReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int AddCarriedAmmo(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.AddCarriedAmmo");
			byte* params = (byte*)malloc(8);
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void UpdateReplicatedCarriedAmmo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.UpdateReplicatedCarriedAmmo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GoInactiveDueToOffhand()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GoInactiveDueToOffhand");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.StopFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BeginFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.BeginFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetEquipTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetEquipTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void TimeWeaponPutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.TimeWeaponPutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetPutDownTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetPutDownTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		bool CanFireOffhandNow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CanFireOffhandNow");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ServerOnClientDeniedFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ServerOnClientDeniedFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyEquipEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ApplyEquipEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveEquipEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.RemoveEquipEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPosition(class UDKPawn* Holder, float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.SetPosition");
			byte* params = (byte*)malloc(8);
			*(class UDKPawn**)params = Holder;
			*(float*)(params + 4) = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int LagRot(int NewValue, int LastValue, float MaxDiff, int Index, float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.LagRot");
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
		bool ShouldRefire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ShouldRefire");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.StartFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Activate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.Activate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AnnounceInvalidPickup(class TrPawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.AnnounceInvalidPickup");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool DenyPickupQuery(ScriptClass* ItemClass, class Actor* Pickup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.DenyPickupQuery");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = ItemClass;
			*(class Actor**)(params + 4) = Pickup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void PutDownFast()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PutDownFast");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceEndFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ForceEndFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanAutoDeviceFireNow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CanAutoDeviceFireNow");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void CustomFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CustomFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AttachMuzzleFlash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.AttachMuzzleFlash");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WeaponPlaySoundLocal(class SoundCue* Sound, float NoiseLoudness)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.WeaponPlaySoundLocal");
			byte* params = (byte*)malloc(8);
			*(class SoundCue**)params = Sound;
			*(float*)(params + 4) = NoiseLoudness;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientWeaponThrown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ClientWeaponThrown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateShotsFired(bool Reset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.UpdateShotsFired");
			byte* params = (byte*)malloc(4);
			*(bool*)params = Reset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartZoom(class UTPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.StartZoom");
			byte* params = (byte*)malloc(4);
			*(class UTPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndZoom(class UTPlayerController* PC, bool bReturningTo3P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.EndZoom");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerController**)params = PC;
			*(bool*)(params + 4) = bReturningTo3P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanViewZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CanViewZoom");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetAltReticule()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.SetAltReticule");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetAltReticule()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ResetAltReticule");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* CalcWeaponFire(Vector StartTrace, Vector EndTrace, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ImpactList, Vector Extent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CalcWeaponFire");
			byte* params = (byte*)malloc(128);
			*(Vector*)params = StartTrace;
			*(Vector*)(params + 12) = EndTrace;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 24) = ImpactList;
			*(Vector*)(params + 36) = Extent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ImpactList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 24);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 48);
			free(params);
			return returnVal;
		}
		void PlayDryFireZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PlayDryFireZoom");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BuffMaxCarriedAmmo(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.BuffMaxCarriedAmmo");
			byte* params = (byte*)malloc(4);
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetMaxAmmoCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetMaxAmmoCount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		int GetBasePickupAmmoAmount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetBasePickupAmmoAmount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void ServerStartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ServerStartFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateWeaponMICs()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.UpdateWeaponMICs");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
