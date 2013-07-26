#pragma once
#include "Engine.ForceFeedbackWaveform.h"
#include "UDKBase.UDKPawn.h"
#include "Engine.SeqAct_ModifyHealth.h"
#include "Core.Object.Vector.h"
#include "UTGame.UTAnimBlendByDriving.h"
#include "UTGame.UTSeqAct_ExitVehicle.h"
#include "UTGame.UTSeqAct_PlayAnim.h"
#include "UTGame.UTWeaponAttachment.h"
#include "Core.Object.Rotator.h"
#include "Engine.Vehicle.h"
#include "Engine.AnimNodeBlend.h"
#include "UTGame.UTWeapon.h"
#include "Engine.UIRoot.TextureCoordinates.h"
#include "UTGame.UTAnimBlendByVehicle.h"
#include "Engine.Actor.TraceHitInfo.h"
#include "Engine.AnimNodeSlot.h"
#include "Engine.Actor.h"
#include "UTGame.UTAnimBlendByHoverboarding.h"
#include "Core.Object.LinearColor.h"
#include "Engine.Texture.h"
#include "Engine.SoundCue.h"
#include "UTGame.UTPlayerController.h"
#include "Engine.CameraAnim.h"
#include "Engine.Teleporter.h"
#include "Engine.Material.h"
#include "UTGame.UTClientSideWeaponPawn.h"
#include "UDKBase.UDKPawn.EmoteInfo.h"
#include "Engine.MaterialInterface.h"
#include "UDKBase.UDKPawn.DrivenWeaponPawnInfo.h"
#include "UTGame.UTProjectile.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "Engine.PhysicsVolume.h"
#include "UTGame.UTMapInfo.h"
#include "Engine.Canvas.h"
#include "Engine.SkeletalMesh.h"
#include "UTGame.UTSeqAct_UseHoverboard.h"
#include "Engine.Weapon.h"
#include "Engine.Pawn.h"
#include "Engine.Actor.ImpactInfo.h"
#include "Engine.Controller.h"
#include "Engine.PlayerController.h"
#include "UDKBase.UDKCarriedObject.h"
#include "UTGame.UTGib.h"
#include "Engine.HUD.h"
#include "Engine.Actor.CollisionImpactData.h"
#include "Engine.SVehicle.h"
#include "UTGame.UTSeqAct_InfiniteAmmo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTPawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTPawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTPawn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTPawn : public UDKPawn
	{
	public:
		ADD_VAR(::FloatProperty, CurrentCameraScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraScale, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, WalkBob, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VestArmor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ShieldBeltArmor, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, HoverboardClass)
		ADD_VAR(::BoolProperty, bIsInvulnerable, 0x40)
		ADD_VAR(::BoolProperty, bFixedView, 0x1)
		ADD_STRUCT(::VectorProperty, FixedViewLoc, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, FixedViewRot, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LandBob, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bJustLanded, 0x400)
		ADD_VAR(::BoolProperty, bLandRecovery, 0x800)
		ADD_VAR(::BoolProperty, bArmsAttached, 0x20000)
		ADD_OBJECT(ScriptClass, CurrentWeaponAttachmentClass)
		ADD_VAR(::BoolProperty, bStopDeathCamera, 0x2000)
		ADD_VAR(::FloatProperty, LastPainSound, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MapSize, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, IconCoords, 0xFFFFFFFF)
		ADD_OBJECT(UTWeaponAttachment, CurrentWeaponAttachment)
		ADD_OBJECT(ScriptClass, CurrCharClassInfo)
		ADD_OBJECT(ScriptClass, SoundGroupClass)
		ADD_VAR(::FloatProperty, DefaultMeshScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bReceivedValidTeam, 0x200000)
		ADD_OBJECT(AnimNodeBlend, FeignDeathBlend)
		ADD_OBJECT(AnimNodeSlot, FullBodyAnimSlot)
		ADD_OBJECT(AnimNodeSlot, TopHalfAnimSlot)
		ADD_OBJECT(UTAnimBlendByDriving, DrivingNode)
		ADD_OBJECT(UTAnimBlendByVehicle, VehicleNode)
		ADD_OBJECT(UTAnimBlendByHoverboarding, HoverboardingNode)
		ADD_VAR(::BoolProperty, bWeaponBob, 0x200)
		ADD_VAR(::FloatProperty, JumpBob, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, TauntNames, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, bobtime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Bob, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AppliedBob, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWeaponAttachmentVisible, 0x40000)
		ADD_VAR(::BoolProperty, bSpawnDone, 0x2)
		ADD_VAR(::BoolProperty, bSpawnIn, 0x4)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, SpawnProtectionColor, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, SpawnSound)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, TranslocateColor, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, TeleportSound)
		ADD_OBJECT(CameraAnim, TransCameraAnim)
		ADD_OBJECT(ScriptClass, TransInEffects)
		ADD_OBJECT(UTClientSideWeaponPawn, ClientSideWeaponPawn)
		ADD_VAR(::FloatProperty, ThighpadArmor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShieldAbsorb, 0x8)
		ADD_OBJECT(SoundCue, ArmorHitSound)
		ADD_VAR(::BoolProperty, bJustDroppedOrb, 0x80)
		ADD_VAR(::FloatProperty, MaxFootstepDistSq, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxJumpSoundDistSq, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHeadGibbed, 0x10000)
		ADD_VAR(::BoolProperty, bGibbed, 0x8000)
		ADD_VAR(::FloatProperty, DeathTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForcedFeignDeath, 0x100)
		ADD_VAR(::BoolProperty, bHideOnListenServer, 0x80000)
		ADD_VAR(::FloatProperty, DeathHipLinSpring, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeathHipLinDamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeathHipAngSpring, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeathHipAngDamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StartDeathAnimTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeLastTookDeathAnimDamage, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, DeathAnimDamageType)
		ADD_VAR(::FloatProperty, CameraZOffset, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWinnerCam, 0x4000)
		ADD_VAR(::IntProperty, HeroCameraPitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HeroCameraScale, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, CamOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DodgeSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DodgeSpeedZ, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDodging, 0x10)
		ADD_VAR(::IntProperty, JumpBootCharge, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CurrentDir, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DoubleJumpEyeHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DoubleJumpThreshold, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bStopOnDoubleLanding, 0x20)
		ADD_VAR(::FloatProperty, DefaultAirControl, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, ShieldBeltTeamMaterialInstances)
		ADD_OBJECT(MaterialInterface, ShieldBeltMaterialInstance)
		ADD_VAR(::FloatProperty, FeignDeathStartTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FeignDeathBodyAtRestSpeed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, UnfeignFailedCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FeignDeathRecoveryStartTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, HeadBone, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bKillsAffectHead, 0x400000)
		ADD_STRUCT(::NonArithmeticProperty<DrivenWeaponPawnInfo>, LastDrivenWeaponPawn, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, m_ClientSideWeaponPawnClass)
		ADD_OBJECT(UTProjectile, AttachedProj)
		ADD_VAR(::FloatProperty, AccumulationTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AccumulateDamage, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHasHoverboard, 0x1000)
		ADD_VAR(::FloatProperty, LastHoverboardTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinHoverboardInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HeadHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HeadRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraScaleMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraScaleMax, 0xFFFFFFFF)
		ADD_OBJECT(ForceFeedbackWaveform, FallingDamageWaveForm)
		ADD_STRUCT(::VectorProperty, OldCameraPosition, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bKilledByBio, 0x800000)
		ADD_VAR(::FloatProperty, BioBurnAwayTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BioEffectName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RagdollLifespan, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPostRenderTraceSucceeded, 0x100000)
		ADD_VAR(::IntProperty, SuperHealthMax, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, WeaponSocket, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, WeaponSocket2, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, PawnEffectSockets, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HeadOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TeamBeaconPlayerInfoMaxDist, 0xFFFFFFFF)
		ADD_OBJECT(Texture, SpeakingBeaconTexture)
		ADD_VAR(::FloatProperty, DesiredMeshScale, 0xFFFFFFFF)
		bool CanDoubleJump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.CanDoubleJump");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		Vector WeaponBob(float BobDamping, float JumpDamping)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.WeaponBob");
			byte* params = (byte*)malloc(20);
			*(float*)params = BobDamping;
			*(float*)(params + 4) = JumpDamping;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 8);
			free(params);
			return returnVal;
		}
		float GetEyeHeight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetEyeHeight");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		bool IsFirstPerson()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.IsFirstPerson");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void AdjustPPEffects(class UTPlayerController* PC, bool bRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.AdjustPPEffects");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerController**)params = PC;
			*(bool*)(params + 4) = bRemove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float AdjustedStrength()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.AdjustedStrength");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		class UTPlayerReplicationInfo* GetUTPlayerReplicationInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetUTPlayerReplicationInfo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTPlayerReplicationInfo**)params;
			free(params);
			return returnVal;
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.FellOutOfWorld");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HeadVolumeChange(class PhysicsVolume* newHeadVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.HeadVolumeChange");
			byte* params = (byte*)malloc(4);
			*(class PhysicsVolume**)params = newHeadVolume;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool PoweredUp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PoweredUp");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool InCombat()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.InCombat");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void RenderMapIcon(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, LinearColor FinalColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.RenderMapIcon");
			byte* params = (byte*)malloc(28);
			*(class UTMapInfo**)params = MP;
			*(class Canvas**)(params + 4) = Canvas;
			*(class UTPlayerController**)(params + 8) = PlayerOwner;
			*(LinearColor*)(params + 12) = FinalColor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetWalking(bool bNewIsWalking)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetWalking");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewIsWalking;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearBodyMatColor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ClearBodyMatColor");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetBodyMatColor(LinearColor NewBodyMatColor, float NewOverlayDuration)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetBodyMatColor");
			byte* params = (byte*)malloc(20);
			*(LinearColor*)params = NewBodyMatColor;
			*(float*)(params + 16) = NewOverlayDuration;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetInvisible(bool bNowInvisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetInvisible");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNowInvisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSkin(class Material* NewMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetSkin");
			byte* params = (byte*)malloc(4);
			*(class Material**)params = NewMaterial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetArmsSkin(class MaterialInterface* NewMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetArmsSkin");
			byte* params = (byte*)malloc(4);
			*(class MaterialInterface**)params = NewMaterial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool VerifyBodyMaterialInstance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.VerifyBodyMaterialInstance");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetCharacterClassFromInfo(ScriptClass* Info, bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetCharacterClassFromInfo");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = Info;
			*(bool*)(params + 4) = bForce;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCharacterMeshInfo(class SkeletalMesh* SkelMesh, class MaterialInterface* HeadMaterial, class MaterialInterface* BodyMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetCharacterMeshInfo");
			byte* params = (byte*)malloc(12);
			*(class SkeletalMesh**)params = SkelMesh;
			*(class MaterialInterface**)(params + 4) = HeadMaterial;
			*(class MaterialInterface**)(params + 8) = BodyMaterial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPawnRBChannels(bool bRagdollMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetPawnRBChannels");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bRagdollMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetCharPhysState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ResetCharPhysState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyTeamChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.NotifyTeamChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFirstPersonArmsInfo(class SkeletalMesh* FirstPersonArmMesh, class MaterialInterface* ArmMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetFirstPersonArmsInfo");
			byte* params = (byte*)malloc(8);
			*(class SkeletalMesh**)params = FirstPersonArmMesh;
			*(class MaterialInterface**)(params + 4) = ArmMaterial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetTeamColor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetTeamColor");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateShadowSettings(bool bWantShadow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.UpdateShadowSettings");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWantShadow;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReattachMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ReattachMesh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetHandIKEnabled(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetHandIKEnabled");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAnimRateScale(float RateScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetAnimRateScale");
			byte* params = (byte*)malloc(4);
			*(float*)params = RateScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetWeapAnimType(byte AnimType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetWeapAnimType");
			byte* params = (byte*)malloc(1);
			*params = AnimType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LeaveABloodSplatterDecal(Vector HitLoc, Vector HitNorm)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.LeaveABloodSplatterDecal");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLoc;
			*(Vector*)(params + 12) = HitNorm;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PerformEmoteCommand(EmoteInfo EInfo, int PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PerformEmoteCommand");
			byte* params = (byte*)malloc(56);
			*(EmoteInfo*)params = EInfo;
			*(int*)(params + 52) = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DoPlayEmote(ScriptName InEmoteTag, int InPlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.DoPlayEmote");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = InEmoteTag;
			*(int*)(params + 8) = InPlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerPlayEmote(ScriptName InEmoteTag, int InPlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ServerPlayEmote");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = InEmoteTag;
			*(int*)(params + 8) = InPlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayEmote(ScriptName InEmoteTag, int InPlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PlayEmote");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = InEmoteTag;
			*(int*)(params + 8) = InPlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPlayAnim(class UTSeqAct_PlayAnim* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.OnPlayAnim");
			byte* params = (byte*)malloc(4);
			*(class UTSeqAct_PlayAnim**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpawnDefaultController()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SpawnDefaultController");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TurnOff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.TurnOff");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool EncroachingOn(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.EncroachingOn");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.EncroachedBy");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void gibbedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.gibbedBy");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void JumpOffPawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.JumpOffPawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StuckOnPawn(class Pawn* OtherPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.StuckOnPawn");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = OtherPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Falling()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.Falling");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddVelocity(Vector NewVelocity, Vector HitLocation, ScriptClass* DamageType, TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.AddVelocity");
			byte* params = (byte*)malloc(56);
			*(Vector*)params = NewVelocity;
			*(Vector*)(params + 12) = HitLocation;
			*(ScriptClass**)(params + 24) = DamageType;
			*(TraceHitInfo*)(params + 28) = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.Died");
			byte* params = (byte*)malloc(24);
			*(class Controller**)params = Killer;
			*(ScriptClass**)(params + 4) = DamageType;
			*(Vector*)(params + 8) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.StartFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool StopFiring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.StopFiring");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool BotFire(bool bFinished)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.BotFire");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bFinished;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool StopWeaponFiring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.StopWeaponFiring");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		byte ChooseFireMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ChooseFireMode");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		bool RecommendLongRangedAttack()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.RecommendLongRangedAttack");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		float RangedAttackTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.RangedAttackTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void PlayVictoryAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PlayVictoryAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnModifyHealth(class SeqAct_ModifyHealth* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.OnModifyHealth");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_ModifyHealth**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetScreenName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetScreenName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void FaceRotation(Rotator NewRotation, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.FaceRotation");
			byte* params = (byte*)malloc(16);
			*(Rotator*)params = NewRotation;
			*(float*)(params + 12) = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateEyeHeight(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.UpdateEyeHeight");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector GetPawnViewLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetPawnViewLocation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		void BecomeViewTarget(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.BecomeViewTarget");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndViewTarget(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.EndViewTarget");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetWeaponVisibility(bool bWeaponVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetWeaponVisibility");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWeaponVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetWeaponAttachmentVisibility(bool bAttachmentVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetWeaponAttachmentVisibility");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bAttachmentVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMeshVisibility(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetMeshVisibility");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DeactivateSpawnProtection()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.DeactivateSpawnProtection");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayTeleportEffect(bool bOut, bool bSound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PlayTeleportEffect");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bOut;
			*(bool*)(params + 4) = bSound;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpawnTransEffect(int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SpawnTransEffect");
			byte* params = (byte*)malloc(4);
			*(int*)params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartDriving(class Vehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.StartDriving");
			byte* params = (byte*)malloc(4);
			*(class Vehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopDriving(class Vehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.StopDriving");
			byte* params = (byte*)malloc(4);
			*(class Vehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientRestart()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ClientRestart");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetShieldStrength()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetShieldStrength");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int AbsorbDamage(int& Damage, int CurrentShieldStrength, float AbsorptionRate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.AbsorbDamage");
			byte* params = (byte*)malloc(16);
			*(int*)params = Damage;
			*(int*)(params + 4) = CurrentShieldStrength;
			*(float*)(params + 8) = AbsorptionRate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Damage = *(int*)params;
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		int ShieldAbsorb(int Damage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ShieldAbsorb");
			byte* params = (byte*)malloc(8);
			*(int*)params = Damage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void AdjustDamage(int& InDamage, Vector& Momentum, class Controller* InstigatedBy, Vector HitLocation, ScriptClass* DamageType, TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.AdjustDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = InDamage;
			*(Vector*)(params + 4) = Momentum;
			*(class Controller**)(params + 16) = InstigatedBy;
			*(Vector*)(params + 20) = HitLocation;
			*(ScriptClass**)(params + 32) = DamageType;
			*(TraceHitInfo*)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InDamage = *(int*)params;
			Momentum = *(Vector*)(params + 4);
			free(params);
		}
		void DropFlag(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.DropFlag");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableInventoryPickup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.EnableInventoryPickup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HoldGameObject(class UDKCarriedObject* GameObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.HoldGameObject");
			byte* params = (byte*)malloc(4);
			*(class UDKCarriedObject**)params = GameObj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GiveHealth(int HealAmount, int HealMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GiveHealth");
			byte* params = (byte*)malloc(12);
			*(int*)params = HealAmount;
			*(int*)(params + 4) = HealMax;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetDebugName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetDebugName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void PlayFootStepSound(int FootDown)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PlayFootStepSound");
			byte* params = (byte*)malloc(4);
			*(int*)params = FootDown;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ActuallyPlayFootstepSound(int FootDown)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ActuallyPlayFootstepSound");
			byte* params = (byte*)malloc(4);
			*(int*)params = FootDown;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptName GetMaterialBelowFeet()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetMaterialBelowFeet");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)params;
			free(params);
			return returnVal;
		}
		void PlayLandingSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PlayLandingSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayJumpingSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PlayJumpingSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldGib(ScriptClass* UTDamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ShouldGib");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = UTDamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SpawnHeadGib(ScriptClass* UTDamageType, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SpawnHeadGib");
			byte* params = (byte*)malloc(16);
			*(ScriptClass**)params = UTDamageType;
			*(Vector*)(params + 4) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class UTGib* SpawnGib(ScriptClass* GibClass, ScriptName BoneName, ScriptClass* UTDamageType, Vector HitLocation, bool bSpinGib)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SpawnGib");
			byte* params = (byte*)malloc(36);
			*(ScriptClass**)params = GibClass;
			*(ScriptName*)(params + 4) = BoneName;
			*(ScriptClass**)(params + 12) = UTDamageType;
			*(Vector*)(params + 16) = HitLocation;
			*(bool*)(params + 28) = bSpinGib;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTGib**)(params + 32);
			free(params);
			return returnVal;
		}
		void SpawnGibs(ScriptClass* UTDamageType, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SpawnGibs");
			byte* params = (byte*)malloc(16);
			*(ScriptClass**)params = UTDamageType;
			*(Vector*)(params + 4) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TurnOffPawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.TurnOffPawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayDying(ScriptClass* DamageType, Vector HitLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PlayDying");
			byte* params = (byte*)malloc(16);
			*(ScriptClass**)params = DamageType;
			*(Vector*)(params + 4) = HitLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DoingDeathAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.DoingDeathAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddDefaultInventory()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.AddDefaultInventory");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CalcCamera(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.CalcCamera");
			byte* params = (byte*)malloc(36);
			*(float*)params = fDeltaTime;
			*(Vector*)(params + 4) = out_CamLoc;
			*(Rotator*)(params + 16) = out_CamRot;
			*(float*)(params + 28) = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_CamLoc = *(Vector*)(params + 4);
			out_CamRot = *(Rotator*)(params + 16);
			out_FOV = *(float*)(params + 28);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		void SetThirdPersonCamera(bool bNewBehindView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetThirdPersonCamera");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewBehindView;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FindGoodEndView(class PlayerController* InPC, Rotator& GoodRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.FindGoodEndView");
			byte* params = (byte*)malloc(16);
			*(class PlayerController**)params = InPC;
			*(Rotator*)(params + 4) = GoodRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			GoodRotation = *(Rotator*)(params + 4);
			free(params);
		}
		bool TryNewCamRot(class UTPlayerController* PC, Rotator ViewRotation, float& CamDist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.TryNewCamRot");
			byte* params = (byte*)malloc(24);
			*(class UTPlayerController**)params = PC;
			*(Rotator*)(params + 4) = ViewRotation;
			*(float*)(params + 16) = CamDist;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			CamDist = *(float*)(params + 16);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		void SetHeroCam(Rotator& out_CamRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetHeroCam");
			byte* params = (byte*)malloc(12);
			*(Rotator*)params = out_CamRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_CamRot = *(Rotator*)params;
			free(params);
		}
		bool CalcThirdPersonCam(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.CalcThirdPersonCam");
			byte* params = (byte*)malloc(36);
			*(float*)params = fDeltaTime;
			*(Vector*)(params + 4) = out_CamLoc;
			*(Rotator*)(params + 16) = out_CamRot;
			*(float*)(params + 28) = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_CamLoc = *(Vector*)(params + 4);
			out_CamRot = *(Rotator*)(params + 16);
			out_FOV = *(float*)(params + 28);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		Vector GetWeaponStartTraceLocation(class Weapon* CurrentWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetWeaponStartTraceLocation");
			byte* params = (byte*)malloc(16);
			*(class Weapon**)params = CurrentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 4);
			free(params);
			return returnVal;
		}
		bool Dodge(byte DoubleClickMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.Dodge");
			byte* params = (byte*)malloc(5);
			*params = DoubleClickMove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		Vector BotDodge(Vector Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.BotDodge");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = Dir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		bool PerformDodge(byte DoubleClickMove, Vector Dir, Vector Cross)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PerformDodge");
			byte* params = (byte*)malloc(29);
			*params = DoubleClickMove;
			*(Vector*)(params + 4) = Dir;
			*(Vector*)(params + 16) = Cross;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void DoDoubleJump(bool bUpdating)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.DoDoubleJump");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bUpdating;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Gasp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.Gasp");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFlying()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.StartFlying");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopFlying()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.StopFlying");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DoJump(bool bUpdating)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.DoJump");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bUpdating;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void Landed(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.Landed");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void JumpOutOfWater(Vector JumpDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.JumpOutOfWater");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = JumpDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanMultiJump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.CanMultiJump");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PlayDyingSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PlayDyingSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		void SetPawnAmbientSound(class SoundCue* NewAmbientSound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetPawnAmbientSound");
			byte* params = (byte*)malloc(4);
			*(class SoundCue**)params = NewAmbientSound;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class SoundCue* GetPawnAmbientSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetPawnAmbientSound");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SoundCue**)params;
			free(params);
			return returnVal;
		}
		void SetWeaponAmbientSound(class SoundCue* NewAmbientSound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetWeaponAmbientSound");
			byte* params = (byte*)malloc(4);
			*(class SoundCue**)params = NewAmbientSound;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class SoundCue* GetWeaponAmbientSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetWeaponAmbientSound");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SoundCue**)params;
			free(params);
			return returnVal;
		}
		void SetOverlayMaterial(class MaterialInterface* NewOverlay)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetOverlayMaterial");
			byte* params = (byte*)malloc(4);
			*(class MaterialInterface**)params = NewOverlay;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class MaterialInterface* GetShieldMaterialInstance(bool bTeamGame)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetShieldMaterialInstance");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bTeamGame;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class MaterialInterface**)(params + 4);
			free(params);
			return returnVal;
		}
		class MaterialInterface* GetOverlayMaterial()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetOverlayMaterial");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class MaterialInterface**)params;
			free(params);
			return returnVal;
		}
		void SetWeaponOverlayFlag(byte FlagToSet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetWeaponOverlayFlag");
			byte* params = (byte*)malloc(1);
			*params = FlagToSet;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearWeaponOverlayFlag(byte FlagToClear)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ClearWeaponOverlayFlag");
			byte* params = (byte*)malloc(1);
			*params = FlagToClear;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ApplyWeaponOverlayFlags(byte NewFlags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ApplyWeaponOverlayFlags");
			byte* params = (byte*)malloc(1);
			*params = NewFlags;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartFeignDeathRecoveryAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.StartFeignDeathRecoveryAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FeignDeathDelayTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.FeignDeathDelayTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayFeignDeath()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PlayFeignDeath");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool SetFeignEndLocation(Vector HitLocation, Vector FeignLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetFeignEndLocation");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = FeignLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool CheckValidLocation(Vector FeignLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.CheckValidLocation");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = FeignLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void ServerFeignDeath()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ServerFeignDeath");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FeignDeath()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.FeignDeath");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceRagdoll()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ForceRagdoll");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FiringModeUpdated(class Weapon* InWeapon, byte InFiringMode, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.FiringModeUpdated");
			byte* params = (byte*)malloc(9);
			*(class Weapon**)params = InWeapon;
			*(params + 4) = InFiringMode;
			*(bool*)(params + 8) = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBigHead()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetBigHead");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FireRateChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.FireRateChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetHeadScale(float NewScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetHeadScale");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPuttingDownWeapon(bool bNowPuttingDownWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetPuttingDownWeapon");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNowPuttingDownWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetPuttingDownWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetPuttingDownWeapon");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.TakeDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = Damage;
			*(class Controller**)(params + 4) = EventInstigator;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			*(TraceHitInfo*)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WeaponFired(class Weapon* InWeapon, bool bViaReplication, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.WeaponFired");
			byte* params = (byte*)malloc(20);
			*(class Weapon**)params = InWeapon;
			*(bool*)(params + 4) = bViaReplication;
			*(Vector*)(params + 8) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WeaponStoppedFiring(class Weapon* InWeapon, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.WeaponStoppedFiring");
			byte* params = (byte*)malloc(8);
			*(class Weapon**)params = InWeapon;
			*(bool*)(params + 4) = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WeaponChanged(class UTWeapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.WeaponChanged");
			byte* params = (byte*)malloc(4);
			*(class UTWeapon**)params = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WeaponAttachmentChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.WeaponAttachmentChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayHit(float Damage, class Controller* InstigatedBy, Vector HitLocation, ScriptClass* DamageType, Vector Momentum, TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PlayHit");
			byte* params = (byte*)malloc(64);
			*(float*)params = Damage;
			*(class Controller**)(params + 4) = InstigatedBy;
			*(Vector*)(params + 8) = HitLocation;
			*(ScriptClass**)(params + 20) = DamageType;
			*(Vector*)(params + 24) = Momentum;
			*(TraceHitInfo*)(params + 36) = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayTakeHitEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PlayTakeHitEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeHitBlendedOut()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.TakeHitBlendedOut");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerHoverboard()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ServerHoverboard");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUseHoverboard(class UTSeqAct_UseHoverboard* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.OnUseHoverboard");
			byte* params = (byte*)malloc(4);
			*(class UTSeqAct_UseHoverboard**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SwitchWeapon(byte NewGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SwitchWeapon");
			byte* params = (byte*)malloc(1);
			*params = NewGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeDrowningDamage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.TakeDrowningDamage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsLocationOnHead(ImpactInfo& Impact, float AdditionalScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.IsLocationOnHead");
			byte* params = (byte*)malloc(88);
			*(ImpactInfo*)params = Impact;
			*(float*)(params + 80) = AdditionalScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Impact = *(ImpactInfo*)params;
			auto returnVal = *(bool*)(params + 84);
			free(params);
			return returnVal;
		}
		void ModifyRotForDebugFreeCam(Rotator& out_CamRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ModifyRotForDebugFreeCam");
			byte* params = (byte*)malloc(12);
			*(Rotator*)params = out_CamRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_CamRot = *(Rotator*)params;
			free(params);
		}
		void AdjustCameraScale(bool bMoveCameraIn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.AdjustCameraScale");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bMoveCameraIn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Rotator GetViewRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetViewRotation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)params;
			free(params);
			return returnVal;
		}
		void TornOff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.TornOff");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetOverlayVisibility(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetOverlayVisibility");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeFallingDamage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.TakeFallingDamage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RigidBodyCollision(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* HitComponent, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComponent, CollisionImpactData& RigidCollisionData, int ContactIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.RigidBodyCollision");
			byte* params = (byte*)malloc(48);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = HitComponent;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = OtherComponent;
			*(CollisionImpactData*)(params + 8) = RigidCollisionData;
			*(int*)(params + 44) = ContactIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			RigidCollisionData = *(CollisionImpactData*)(params + 8);
			free(params);
		}
		void OnRanOver(class SVehicle* Vehicle, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* RunOverComponent, int WheelIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.OnRanOver");
			byte* params = (byte*)malloc(12);
			*(class SVehicle**)params = Vehicle;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = RunOverComponent;
			*(int*)(params + 8) = WheelIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StuckFalling()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.StuckFalling");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnExitVehicle(class UTSeqAct_ExitVehicle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.OnExitVehicle");
			byte* params = (byte*)malloc(4);
			*(class UTSeqAct_ExitVehicle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnInfiniteAmmo(class UTSeqAct_InfiniteAmmo* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.OnInfiniteAmmo");
			byte* params = (byte*)malloc(4);
			*(class UTSeqAct_InfiniteAmmo**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PossessedBy(class Controller* C, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PossessedBy");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			*(bool*)(params + 4) = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool NeedToTurn(Vector targ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.NeedToTurn");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = targ;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptClass* GetFamilyInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetFamilyInfo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)params;
			free(params);
			return returnVal;
		}
		void PostTeleport(class Teleporter* OutTeleporter)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PostTeleport");
			byte* params = (byte*)malloc(4);
			*(class Teleporter**)params = OutTeleporter;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBigTeleport()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PostBigTeleport");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
