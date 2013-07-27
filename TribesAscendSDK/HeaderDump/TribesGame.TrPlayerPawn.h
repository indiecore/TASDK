#pragma once
#include "TribesGame.TrPawn.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.SoundCue.h"
#include "TribesGame.TrAnimNodeBlendBy3pDevice.h"
#include "Engine.AnimNodeSequence.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.ParticleSystem.h"
#include "TribesGame.TrObject.h"
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
	class TrPlayerPawn : public TrPawn
	{
	public:
		ADD_STRUCT(byte, r_nFlashReloadPrimaryWeapon, 3212)
		ADD_STRUCT(byte, r_nFlashReloadSecondaryWeapon, 3213)
		ADD_OBJECT(TrAnimNodeBlendBy3pDevice, m_3pDeviceAnimNode, 3204)
		ADD_OBJECT(TrAnimNodeBlendBy3pDevice, m_1pBodyMeshDeviceAnimNode, 3208)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, m_JetpackPSCs, 3216)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, m_JetpackRibbonPSCs, 3228)
		ADD_STRUCT(ScriptArray<TrPawn::FootstepParticleInfo>, m_HardLandingParticles, 3240)
		ADD_STRUCT(ScriptArray<TrPawn::FootstepParticleInfo>, m_StepParticles, 3252)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, m_FootThrusterPSCs, 3268)
		ADD_STRUCT(ScriptArray<class AnimNodeSequence*>, m_MeshAnimSequenceNodes, 3436)
		ADD_STRUCT(float, BobGroundSpeedMultiplier2, 3432)
		ADD_STRUCT(float, BobGroundSpeedMultiplier1, 3428)
		ADD_STRUCT(float, BobTimeMultiplier, 3424)
		ADD_STRUCT(float, m_WeaponBobMultiplier2, 3420)
		ADD_STRUCT(float, m_WeaponBobMultiplier1, 3416)
		ADD_STRUCT(float, m_BobFootstepMultiplier, 3412)
		ADD_STRUCT(float, m_JumpBob5, 3408)
		ADD_STRUCT(float, m_JumpBob4, 3404)
		ADD_STRUCT(float, m_JumpBob3, 3400)
		ADD_STRUCT(float, m_JumpBob2, 3396)
		ADD_STRUCT(float, m_JumpBob1, 3392)
		ADD_STRUCT(float, m_EyeHeightLandingSkiingMultiplier2, 3388)
		ADD_STRUCT(float, m_EyeHeightLandingSkiingMultiplier, 3384)
		ADD_STRUCT(float, m_EyeHeightLandingSpeedSqThresholdSkiing, 3380)
		ADD_STRUCT(float, m_EyeHeightLandingSpeedSqThreshold, 3376)
		ADD_STRUCT(float, m_EyeHeightLandingMultiplier5, 3372)
		ADD_STRUCT(float, m_EyeHeightLandingMultiplier4, 3368)
		ADD_STRUCT(float, m_EyeHeightLandingMultiplier3, 3364)
		ADD_STRUCT(float, m_EyeHeightLandingMultiplier2, 3360)
		ADD_STRUCT(float, m_EyeHeightLandingMultiplier1, 3356)
		ADD_STRUCT(float, m_EyeHeightLandingMultiplier, 3352)
		ADD_STRUCT(float, m_EyeHeightLandingMinSmoothing, 3348)
		ADD_STRUCT(float, m_EyeHeightLandRecoveryMultiplier2, 3344)
		ADD_STRUCT(float, m_EyeHeightLandRecoveryMultiplier1, 3340)
		ADD_STRUCT(float, m_EyeHeightLandRecoveryMultiplier, 3336)
		ADD_STRUCT(float, m_EyeHeightLandRecoveryMinSmoothing, 3332)
		ADD_STRUCT(float, m_EyeHeightWalkingMultiplier, 3328)
		ADD_STRUCT(float, m_EyeHeightWalkingMinSmoothing, 3324)
		ADD_STRUCT(float, m_Cam3pZoomInSpeed, 3320)
		ADD_STRUCT(float, m_Cam3pZoomOutSpeed, 3316)
		ADD_OBJECT(Actor, m_DeathCamFocus, 3312)
		ADD_STRUCT(Object::Rotator, m_CamRotOffset, 3300)
		ADD_STRUCT(float, m_fRibbonZVelocity, 3296)
		ADD_OBJECT(ParticleSystem, m_SonicPunchEffect3p, 3292)
		ADD_OBJECT(ParticleSystem, m_SonicPunchEffect1p, 3288)
		ADD_OBJECT(SoundCue, m_SonicPunch3p, 3284)
		ADD_OBJECT(SoundCue, m_SonicPunch1p, 3280)
		ADD_OBJECT(ParticleSystem, m_DefaultSkiJetParticle, 3264)
		ADD_STRUCT(float, m_fJetpackSoundFadeOutTime, 3200)
		ADD_STRUCT(float, m_fRemainingJetpackSoundFadeOutTime, 3196)
		void SetCharacterClassFromInfo(ScriptClass* Info, bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.SetCharacterClassFromInfo");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = Info;
			*(bool*)&params[4] = bForce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateEyeHeight(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.UpdateEyeHeight");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptName GetMaterialBelowFeetByLoc(Object::Vector TestLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.GetMaterialBelowFeetByLoc");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = TestLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[12];
		}
		ScriptName GetMaterialBelowFeet()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.GetMaterialBelowFeet");
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[0];
		}
		void ActuallyPlayFootstepSound(int FootDown)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.ActuallyPlayFootstepSound");
			byte params[4] = { NULL };
			*(int*)&params[0] = FootDown;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector WeaponBob(float BobDamping, float JumpDamping)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.WeaponBob");
			byte params[20] = { NULL };
			*(float*)&params[0] = BobDamping;
			*(float*)&params[4] = JumpDamping;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[8];
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.PostInitAnimTree");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayHardLandingEffect(Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.PlayHardLandingEffect");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlaySonicPunchEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.PlaySonicPunchEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateSkiParticleEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.CreateSkiParticleEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearSkiParticleEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.ClearSkiParticleEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlaySkiEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.PlaySkiEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopSkiEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.StopSkiEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateJetpackParticleEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.CreateJetpackParticleEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearJetpackParticleEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.ClearJetpackParticleEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayJetpackEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.PlayJetpackEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateJetpackEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.UpdateJetpackEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopJetpackEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.StopJetpackEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayReload(TrObject::TR_EQUIP_POINT EquipPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.PlayReload");
			byte params[1] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)&params[0] = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CalcCamera(float fDeltaTime, Object::Vector& out_CamLoc, Object::Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.CalcCamera");
			byte params[36] = { NULL };
			*(float*)&params[0] = fDeltaTime;
			*(Object::Vector*)&params[4] = out_CamLoc;
			*(Object::Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Object::Vector*)&params[4];
			out_CamRot = *(Object::Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
			return *(bool*)&params[32];
		}
		void SetThirdPersonCamera(bool bNewBehindView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.SetThirdPersonCamera");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewBehindView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CalcThirdPersonCam(float fDeltaTime, Object::Vector& out_CamLoc, Object::Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.CalcThirdPersonCam");
			byte params[36] = { NULL };
			*(float*)&params[0] = fDeltaTime;
			*(Object::Vector*)&params[4] = out_CamLoc;
			*(Object::Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Object::Vector*)&params[4];
			out_CamRot = *(Object::Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
			return *(bool*)&params[32];
		}
		bool CalcOtherWatchingCam(float fDeltaTime, Object::Vector& out_CamLoc, Object::Rotator& out_CamRot, float& out_FOV, class TrPlayerController* WatcherController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.CalcOtherWatchingCam");
			byte params[40] = { NULL };
			*(float*)&params[0] = fDeltaTime;
			*(Object::Vector*)&params[4] = out_CamLoc;
			*(Object::Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			*(class TrPlayerController**)&params[32] = WatcherController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Object::Vector*)&params[4];
			out_CamRot = *(Object::Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
			return *(bool*)&params[36];
		}
		void ClearMeshAnimSeqNodes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.ClearMeshAnimSeqNodes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CacheMeshAnimSeqNodes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.CacheMeshAnimSeqNodes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SuppressAnimNotifies(bool bSuppress)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerPawn.SuppressAnimNotifies");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bSuppress;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
