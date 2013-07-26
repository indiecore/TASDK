#pragma once
#include "UTGame.UTVehicleWeapon.h"
#include "Core.Object.Rotator.h"
#include "Engine.ParticleSystem.h"
#include "Core.Object.Vector.h"
#include "Engine.CameraShake.h"
#include "Engine.Projectile.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.SoundCue.h"
#include "TribesGame.TrProj_Tracer.h"
#include "UTGame.UTPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrVehicleWeapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrVehicleWeapon." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrVehicleWeapon : public UTVehicleWeapon
	{
	public:
		ADD_VAR(::IntProperty, m_nReticuleIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bShowAmmoIndicator, 0x20)
		ADD_VAR(::FloatProperty, m_fReloadTimeRemaining, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bEndZoomOnReload, 0x100)
		ADD_VAR(::BoolProperty, r_bIsReloading, 0x40)
		ADD_VAR(::NameProperty, m_WeaponSpinControl, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bSpawnTracers, 0x1)
		ADD_VAR(::ByteProperty, m_TracerType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bSpawnTracerBeams, 0x2)
		ADD_OBJECT(ParticleSystem, m_TracerBeamTemplate)
		ADD_VAR(::FloatProperty, m_fShowTracerDistance, 0xFFFFFFFF)
		ADD_OBJECT(CameraShake, m_FireCameraShake)
		ADD_OBJECT(MaterialInstanceConstant, m_ZoomOverlayMaterial)
		ADD_VAR(::NameProperty, m_nmZoomMaterialEffectName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nCarriedAmmoCount, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, m_DryFireSoundCue)
		ADD_OBJECT(SoundCue, m_ReloadAmmoSoundCue)
		ADD_VAR(::FloatProperty, m_fPctTimeBeforeReload, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fReloadTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nCarriedAmmo, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLowAmmoWarning, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nTracerInterval, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bCanZoom, 0x80)
		ADD_VAR(::BoolProperty, m_bPendingReload, 0x10)
		ADD_VAR(::BoolProperty, m_bReloadSingles, 0x8)
		ADD_VAR(::BoolProperty, m_bLowAmmoOn, 0x4)
		ADD_VAR(::FloatProperty, m_fAccuracyCorrectionRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAimingModeAccuracyBonus, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAccuracyLossMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAccuracyLossOnShot, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAccuracyLossOnWeaponSwitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAccuracyLossOnJump, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDefaultAccuracy, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCachedFiringCone, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nFiringConeWidthDegrees, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_ShotsFired, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nAltReticuleIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DBWeaponId, 0xFFFFFFFF)
		bool HasReticuleCharge()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.HasReticuleCharge");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		float CalculateReloadPercentRemaining()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.CalculateReloadPercentRemaining");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetAccuracy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.GetAccuracy");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		bool CanClientRequestReloadNow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.CanClientRequestReloadNow");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CanViewZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.CanViewZoom");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		float GetTargetAccuracy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.GetTargetAccuracy");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void RestoreAccuracy(float fTimeStep)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.RestoreAccuracy");
			byte* params = (byte*)malloc(4);
			*(float*)params = fTimeStep;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitVehicleGun()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.InitVehicleGun");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float CalculateReloadTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.CalculateReloadTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.StartFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsWeaponInFiringCone()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.IsWeaponInFiringCone");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.ProjectileFire");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Projectile**)params;
			free(params);
			return returnVal;
		}
		ScriptClass* GetProjectileClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.GetProjectileClass");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)params;
			free(params);
			return returnVal;
		}
		void UpdateShotsFired(bool Reset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.UpdateShotsFired");
			byte* params = (byte*)malloc(4);
			*(bool*)params = Reset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetNumRoundsCurrentlyInClip()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.GetNumRoundsCurrentlyInClip");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		Vector GetEffectLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.GetEffectLocation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		void AttachMuzzleFlash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.AttachMuzzleFlash");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MuzzleFlashTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.MuzzleFlashTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CauseMuzzleFlash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.CauseMuzzleFlash");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopMuzzleFlash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.StopMuzzleFlash");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayFireEffects(byte FireModeNum, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.PlayFireEffects");
			byte* params = (byte*)malloc(13);
			*params = FireModeNum;
			*(Vector*)(params + 4) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShakeView()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.ShakeView");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldFireTracer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.ShouldFireTracer");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool ShouldFireTracerBeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.ShouldFireTracerBeam");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SpawnTracerBeam(Vector Start, Vector End)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.SpawnTracerBeam");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = Start;
			*(Vector*)(params + 12) = End;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class TrProj_Tracer* SpawnTracerEffect(Vector HitLocation, float HitDistance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.SpawnTracerEffect");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitLocation;
			*(float*)(params + 12) = HitDistance;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrProj_Tracer**)(params + 16);
			free(params);
			return returnVal;
		}
		void WeaponPlaySoundLocal(class SoundCue* Sound, float NoiseLoudness, bool bStopWhenOwnerDestroyed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.WeaponPlaySoundLocal");
			byte* params = (byte*)malloc(12);
			*(class SoundCue**)params = Sound;
			*(float*)(params + 4) = NoiseLoudness;
			*(bool*)(params + 8) = bStopWhenOwnerDestroyed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class TrProj_Tracer* GetTracer(Vector SpawnLocation, Rotator SpawnRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.GetTracer");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = SpawnLocation;
			*(Rotator*)(params + 12) = SpawnRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrProj_Tracer**)(params + 24);
			free(params);
			return returnVal;
		}
		void PayAccuracyForShot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.PayAccuracyForShot");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Rotator AddSpreadWithAccuracy(Rotator BaseAim, float fAccuracy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.AddSpreadWithAccuracy");
			byte* params = (byte*)malloc(28);
			*(Rotator*)params = BaseAim;
			*(float*)(params + 12) = fAccuracy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 16);
			free(params);
			return returnVal;
		}
		Rotator GetAdjustedAim(Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.GetAdjustedAim");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 12);
			free(params);
			return returnVal;
		}
		Rotator AddSpread(Rotator BaseAim)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.AddSpread");
			byte* params = (byte*)malloc(24);
			*(Rotator*)params = BaseAim;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 12);
			free(params);
			return returnVal;
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.FireAmmunition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.BeginFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PutDownWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.PutDownWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RequestReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.RequestReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnClientReloaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.OnClientReloaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientFinishedReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.ClientFinishedReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReloadComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.OnReloadComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginAReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.BeginAReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int AddCarriedAmmo(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.AddCarriedAmmo");
			byte* params = (byte*)malloc(8);
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void UpdateReplicatedCarriedAmmo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.UpdateReplicatedCarriedAmmo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartZoom(class UTPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.StartZoom");
			byte* params = (byte*)malloc(4);
			*(class UTPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndZoom(class UTPlayerController* PC, bool bReturningTo3P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.EndZoom");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerController**)params = PC;
			*(bool*)(params + 4) = bReturningTo3P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAltReticule()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.SetAltReticule");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetAltReticule()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.ResetAltReticule");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
