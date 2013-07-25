#pragma once
#include "TribesGame__TrPlayerController.h"
#include "TribesGame__TrAnimNodeBlendBy3pDevice.h"
#include "TribesGame__TrPawn.h"
#include "Engine__ParticleSystem.h"
#include "Engine__Actor.h"
#include "Engine__SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPlayerPawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrPlayerPawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPlayerPawn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPlayerPawn : public TrPawn
	{
	public:
		ADD_VAR(::ByteProperty, r_nFlashReloadPrimaryWeapon, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_nFlashReloadSecondaryWeapon, 0xFFFFFFFF)
		ADD_OBJECT(TrAnimNodeBlendBy3pDevice, m_3pDeviceAnimNode)
		ADD_OBJECT(TrAnimNodeBlendBy3pDevice, m_1pBodyMeshDeviceAnimNode)
		ADD_VAR(::FloatProperty, BobGroundSpeedMultiplier2, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BobGroundSpeedMultiplier1, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BobTimeMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_WeaponBobMultiplier2, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_WeaponBobMultiplier1, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_BobFootstepMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_JumpBob5, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_JumpBob4, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_JumpBob3, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_JumpBob2, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_JumpBob1, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_EyeHeightLandingSkiingMultiplier2, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_EyeHeightLandingSkiingMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_EyeHeightLandingSpeedSqThresholdSkiing, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_EyeHeightLandingSpeedSqThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_EyeHeightLandingMultiplier5, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_EyeHeightLandingMultiplier4, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_EyeHeightLandingMultiplier3, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_EyeHeightLandingMultiplier2, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_EyeHeightLandingMultiplier1, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_EyeHeightLandingMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_EyeHeightLandingMinSmoothing, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_EyeHeightLandRecoveryMultiplier2, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_EyeHeightLandRecoveryMultiplier1, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_EyeHeightLandRecoveryMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_EyeHeightLandRecoveryMinSmoothing, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_EyeHeightWalkingMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_EyeHeightWalkingMinSmoothing, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_Cam3pZoomInSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_Cam3pZoomOutSpeed, 0xFFFFFFFF)
		ADD_OBJECT(Actor, m_DeathCamFocus)
		ADD_STRUCT(::RotatorProperty, m_CamRotOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fRibbonZVelocity, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, m_SonicPunchEffect3p)
		ADD_OBJECT(ParticleSystem, m_SonicPunchEffect1p)
		ADD_OBJECT(SoundCue, m_SonicPunch3p)
		ADD_OBJECT(SoundCue, m_SonicPunch1p)
		ADD_OBJECT(ParticleSystem, m_DefaultSkiJetParticle)
		ADD_VAR(::FloatProperty, m_fJetpackSoundFadeOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRemainingJetpackSoundFadeOutTime, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'SetCharacterClassFromInfo'
		// Here lies the not-yet-implemented method 'UpdateEyeHeight'
		// Here lies the not-yet-implemented method 'GetMaterialBelowFeetByLoc'
		// Here lies the not-yet-implemented method 'GetMaterialBelowFeet'
		// Here lies the not-yet-implemented method 'ActuallyPlayFootstepSound'
		// Here lies the not-yet-implemented method 'WeaponBob'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'PlayHardLandingEffect'
		// Here lies the not-yet-implemented method 'PlaySonicPunchEffect'
		// Here lies the not-yet-implemented method 'CreateSkiParticleEffects'
		// Here lies the not-yet-implemented method 'ClearSkiParticleEffects'
		// Here lies the not-yet-implemented method 'PlaySkiEffects'
		// Here lies the not-yet-implemented method 'StopSkiEffects'
		// Here lies the not-yet-implemented method 'CreateJetpackParticleEffects'
		// Here lies the not-yet-implemented method 'ClearJetpackParticleEffects'
		// Here lies the not-yet-implemented method 'PlayJetpackEffects'
		// Here lies the not-yet-implemented method 'UpdateJetpackEffects'
		// Here lies the not-yet-implemented method 'StopJetpackEffects'
		// Here lies the not-yet-implemented method 'PlayReload'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'CalcCamera'
		// Here lies the not-yet-implemented method 'SetThirdPersonCamera'
		// Here lies the not-yet-implemented method 'CalcThirdPersonCam'
		// Here lies the not-yet-implemented method 'CalcOtherWatchingCam'
		// Here lies the not-yet-implemented method 'ClearMeshAnimSeqNodes'
		// Here lies the not-yet-implemented method 'CacheMeshAnimSeqNodes'
		// Here lies the not-yet-implemented method 'SuppressAnimNotifies'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
