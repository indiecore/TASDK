#pragma once
#include "Engine.ForceFeedbackWaveform.h"
#include "UDKBase.UDKPawn.h"
#include "Engine.Actor.h"
#include "UTGame.UTAnimBlendByHoverboarding.h"
#include "Core.Object.h"
#include "Engine.UIRoot.h"
#include "UTGame.UTAnimBlendByDriving.h"
#include "UTGame.UTSeqAct_ExitVehicle.h"
#include "UTGame.UTSeqAct_PlayAnim.h"
#include "UTGame.UTWeaponAttachment.h"
#include "Engine.Vehicle.h"
#include "Engine.AnimNodeBlend.h"
#include "UTGame.UTAnimBlendByVehicle.h"
#include "Engine.AnimNodeSlot.h"
#include "Engine.Texture.h"
#include "Engine.SoundCue.h"
#include "UTGame.UTPlayerController.h"
#include "Engine.CameraAnim.h"
#include "Engine.Teleporter.h"
#include "Engine.Material.h"
#include "UTGame.UTClientSideWeaponPawn.h"
#include "Engine.MaterialInterface.h"
#include "UTGame.UTProjectile.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "Engine.PhysicsVolume.h"
#include "UTGame.UTMapInfo.h"
#include "Engine.Canvas.h"
#include "Engine.SkeletalMesh.h"
#include "UTGame.UTSeqAct_UseHoverboard.h"
#include "Engine.Weapon.h"
#include "Engine.Pawn.h"
#include "Engine.Controller.h"
#include "Engine.SeqAct_ModifyHealth.h"
#include "Engine.PlayerController.h"
#include "UDKBase.UDKCarriedObject.h"
#include "UTGame.UTGib.h"
#include "Engine.HUD.h"
#include "UTGame.UTWeapon.h"
#include "Engine.SVehicle.h"
#include "UTGame.UTSeqAct_InfiniteAmmo.h"
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
	class UTPawn : public UDKPawn
	{
	public:
		static const float MINTIMEBETWEENPAINSOUNDS;
		enum EWeapAnimType : byte
		{
			EWAT_Default = 0,
			EWAT_Pistol = 1,
			EWAT_DualPistols = 2,
			EWAT_ShoulderRocket = 3,
			EWAT_Stinger = 4,
			EWAT_MAX = 5,
		};
		class GibInfo
		{
		public:
			ADD_OBJECT(ScriptClass, GibClass, 8)
			ADD_STRUCT(ScriptName, BoneName, 0)
			ADD_BOOL(bHighDetailOnly, 12, 0x1)
		};
		ADD_STRUCT(float, CurrentCameraScale, 1700)
		ADD_STRUCT(float, CameraScale, 1696)
		ADD_STRUCT(Object::Vector, WalkBob, 1780)
		ADD_STRUCT(float, VestArmor, 1876)
		ADD_STRUCT(float, ShieldBeltArmor, 1872)
		ADD_OBJECT(ScriptClass, HoverboardClass, 2072)
		ADD_BOOL(bIsInvulnerable, 1616, 0x40)
		ADD_BOOL(bFixedView, 1616, 0x1)
		ADD_STRUCT(Object::Vector, FixedViewLoc, 1672)
		ADD_STRUCT(Object::Rotator, FixedViewRot, 1684)
		ADD_STRUCT(float, LandBob, 1764)
		ADD_BOOL(bJustLanded, 1616, 0x400)
		ADD_BOOL(bLandRecovery, 1616, 0x800)
		ADD_BOOL(bArmsAttached, 1616, 0x20000)
		ADD_OBJECT(ScriptClass, CurrentWeaponAttachmentClass, 1620)
		ADD_BOOL(bStopDeathCamera, 1616, 0x2000)
		ADD_STRUCT(float, LastPainSound, 2052)
		ADD_STRUCT(float, MapSize, 2032)
		ADD_STRUCT(UIRoot::TextureCoordinates, IconCoords, 2036)
		ADD_OBJECT(UTWeaponAttachment, CurrentWeaponAttachment, 1884)
		ADD_OBJECT(ScriptClass, CurrCharClassInfo, 1812)
		ADD_STRUCT(ScriptArray<ScriptName>, TakeHitPhysicsFixedBones, 1816)
		ADD_OBJECT(ScriptClass, SoundGroupClass, 1808)
		ADD_STRUCT(float, DefaultMeshScale, 2116)
		ADD_STRUCT(ScriptArray<ScriptName>, NoDriveBodies, 1828)
		ADD_BOOL(bReceivedValidTeam, 1616, 0x200000)
		ADD_OBJECT(AnimNodeBlend, FeignDeathBlend, 1632)
		ADD_OBJECT(AnimNodeSlot, FullBodyAnimSlot, 1636)
		ADD_OBJECT(AnimNodeSlot, TopHalfAnimSlot, 1640)
		ADD_OBJECT(UTAnimBlendByDriving, DrivingNode, 1860)
		ADD_OBJECT(UTAnimBlendByVehicle, VehicleNode, 1864)
		ADD_OBJECT(UTAnimBlendByHoverboarding, HoverboardingNode, 1868)
		ADD_BOOL(bWeaponBob, 1616, 0x200)
		ADD_STRUCT(float, JumpBob, 1768)
		ADD_STRUCT(ScriptName, TauntNames, 2120)
		ADD_STRUCT(float, bobtime, 1776)
		ADD_STRUCT(float, Bob, 1760)
		ADD_STRUCT(float, AppliedBob, 1772)
		ADD_BOOL(bWeaponAttachmentVisible, 1616, 0x40000)
		ADD_BOOL(bSpawnDone, 1616, 0x2)
		ADD_BOOL(bSpawnIn, 1616, 0x4)
		ADD_STRUCT(Object::LinearColor, SpawnProtectionColor, 2008)
		ADD_OBJECT(SoundCue, SpawnSound, 2000)
		ADD_STRUCT(Object::LinearColor, TranslocateColor, 1952)
		ADD_OBJECT(SoundCue, TeleportSound, 2004)
		ADD_OBJECT(CameraAnim, TransCameraAnim, 1984)
		ADD_OBJECT(ScriptClass, TransInEffects, 1944)
		ADD_OBJECT(UTClientSideWeaponPawn, ClientSideWeaponPawn, 2088)
		ADD_STRUCT(float, ThighpadArmor, 1880)
		ADD_BOOL(bShieldAbsorb, 1616, 0x8)
		ADD_OBJECT(SoundCue, ArmorHitSound, 1996)
		ADD_BOOL(bJustDroppedOrb, 1616, 0x80)
		ADD_STRUCT(float, MaxFootstepDistSq, 2064)
		ADD_STRUCT(float, MaxJumpSoundDistSq, 2068)
		ADD_BOOL(bHeadGibbed, 1616, 0x10000)
		ADD_BOOL(bGibbed, 1616, 0x8000)
		ADD_STRUCT(float, DeathTime, 2200)
		ADD_BOOL(bForcedFeignDeath, 1616, 0x100)
		ADD_BOOL(bHideOnListenServer, 1616, 0x80000)
		ADD_STRUCT(float, DeathHipLinSpring, 1644)
		ADD_STRUCT(float, DeathHipLinDamp, 1648)
		ADD_STRUCT(float, DeathHipAngSpring, 1652)
		ADD_STRUCT(float, DeathHipAngDamp, 1656)
		ADD_STRUCT(float, StartDeathAnimTime, 1660)
		ADD_STRUCT(float, TimeLastTookDeathAnimDamage, 1668)
		ADD_OBJECT(ScriptClass, DeathAnimDamageType, 1664)
		ADD_STRUCT(float, CameraZOffset, 1724)
		ADD_BOOL(bWinnerCam, 1616, 0x4000)
		ADD_STRUCT(int, HeroCameraPitch, 1732)
		ADD_STRUCT(float, HeroCameraScale, 1728)
		ADD_STRUCT(Object::Vector, CamOffset, 2172)
		ADD_STRUCT(float, DodgeSpeed, 1736)
		ADD_STRUCT(float, DodgeSpeedZ, 1740)
		ADD_BOOL(bDodging, 1616, 0x10)
		ADD_STRUCT(int, JumpBootCharge, 2112)
		ADD_STRUCT(Actor::EDoubleClickDir, CurrentDir, 1744)
		ADD_STRUCT(float, DoubleJumpEyeHeight, 1748)
		ADD_STRUCT(float, DoubleJumpThreshold, 1752)
		ADD_BOOL(bStopOnDoubleLanding, 1616, 0x20)
		ADD_STRUCT(float, DefaultAirControl, 1756)
		ADD_OBJECT(MaterialInterface, ShieldBeltTeamMaterialInstances, 2096)
		ADD_OBJECT(MaterialInterface, ShieldBeltMaterialInstance, 2092)
		ADD_STRUCT(float, FeignDeathStartTime, 1796)
		ADD_STRUCT(float, FeignDeathBodyAtRestSpeed, 1792)
		ADD_STRUCT(int, UnfeignFailedCount, 1624)
		ADD_STRUCT(float, FeignDeathRecoveryStartTime, 1800)
		ADD_STRUCT(ScriptName, HeadBone, 1932)
		ADD_BOOL(bKillsAffectHead, 1616, 0x400000)
		ADD_STRUCT(UDKPawn::DrivenWeaponPawnInfo, LastDrivenWeaponPawn, 2076)
		ADD_OBJECT(ScriptClass, m_ClientSideWeaponPawnClass, 2204)
		ADD_OBJECT(UTProjectile, AttachedProj, 2060)
		ADD_STRUCT(float, AccumulationTime, 1848)
		ADD_STRUCT(float, AccumulateDamage, 1844)
		ADD_BOOL(bHasHoverboard, 1616, 0x1000)
		ADD_STRUCT(float, LastHoverboardTime, 1852)
		ADD_STRUCT(float, MinHoverboardInterval, 1856)
		ADD_STRUCT(float, HeadHeight, 1928)
		ADD_STRUCT(float, HeadRadius, 1924)
		ADD_STRUCT(float, CameraScaleMin, 1704)
		ADD_STRUCT(float, CameraScaleMax, 1708)
		ADD_OBJECT(ForceFeedbackWaveform, FallingDamageWaveForm, 1840)
		ADD_STRUCT(Object::Vector, OldCameraPosition, 1712)
		ADD_BOOL(bKilledByBio, 1616, 0x800000)
		ADD_STRUCT(float, BioBurnAwayTime, 2188)
		ADD_STRUCT(ScriptName, BioEffectName, 2192)
		ADD_STRUCT(float, RagdollLifespan, 2056)
		ADD_BOOL(bPostRenderTraceSucceeded, 1616, 0x100000)
		ADD_STRUCT(int, SuperHealthMax, 1804)
		ADD_STRUCT(ScriptName, WeaponSocket, 1888)
		ADD_STRUCT(ScriptName, WeaponSocket2, 1896)
		ADD_STRUCT(ScriptName, PawnEffectSockets, 1904)
		ADD_STRUCT(float, HeadOffset, 1920)
		ADD_STRUCT(float, TeamBeaconPlayerInfoMaxDist, 2024)
		ADD_OBJECT(Texture, SpeakingBeaconTexture, 2028)
		ADD_STRUCT(float, DesiredMeshScale, 2168)
		bool CanDoubleJump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.CanDoubleJump");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		Object::Vector WeaponBob(float BobDamping, float JumpDamping)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.WeaponBob");
			byte params[20] = { NULL };
			*(float*)&params[0] = BobDamping;
			*(float*)&params[4] = JumpDamping;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[8];
		}
		float GetEyeHeight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetEyeHeight");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		bool IsFirstPerson()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.IsFirstPerson");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void AdjustPPEffects(class UTPlayerController* PC, bool bRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.AdjustPPEffects");
			byte params[8] = { NULL };
			*(class UTPlayerController**)&params[0] = PC;
			*(bool*)&params[4] = bRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float AdjustedStrength()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.AdjustedStrength");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		class UTPlayerReplicationInfo* GetUTPlayerReplicationInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetUTPlayerReplicationInfo");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTPlayerReplicationInfo**)&params[0];
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.FellOutOfWorld");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HeadVolumeChange(class PhysicsVolume* newHeadVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.HeadVolumeChange");
			byte params[4] = { NULL };
			*(class PhysicsVolume**)&params[0] = newHeadVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PoweredUp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PoweredUp");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool InCombat()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.InCombat");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void RenderMapIcon(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, Object::LinearColor FinalColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.RenderMapIcon");
			byte params[28] = { NULL };
			*(class UTMapInfo**)&params[0] = MP;
			*(class Canvas**)&params[4] = Canvas;
			*(class UTPlayerController**)&params[8] = PlayerOwner;
			*(Object::LinearColor*)&params[12] = FinalColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetWalking(bool bNewIsWalking)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetWalking");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewIsWalking;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearBodyMatColor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ClearBodyMatColor");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetBodyMatColor(Object::LinearColor NewBodyMatColor, float NewOverlayDuration)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetBodyMatColor");
			byte params[20] = { NULL };
			*(Object::LinearColor*)&params[0] = NewBodyMatColor;
			*(float*)&params[16] = NewOverlayDuration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetInvisible(bool bNowInvisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetInvisible");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNowInvisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSkin(class Material* NewMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetSkin");
			byte params[4] = { NULL };
			*(class Material**)&params[0] = NewMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetArmsSkin(class MaterialInterface* NewMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetArmsSkin");
			byte params[4] = { NULL };
			*(class MaterialInterface**)&params[0] = NewMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool VerifyBodyMaterialInstance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.VerifyBodyMaterialInstance");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SetCharacterClassFromInfo(ScriptClass* Info, bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetCharacterClassFromInfo");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = Info;
			*(bool*)&params[4] = bForce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCharacterMeshInfo(class SkeletalMesh* SkelMesh, class MaterialInterface* HeadMaterial, class MaterialInterface* BodyMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetCharacterMeshInfo");
			byte params[12] = { NULL };
			*(class SkeletalMesh**)&params[0] = SkelMesh;
			*(class MaterialInterface**)&params[4] = HeadMaterial;
			*(class MaterialInterface**)&params[8] = BodyMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPawnRBChannels(bool bRagdollMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetPawnRBChannels");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bRagdollMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[8] = { NULL };
			*(class SkeletalMesh**)&params[0] = FirstPersonArmMesh;
			*(class MaterialInterface**)&params[4] = ArmMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWantShadow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHandIKEnabled(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetHandIKEnabled");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAnimRateScale(float RateScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetAnimRateScale");
			byte params[4] = { NULL };
			*(float*)&params[0] = RateScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetWeapAnimType(UTPawn::EWeapAnimType AnimType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetWeapAnimType");
			byte params[1] = { NULL };
			*(UTPawn::EWeapAnimType*)&params[0] = AnimType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LeaveABloodSplatterDecal(Object::Vector HitLoc, Object::Vector HitNorm)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.LeaveABloodSplatterDecal");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = HitLoc;
			*(Object::Vector*)&params[12] = HitNorm;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PerformEmoteCommand(UDKPawn::EmoteInfo EInfo, int PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PerformEmoteCommand");
			byte params[56] = { NULL };
			*(UDKPawn::EmoteInfo*)&params[0] = EInfo;
			*(int*)&params[52] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoPlayEmote(ScriptName InEmoteTag, int InPlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.DoPlayEmote");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = InEmoteTag;
			*(int*)&params[8] = InPlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerPlayEmote(ScriptName InEmoteTag, int InPlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ServerPlayEmote");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = InEmoteTag;
			*(int*)&params[8] = InPlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayEmote(ScriptName InEmoteTag, int InPlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PlayEmote");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = InEmoteTag;
			*(int*)&params[8] = InPlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPlayAnim(class UTSeqAct_PlayAnim* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.OnPlayAnim");
			byte params[4] = { NULL };
			*(class UTSeqAct_PlayAnim**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.EncroachedBy");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void gibbedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.gibbedBy");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void JumpOffPawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.JumpOffPawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StuckOnPawn(class Pawn* OtherPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.StuckOnPawn");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = OtherPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Falling()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.Falling");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddVelocity(Object::Vector NewVelocity, Object::Vector HitLocation, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.AddVelocity");
			byte params[56] = { NULL };
			*(Object::Vector*)&params[0] = NewVelocity;
			*(Object::Vector*)&params[12] = HitLocation;
			*(ScriptClass**)&params[24] = DamageType;
			*(Actor::TraceHitInfo*)&params[28] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.Died");
			byte params[24] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(ScriptClass**)&params[4] = DamageType;
			*(Object::Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.StartFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool StopFiring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.StopFiring");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool BotFire(bool bFinished)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.BotFire");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bFinished;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool StopWeaponFiring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.StopWeaponFiring");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		byte ChooseFireMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ChooseFireMode");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[0];
		}
		bool RecommendLongRangedAttack()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.RecommendLongRangedAttack");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		float RangedAttackTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.RangedAttackTime");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void PlayVictoryAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PlayVictoryAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnModifyHealth(class SeqAct_ModifyHealth* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.OnModifyHealth");
			byte params[4] = { NULL };
			*(class SeqAct_ModifyHealth**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetScreenName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetScreenName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void FaceRotation(Object::Rotator NewRotation, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.FaceRotation");
			byte params[16] = { NULL };
			*(Object::Rotator*)&params[0] = NewRotation;
			*(float*)&params[12] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateEyeHeight(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.UpdateEyeHeight");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector GetPawnViewLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetPawnViewLocation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		void BecomeViewTarget(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.BecomeViewTarget");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndViewTarget(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.EndViewTarget");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetWeaponVisibility(bool bWeaponVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetWeaponVisibility");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWeaponVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetWeaponAttachmentVisibility(bool bAttachmentVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetWeaponAttachmentVisibility");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bAttachmentVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMeshVisibility(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetMeshVisibility");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DeactivateSpawnProtection()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.DeactivateSpawnProtection");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayTeleportEffect(bool bOut, bool bSound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PlayTeleportEffect");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bOut;
			*(bool*)&params[4] = bSound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnTransEffect(int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SpawnTransEffect");
			byte params[4] = { NULL };
			*(int*)&params[0] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartDriving(class Vehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.StartDriving");
			byte params[4] = { NULL };
			*(class Vehicle**)&params[0] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopDriving(class Vehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.StopDriving");
			byte params[4] = { NULL };
			*(class Vehicle**)&params[0] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientRestart()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ClientRestart");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetShieldStrength()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetShieldStrength");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int AbsorbDamage(int& Damage, int CurrentShieldStrength, float AbsorptionRate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.AbsorbDamage");
			byte params[16] = { NULL };
			*(int*)&params[0] = Damage;
			*(int*)&params[4] = CurrentShieldStrength;
			*(float*)&params[8] = AbsorptionRate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Damage = *(int*)&params[0];
			return *(int*)&params[12];
		}
		int ShieldAbsorb(int Damage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ShieldAbsorb");
			byte params[8] = { NULL };
			*(int*)&params[0] = Damage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void AdjustDamage(int& InDamage, Object::Vector& Momentum, class Controller* InstigatedBy, Object::Vector HitLocation, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.AdjustDamage");
			byte params[68] = { NULL };
			*(int*)&params[0] = InDamage;
			*(Object::Vector*)&params[4] = Momentum;
			*(class Controller**)&params[16] = InstigatedBy;
			*(Object::Vector*)&params[20] = HitLocation;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InDamage = *(int*)&params[0];
			Momentum = *(Object::Vector*)&params[4];
		}
		void DropFlag(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.DropFlag");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableInventoryPickup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.EnableInventoryPickup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HoldGameObject(class UDKCarriedObject* GameObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.HoldGameObject");
			byte params[4] = { NULL };
			*(class UDKCarriedObject**)&params[0] = GameObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GiveHealth(int HealAmount, int HealMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GiveHealth");
			byte params[12] = { NULL };
			*(int*)&params[0] = HealAmount;
			*(int*)&params[4] = HealMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		ScriptString* GetDebugName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetDebugName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void PlayFootStepSound(int FootDown)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PlayFootStepSound");
			byte params[4] = { NULL };
			*(int*)&params[0] = FootDown;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ActuallyPlayFootstepSound(int FootDown)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ActuallyPlayFootstepSound");
			byte params[4] = { NULL };
			*(int*)&params[0] = FootDown;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptName GetMaterialBelowFeet()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetMaterialBelowFeet");
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[0];
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
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = UTDamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SpawnHeadGib(ScriptClass* UTDamageType, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SpawnHeadGib");
			byte params[16] = { NULL };
			*(ScriptClass**)&params[0] = UTDamageType;
			*(Object::Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class UTGib* SpawnGib(ScriptClass* GibClass, ScriptName BoneName, ScriptClass* UTDamageType, Object::Vector HitLocation, bool bSpinGib)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SpawnGib");
			byte params[36] = { NULL };
			*(ScriptClass**)&params[0] = GibClass;
			*(ScriptName*)&params[4] = BoneName;
			*(ScriptClass**)&params[12] = UTDamageType;
			*(Object::Vector*)&params[16] = HitLocation;
			*(bool*)&params[28] = bSpinGib;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTGib**)&params[32];
		}
		void SpawnGibs(ScriptClass* UTDamageType, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SpawnGibs");
			byte params[16] = { NULL };
			*(ScriptClass**)&params[0] = UTDamageType;
			*(Object::Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TurnOffPawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.TurnOffPawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayDying(ScriptClass* DamageType, Object::Vector HitLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PlayDying");
			byte params[16] = { NULL };
			*(ScriptClass**)&params[0] = DamageType;
			*(Object::Vector*)&params[4] = HitLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		bool CalcCamera(float fDeltaTime, Object::Vector& out_CamLoc, Object::Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.CalcCamera");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetThirdPersonCamera");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewBehindView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FindGoodEndView(class PlayerController* InPC, Object::Rotator& GoodRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.FindGoodEndView");
			byte params[16] = { NULL };
			*(class PlayerController**)&params[0] = InPC;
			*(Object::Rotator*)&params[4] = GoodRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			GoodRotation = *(Object::Rotator*)&params[4];
		}
		bool TryNewCamRot(class UTPlayerController* PC, Object::Rotator ViewRotation, float& CamDist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.TryNewCamRot");
			byte params[24] = { NULL };
			*(class UTPlayerController**)&params[0] = PC;
			*(Object::Rotator*)&params[4] = ViewRotation;
			*(float*)&params[16] = CamDist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CamDist = *(float*)&params[16];
			return *(bool*)&params[20];
		}
		void SetHeroCam(Object::Rotator& out_CamRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetHeroCam");
			byte params[12] = { NULL };
			*(Object::Rotator*)&params[0] = out_CamRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamRot = *(Object::Rotator*)&params[0];
		}
		bool CalcThirdPersonCam(float fDeltaTime, Object::Vector& out_CamLoc, Object::Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.CalcThirdPersonCam");
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
		Object::Vector GetWeaponStartTraceLocation(class Weapon* CurrentWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetWeaponStartTraceLocation");
			byte params[16] = { NULL };
			*(class Weapon**)&params[0] = CurrentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[4];
		}
		bool Dodge(Actor::EDoubleClickDir DoubleClickMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.Dodge");
			byte params[5] = { NULL };
			*(Actor::EDoubleClickDir*)&params[0] = DoubleClickMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		Object::Vector BotDodge(Object::Vector Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.BotDodge");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[12];
		}
		bool PerformDodge(Actor::EDoubleClickDir DoubleClickMove, Object::Vector Dir, Object::Vector Cross)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PerformDodge");
			byte params[29] = { NULL };
			*(Actor::EDoubleClickDir*)&params[0] = DoubleClickMove;
			*(Object::Vector*)&params[4] = Dir;
			*(Object::Vector*)&params[16] = Cross;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void DoDoubleJump(bool bUpdating)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.DoDoubleJump");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bUpdating;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[8] = { NULL };
			*(bool*)&params[0] = bUpdating;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void Landed(Object::Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.Landed");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void JumpOutOfWater(Object::Vector JumpDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.JumpOutOfWater");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = JumpDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanMultiJump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.CanMultiJump");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void PlayDyingSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PlayDyingSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void SetPawnAmbientSound(class SoundCue* NewAmbientSound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetPawnAmbientSound");
			byte params[4] = { NULL };
			*(class SoundCue**)&params[0] = NewAmbientSound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class SoundCue* GetPawnAmbientSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetPawnAmbientSound");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundCue**)&params[0];
		}
		void SetWeaponAmbientSound(class SoundCue* NewAmbientSound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetWeaponAmbientSound");
			byte params[4] = { NULL };
			*(class SoundCue**)&params[0] = NewAmbientSound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class SoundCue* GetWeaponAmbientSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetWeaponAmbientSound");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundCue**)&params[0];
		}
		void SetOverlayMaterial(class MaterialInterface* NewOverlay)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetOverlayMaterial");
			byte params[4] = { NULL };
			*(class MaterialInterface**)&params[0] = NewOverlay;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class MaterialInterface* GetShieldMaterialInstance(bool bTeamGame)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetShieldMaterialInstance");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bTeamGame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MaterialInterface**)&params[4];
		}
		class MaterialInterface* GetOverlayMaterial()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetOverlayMaterial");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MaterialInterface**)&params[0];
		}
		void SetWeaponOverlayFlag(byte FlagToSet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetWeaponOverlayFlag");
			byte params[1] = { NULL };
			params[0] = FlagToSet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearWeaponOverlayFlag(byte FlagToClear)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ClearWeaponOverlayFlag");
			byte params[1] = { NULL };
			params[0] = FlagToClear;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyWeaponOverlayFlags(byte NewFlags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ApplyWeaponOverlayFlags");
			byte params[1] = { NULL };
			params[0] = NewFlags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		bool SetFeignEndLocation(Object::Vector HitLocation, Object::Vector FeignLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetFeignEndLocation");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(Object::Vector*)&params[12] = FeignLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool CheckValidLocation(Object::Vector FeignLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.CheckValidLocation");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = FeignLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
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
			byte params[9] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			params[4] = InFiringMode;
			*(bool*)&params[8] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHeadScale(float NewScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetHeadScale");
			byte params[4] = { NULL };
			*(float*)&params[0] = NewScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPuttingDownWeapon(bool bNowPuttingDownWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetPuttingDownWeapon");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNowPuttingDownWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetPuttingDownWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetPuttingDownWeapon");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Object::Vector HitLocation, Object::Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.TakeDamage");
			byte params[68] = { NULL };
			*(int*)&params[0] = Damage;
			*(class Controller**)&params[4] = EventInstigator;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WeaponFired(class Weapon* InWeapon, bool bViaReplication, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.WeaponFired");
			byte params[20] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			*(Object::Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WeaponStoppedFiring(class Weapon* InWeapon, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.WeaponStoppedFiring");
			byte params[8] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WeaponChanged(class UTWeapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.WeaponChanged");
			byte params[4] = { NULL };
			*(class UTWeapon**)&params[0] = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WeaponAttachmentChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.WeaponAttachmentChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayHit(float Damage, class Controller* InstigatedBy, Object::Vector HitLocation, ScriptClass* DamageType, Object::Vector Momentum, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PlayHit");
			byte params[64] = { NULL };
			*(float*)&params[0] = Damage;
			*(class Controller**)&params[4] = InstigatedBy;
			*(Object::Vector*)&params[8] = HitLocation;
			*(ScriptClass**)&params[20] = DamageType;
			*(Object::Vector*)&params[24] = Momentum;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(class UTSeqAct_UseHoverboard**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchWeapon(byte NewGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SwitchWeapon");
			byte params[1] = { NULL };
			params[0] = NewGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDrowningDamage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.TakeDrowningDamage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsLocationOnHead(Actor::ImpactInfo& Impact, float AdditionalScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.IsLocationOnHead");
			byte params[88] = { NULL };
			*(Actor::ImpactInfo*)&params[0] = Impact;
			*(float*)&params[80] = AdditionalScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Impact = *(Actor::ImpactInfo*)&params[0];
			return *(bool*)&params[84];
		}
		void ModifyRotForDebugFreeCam(Object::Rotator& out_CamRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.ModifyRotForDebugFreeCam");
			byte params[12] = { NULL };
			*(Object::Rotator*)&params[0] = out_CamRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamRot = *(Object::Rotator*)&params[0];
		}
		void AdjustCameraScale(bool bMoveCameraIn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.AdjustCameraScale");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bMoveCameraIn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Rotator GetViewRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetViewRotation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[0];
		}
		void TornOff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.TornOff");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetOverlayVisibility(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.SetOverlayVisibility");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
void* OtherComponent, Actor::CollisionImpactData& RigidCollisionData, int ContactIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.RigidBodyCollision");
			byte params[48] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = HitComponent;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComponent;
			*(Actor::CollisionImpactData*)&params[8] = RigidCollisionData;
			*(int*)&params[44] = ContactIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			RigidCollisionData = *(Actor::CollisionImpactData*)&params[8];
		}
		void OnRanOver(class SVehicle* Vehicle, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* RunOverComponent, int WheelIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.OnRanOver");
			byte params[12] = { NULL };
			*(class SVehicle**)&params[0] = Vehicle;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = RunOverComponent;
			*(int*)&params[8] = WheelIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StuckFalling()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.StuckFalling");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnExitVehicle(class UTSeqAct_ExitVehicle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.OnExitVehicle");
			byte params[4] = { NULL };
			*(class UTSeqAct_ExitVehicle**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnInfiniteAmmo(class UTSeqAct_InfiniteAmmo* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.OnInfiniteAmmo");
			byte params[4] = { NULL };
			*(class UTSeqAct_InfiniteAmmo**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PossessedBy(class Controller* C, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PossessedBy");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = C;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool NeedToTurn(Object::Vector targ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.NeedToTurn");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = targ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		ScriptClass* GetFamilyInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.GetFamilyInfo");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[0];
		}
		void PostTeleport(class Teleporter* OutTeleporter)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PostTeleport");
			byte params[4] = { NULL };
			*(class Teleporter**)&params[0] = OutTeleporter;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBigTeleport()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawn.PostBigTeleport");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
	const float UTPawn::MINTIMEBETWEENPAINSOUNDS = 0.35f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
