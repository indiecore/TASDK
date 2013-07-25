#pragma once
#include "UTGame__UTWeapon.h"
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
		ADD_STRUCT(::VectorProperty, m_vClientSideFireOffset, 0xFFFFFFFF
		ADD_OBJECT(TrDeviceContentData, m_ContentData)
		ADD_VAR(::StrProperty, m_sContentDataClassName, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrDevice.DeviceUpgrade' for the property named 'BaseMod'!
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo' for the property named 'm_InGamePaperDollInfo'!
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo' for the property named 'm_MainMenuPaperDollInfo'!
		ADD_STRUCT(::VectorProperty, m_TinyWeaponsOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fTimeBeforeInactiveReload, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastActiveTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nTetherCounter, 0xFFFFFFFF)
		ADD_OBJECT(AnimSet, m_NoAmmoAnimSet)
		ADD_VAR(::FloatProperty, m_fFireIntervalForLastShotInClip, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fClientSideHitLeeway, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_ZoomOverlayMaterial)
		ADD_VAR(::NameProperty, m_nmZoomMaterialEffectName, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vZoomMeshOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fZoomRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDesiredZoomFOV, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_ShotsFired, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vPositionPivotOffset, 0xFFFFFFFF
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
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
