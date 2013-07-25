#pragma once
#include "UTGame__UTVehicleWeapon.h"
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
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
