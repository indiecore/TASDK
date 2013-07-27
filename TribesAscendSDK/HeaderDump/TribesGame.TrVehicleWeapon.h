#pragma once
#include "UTGame.UTVehicleWeapon.h"
#include "TribesGame.TrProj_Tracer.h"
#include "TribesGame.TrObject.h"
#include "Engine.ParticleSystem.h"
#include "Engine.CameraShake.h"
#include "Engine.Projectile.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.SoundCue.h"
#include "Core.Object.h"
#include "UTGame.UTPlayerController.h"
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
	class TrVehicleWeapon : public UTVehicleWeapon
	{
	public:
		ADD_STRUCT(int, m_nReticuleIndex, 1656)
		ADD_BOOL(m_bShowAmmoIndicator, 1712, 0x20)
		ADD_STRUCT(float, m_fReloadTimeRemaining, 1704)
		ADD_BOOL(m_bEndZoomOnReload, 1712, 0x100)
		ADD_BOOL(r_bIsReloading, 1712, 0x40)
		ADD_STRUCT(ScriptName, m_WeaponSpinControl, 1772)
		ADD_BOOL(m_bSpawnTracers, 1712, 0x1)
		ADD_STRUCT(TrObject::EWeaponTracerType, m_TracerType, 1708)
		ADD_BOOL(m_bSpawnTracerBeams, 1712, 0x2)
		ADD_OBJECT(ParticleSystem, m_TracerBeamTemplate, 1724)
		ADD_STRUCT(float, m_fShowTracerDistance, 1720)
		ADD_OBJECT(CameraShake, m_FireCameraShake, 1768)
		ADD_OBJECT(MaterialInstanceConstant, m_ZoomOverlayMaterial, 1764)
		ADD_STRUCT(ScriptName, m_nmZoomMaterialEffectName, 1756)
		ADD_STRUCT(int, r_nCarriedAmmoCount, 1752)
		ADD_OBJECT(SoundCue, m_DryFireSoundCue, 1748)
		ADD_OBJECT(SoundCue, m_ReloadAmmoSoundCue, 1744)
		ADD_STRUCT(float, m_fPctTimeBeforeReload, 1740)
		ADD_STRUCT(float, m_fReloadTime, 1736)
		ADD_STRUCT(int, m_nCarriedAmmo, 1732)
		ADD_STRUCT(int, m_nLowAmmoWarning, 1728)
		ADD_STRUCT(int, m_nTracerInterval, 1716)
		ADD_BOOL(m_bCanZoom, 1712, 0x80)
		ADD_BOOL(m_bPendingReload, 1712, 0x10)
		ADD_BOOL(m_bReloadSingles, 1712, 0x8)
		ADD_BOOL(m_bLowAmmoOn, 1712, 0x4)
		ADD_STRUCT(float, m_fAccuracyCorrectionRate, 1700)
		ADD_STRUCT(float, m_fAimingModeAccuracyBonus, 1696)
		ADD_STRUCT(float, m_fAccuracyLossMax, 1692)
		ADD_STRUCT(float, m_fAccuracyLossOnShot, 1688)
		ADD_STRUCT(float, m_fAccuracyLossOnWeaponSwitch, 1684)
		ADD_STRUCT(float, m_fAccuracyLossOnJump, 1680)
		ADD_STRUCT(float, m_fDefaultAccuracy, 1676)
		ADD_STRUCT(float, m_fCachedFiringCone, 1672)
		ADD_STRUCT(int, m_nFiringConeWidthDegrees, 1668)
		ADD_STRUCT(int, m_ShotsFired, 1664)
		ADD_STRUCT(int, m_nAltReticuleIndex, 1660)
		ADD_STRUCT(int, DBWeaponId, 1652)
		bool HasReticuleCharge()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.HasReticuleCharge");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		float CalculateReloadPercentRemaining()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.CalculateReloadPercentRemaining");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetAccuracy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.GetAccuracy");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		bool CanClientRequestReloadNow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.CanClientRequestReloadNow");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool CanViewZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.CanViewZoom");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		float GetTargetAccuracy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.GetTargetAccuracy");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void RestoreAccuracy(float fTimeStep)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.RestoreAccuracy");
			byte params[4] = { NULL };
			*(float*)&params[0] = fTimeStep;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitVehicleGun()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.InitVehicleGun");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float CalculateReloadTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.CalculateReloadTime");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.StartFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsWeaponInFiringCone()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.IsWeaponInFiringCone");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.ProjectileFire");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Projectile**)&params[0];
		}
		ScriptClass* GetProjectileClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.GetProjectileClass");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[0];
		}
		void UpdateShotsFired(bool Reset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.UpdateShotsFired");
			byte params[4] = { NULL };
			*(bool*)&params[0] = Reset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetNumRoundsCurrentlyInClip()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.GetNumRoundsCurrentlyInClip");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		Object::Vector GetEffectLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.GetEffectLocation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
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
		void PlayFireEffects(byte FireModeNum, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.PlayFireEffects");
			byte params[13] = { NULL };
			params[0] = FireModeNum;
			*(Object::Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShakeView()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.ShakeView");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldFireTracer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.ShouldFireTracer");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool ShouldFireTracerBeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.ShouldFireTracerBeam");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SpawnTracerBeam(Object::Vector Start, Object::Vector End)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.SpawnTracerBeam");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = Start;
			*(Object::Vector*)&params[12] = End;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class TrProj_Tracer* SpawnTracerEffect(Object::Vector HitLocation, float HitDistance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.SpawnTracerEffect");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(float*)&params[12] = HitDistance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrProj_Tracer**)&params[16];
		}
		void WeaponPlaySoundLocal(class SoundCue* Sound, float NoiseLoudness, bool bStopWhenOwnerDestroyed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.WeaponPlaySoundLocal");
			byte params[12] = { NULL };
			*(class SoundCue**)&params[0] = Sound;
			*(float*)&params[4] = NoiseLoudness;
			*(bool*)&params[8] = bStopWhenOwnerDestroyed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class TrProj_Tracer* GetTracer(Object::Vector SpawnLocation, Object::Rotator SpawnRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.GetTracer");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = SpawnLocation;
			*(Object::Rotator*)&params[12] = SpawnRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrProj_Tracer**)&params[24];
		}
		void PayAccuracyForShot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.PayAccuracyForShot");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Object::Rotator AddSpreadWithAccuracy(Object::Rotator BaseAim, float fAccuracy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.AddSpreadWithAccuracy");
			byte params[28] = { NULL };
			*(Object::Rotator*)&params[0] = BaseAim;
			*(float*)&params[12] = fAccuracy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[16];
		}
		Object::Rotator GetAdjustedAim(Object::Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.GetAdjustedAim");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[12];
		}
		Object::Rotator AddSpread(Object::Rotator BaseAim)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.AddSpread");
			byte params[24] = { NULL };
			*(Object::Rotator*)&params[0] = BaseAim;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[12];
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.FireAmmunition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.BeginFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[8] = { NULL };
			*(int*)&params[0] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void UpdateReplicatedCarriedAmmo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.UpdateReplicatedCarriedAmmo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartZoom(class UTPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.StartZoom");
			byte params[4] = { NULL };
			*(class UTPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndZoom(class UTPlayerController* PC, bool bReturningTo3P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon.EndZoom");
			byte params[8] = { NULL };
			*(class UTPlayerController**)&params[0] = PC;
			*(bool*)&params[4] = bReturningTo3P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
