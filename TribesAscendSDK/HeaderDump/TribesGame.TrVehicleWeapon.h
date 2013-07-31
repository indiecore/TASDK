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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(53721);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		float CalculateReloadPercentRemaining()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(53723);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetAccuracy()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61619);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		bool CanClientRequestReloadNow()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76406);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CanViewZoom()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76916);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		float GetTargetAccuracy()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115117);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void RestoreAccuracy(float fTimeStep)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115119);
			byte params[4] = { NULL };
			*(float*)params = fTimeStep;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitVehicleGun()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115121);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float CalculateReloadTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115122);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115124);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115125);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsWeaponInFiringCone()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115127);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115131);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Projectile**)params;
		}
		ScriptClass* GetProjectileClass()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115136);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)params;
		}
		void UpdateShotsFired(bool Reset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115138);
			byte params[4] = { NULL };
			*(bool*)params = Reset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetNumRoundsCurrentlyInClip()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115140);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		Vector GetEffectLocation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115142);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		void AttachMuzzleFlash()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115145);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MuzzleFlashTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115147);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CauseMuzzleFlash()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115148);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopMuzzleFlash()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115150);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayFireEffects(byte FireModeNum, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115151);
			byte params[13] = { NULL };
			*params = FireModeNum;
			*(Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShakeView()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115154);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldFireTracer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115156);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool ShouldFireTracerBeam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115158);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SpawnTracerBeam(Vector Start, Vector End)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115160);
			byte params[24] = { NULL };
			*(Vector*)params = Start;
			*(Vector*)&params[12] = End;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class TrProj_Tracer* SpawnTracerEffect(Vector HitLocation, float HitDistance)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115164);
			byte params[20] = { NULL };
			*(Vector*)params = HitLocation;
			*(float*)&params[12] = HitDistance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrProj_Tracer**)&params[16];
		}
		void WeaponPlaySoundLocal(class SoundCue* Sound, float NoiseLoudness, bool bStopWhenOwnerDestroyed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115171);
			byte params[12] = { NULL };
			*(class SoundCue**)params = Sound;
			*(float*)&params[4] = NoiseLoudness;
			*(bool*)&params[8] = bStopWhenOwnerDestroyed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class TrProj_Tracer* GetTracer(Vector SpawnLocation, Rotator SpawnRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115175);
			byte params[28] = { NULL };
			*(Vector*)params = SpawnLocation;
			*(Rotator*)&params[12] = SpawnRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrProj_Tracer**)&params[24];
		}
		void PayAccuracyForShot()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115179);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Rotator AddSpreadWithAccuracy(Rotator BaseAim, float fAccuracy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115182);
			byte params[28] = { NULL };
			*(Rotator*)params = BaseAim;
			*(float*)&params[12] = fAccuracy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[16];
		}
		Rotator GetAdjustedAim(Vector StartFireLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115193);
			byte params[24] = { NULL };
			*(Vector*)params = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[12];
		}
		Rotator AddSpread(Rotator BaseAim)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115199);
			byte params[24] = { NULL };
			*(Rotator*)params = BaseAim;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[12];
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115202);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115203);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PutDownWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115205);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RequestReload()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115224);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnClientReloaded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115225);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientFinishedReload()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115249);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReloadComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115250);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginAReload()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115253);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int AddCarriedAmmo(int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115254);
			byte params[8] = { NULL };
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void UpdateReplicatedCarriedAmmo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115257);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartZoom(class UTPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115258);
			byte params[4] = { NULL };
			*(class UTPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndZoom(class UTPlayerController* PC, bool bReturningTo3P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115262);
			byte params[8] = { NULL };
			*(class UTPlayerController**)params = PC;
			*(bool*)&params[4] = bReturningTo3P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAltReticule()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115266);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetAltReticule()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115271);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
