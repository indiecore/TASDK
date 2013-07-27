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
		struct GibInfo
		{
		public:
			ADD_OBJECT(ScriptClass, GibClass, 8)
			ADD_STRUCT(ScriptName, BoneName, 0)
			ADD_BOOL(bHighDetailOnly, 12, 0x1)
		};
		ADD_STRUCT(float, CurrentCameraScale, 1700)
		ADD_STRUCT(float, CameraScale, 1696)
		ADD_STRUCT(Vector, WalkBob, 1780)
		ADD_STRUCT(float, VestArmor, 1876)
		ADD_STRUCT(float, ShieldBeltArmor, 1872)
		ADD_OBJECT(ScriptClass, HoverboardClass, 2072)
		ADD_BOOL(bIsInvulnerable, 1616, 0x40)
		ADD_BOOL(bFixedView, 1616, 0x1)
		ADD_STRUCT(Vector, FixedViewLoc, 1672)
		ADD_STRUCT(Rotator, FixedViewRot, 1684)
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
		ADD_STRUCT(Vector, CamOffset, 2172)
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
		ADD_STRUCT(Vector, OldCameraPosition, 1712)
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36507);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		Vector WeaponBob(float BobDamping, float JumpDamping)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40890);
			byte params[20] = { NULL };
			*(float*)params = BobDamping;
			*(float*)&params[4] = JumpDamping;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[8];
		}
		float GetEyeHeight()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40899);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		bool IsFirstPerson()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41310);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void AdjustPPEffects(class UTPlayerController* PC, bool bRemove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41359);
			byte params[8] = { NULL };
			*(class UTPlayerController**)params = PC;
			*(bool*)&params[4] = bRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float AdjustedStrength()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41363);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		class UTPlayerReplicationInfo* GetUTPlayerReplicationInfo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41365);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTPlayerReplicationInfo**)params;
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41368);
			byte params[4] = { NULL };
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HeadVolumeChange(class PhysicsVolume* newHeadVolume)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41371);
			byte params[4] = { NULL };
			*(class PhysicsVolume**)params = newHeadVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PoweredUp()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41373);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool InCombat()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41375);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void RenderMapIcon(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, Object::LinearColor FinalColor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41378);
			byte params[28] = { NULL };
			*(class UTMapInfo**)params = MP;
			*(class Canvas**)&params[4] = Canvas;
			*(class UTPlayerController**)&params[8] = PlayerOwner;
			*(Object::LinearColor*)&params[12] = FinalColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetWalking(bool bNewIsWalking)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41385);
			byte params[4] = { NULL };
			*(bool*)params = bNewIsWalking;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearBodyMatColor()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41387);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetBodyMatColor(Object::LinearColor NewBodyMatColor, float NewOverlayDuration)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41388);
			byte params[20] = { NULL };
			*(Object::LinearColor*)params = NewBodyMatColor;
			*(float*)&params[16] = NewOverlayDuration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetInvisible(bool bNowInvisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41391);
			byte params[4] = { NULL };
			*(bool*)params = bNowInvisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSkin(class Material* NewMaterial)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41393);
			byte params[4] = { NULL };
			*(class Material**)params = NewMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetArmsSkin(class MaterialInterface* NewMaterial)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41397);
			byte params[4] = { NULL };
			*(class MaterialInterface**)params = NewMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool VerifyBodyMaterialInstance()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41404);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetCharacterClassFromInfo(ScriptClass* Info, bool bForce)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41407);
			byte params[8] = { NULL };
			*(ScriptClass**)params = Info;
			*(bool*)&params[4] = bForce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCharacterMeshInfo(class SkeletalMesh* SkelMesh, class MaterialInterface* HeadMaterial, class MaterialInterface* BodyMaterial)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41437);
			byte params[12] = { NULL };
			*(class SkeletalMesh**)params = SkelMesh;
			*(class MaterialInterface**)&params[4] = HeadMaterial;
			*(class MaterialInterface**)&params[8] = BodyMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPawnRBChannels(bool bRagdollMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41441);
			byte params[4] = { NULL };
			*(bool*)params = bRagdollMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetCharPhysState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41443);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyTeamChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41445);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFirstPersonArmsInfo(class SkeletalMesh* FirstPersonArmMesh, class MaterialInterface* ArmMaterial)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41450);
			byte params[8] = { NULL };
			*(class SkeletalMesh**)params = FirstPersonArmMesh;
			*(class MaterialInterface**)&params[4] = ArmMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTeamColor()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41453);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41457);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateShadowSettings(bool bWantShadow)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41460);
			byte params[4] = { NULL };
			*(bool*)params = bWantShadow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReattachMesh()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41464);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41465);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHandIKEnabled(bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41473);
			byte params[4] = { NULL };
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAnimRateScale(float RateScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41475);
			byte params[4] = { NULL };
			*(float*)params = RateScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetWeapAnimType(UTPawn::EWeapAnimType AnimType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41477);
			byte params[1] = { NULL };
			*(UTPawn::EWeapAnimType*)params = AnimType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LeaveABloodSplatterDecal(Vector HitLoc, Vector HitNorm)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41480);
			byte params[24] = { NULL };
			*(Vector*)params = HitLoc;
			*(Vector*)&params[12] = HitNorm;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PerformEmoteCommand(UDKPawn::EmoteInfo EInfo, int PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41494);
			byte params[56] = { NULL };
			*(UDKPawn::EmoteInfo*)params = EInfo;
			*(int*)&params[52] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoPlayEmote(ScriptName InEmoteTag, int InPlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41503);
			byte params[12] = { NULL };
			*(ScriptName*)params = InEmoteTag;
			*(int*)&params[8] = InPlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerPlayEmote(ScriptName InEmoteTag, int InPlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41513);
			byte params[12] = { NULL };
			*(ScriptName*)params = InEmoteTag;
			*(int*)&params[8] = InPlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayEmote(ScriptName InEmoteTag, int InPlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41516);
			byte params[12] = { NULL };
			*(ScriptName*)params = InEmoteTag;
			*(int*)&params[8] = InPlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPlayAnim(class UTSeqAct_PlayAnim* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41519);
			byte params[4] = { NULL };
			*(class UTSeqAct_PlayAnim**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnDefaultController()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41542);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TurnOff()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41553);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool EncroachingOn(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41554);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41557);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void gibbedBy(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41560);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void JumpOffPawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41564);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StuckOnPawn(class Pawn* OtherPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41565);
			byte params[4] = { NULL };
			*(class Pawn**)params = OtherPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Falling()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41567);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddVelocity(Vector NewVelocity, Vector HitLocation, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41568);
			byte params[56] = { NULL };
			*(Vector*)params = NewVelocity;
			*(Vector*)&params[12] = HitLocation;
			*(ScriptClass**)&params[24] = DamageType;
			*(Actor::TraceHitInfo*)&params[28] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41574);
			byte params[24] = { NULL };
			*(class Controller**)params = Killer;
			*(ScriptClass**)&params[4] = DamageType;
			*(Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41579);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool StopFiring()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41581);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool BotFire(bool bFinished)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41583);
			byte params[8] = { NULL };
			*(bool*)params = bFinished;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool StopWeaponFiring()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41588);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		byte ChooseFireMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41593);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *params;
		}
		bool RecommendLongRangedAttack()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41595);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		float RangedAttackTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41597);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void PlayVictoryAnimation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41599);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnModifyHealth(class SeqAct_ModifyHealth* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41601);
			byte params[4] = { NULL };
			*(class SeqAct_ModifyHealth**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetScreenName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41603);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void FaceRotation(Rotator NewRotation, float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41605);
			byte params[16] = { NULL };
			*(Rotator*)params = NewRotation;
			*(float*)&params[12] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateEyeHeight(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41608);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Vector GetPawnViewLocation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41626);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		void BecomeViewTarget(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41628);
			byte params[4] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndViewTarget(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41632);
			byte params[4] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetWeaponVisibility(bool bWeaponVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41634);
			byte params[4] = { NULL };
			*(bool*)params = bWeaponVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetWeaponAttachmentVisibility(bool bAttachmentVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41640);
			byte params[4] = { NULL };
			*(bool*)params = bAttachmentVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMeshVisibility(bool bVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41643);
			byte params[4] = { NULL };
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DeactivateSpawnProtection()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41646);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayTeleportEffect(bool bOut, bool bSound)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41650);
			byte params[8] = { NULL };
			*(bool*)params = bOut;
			*(bool*)&params[4] = bSound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnTransEffect(int TeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41660);
			byte params[4] = { NULL };
			*(int*)params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartDriving(class Vehicle* V)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41663);
			byte params[4] = { NULL };
			*(class Vehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopDriving(class Vehicle* V)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41669);
			byte params[4] = { NULL };
			*(class Vehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientRestart()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41674);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetShieldStrength()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41676);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int AbsorbDamage(int& Damage, int CurrentShieldStrength, float AbsorptionRate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41679);
			byte params[16] = { NULL };
			*(int*)params = Damage;
			*(int*)&params[4] = CurrentShieldStrength;
			*(float*)&params[8] = AbsorptionRate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Damage = *(int*)params;
			return *(int*)&params[12];
		}
		int ShieldAbsorb(int Damage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41685);
			byte params[8] = { NULL };
			*(int*)params = Damage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void AdjustDamage(int& InDamage, Vector& Momentum, class Controller* InstigatedBy, Vector HitLocation, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41690);
			byte params[68] = { NULL };
			*(int*)params = InDamage;
			*(Vector*)&params[4] = Momentum;
			*(class Controller**)&params[16] = InstigatedBy;
			*(Vector*)&params[20] = HitLocation;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InDamage = *(int*)params;
			Momentum = *(Vector*)&params[4];
		}
		void DropFlag(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41699);
			byte params[4] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableInventoryPickup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41703);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HoldGameObject(class UDKCarriedObject* GameObj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41704);
			byte params[4] = { NULL };
			*(class UDKCarriedObject**)params = GameObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GiveHealth(int HealAmount, int HealMax)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41712);
			byte params[12] = { NULL };
			*(int*)params = HealAmount;
			*(int*)&params[4] = HealMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		ScriptString* GetDebugName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41716);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void PlayFootStepSound(int FootDown)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41718);
			byte params[4] = { NULL };
			*(int*)params = FootDown;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ActuallyPlayFootstepSound(int FootDown)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41722);
			byte params[4] = { NULL };
			*(int*)params = FootDown;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptName GetMaterialBelowFeet()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41728);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)params;
		}
		void PlayLandingSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41738);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayJumpingSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41743);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldGib(ScriptClass* UTDamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41747);
			byte params[8] = { NULL };
			*(ScriptClass**)params = UTDamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SpawnHeadGib(ScriptClass* UTDamageType, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41752);
			byte params[16] = { NULL };
			*(ScriptClass**)params = UTDamageType;
			*(Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class UTGib* SpawnGib(ScriptClass* GibClass, ScriptName BoneName, ScriptClass* UTDamageType, Vector HitLocation, bool bSpinGib)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41772);
			byte params[36] = { NULL };
			*(ScriptClass**)params = GibClass;
			*(ScriptName*)&params[4] = BoneName;
			*(ScriptClass**)&params[12] = UTDamageType;
			*(Vector*)&params[16] = HitLocation;
			*(bool*)&params[28] = bSpinGib;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTGib**)&params[32];
		}
		void SpawnGibs(ScriptClass* UTDamageType, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41789);
			byte params[16] = { NULL };
			*(ScriptClass**)params = UTDamageType;
			*(Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TurnOffPawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41802);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayDying(ScriptClass* DamageType, Vector HitLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41803);
			byte params[16] = { NULL };
			*(ScriptClass**)params = DamageType;
			*(Vector*)&params[4] = HitLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoingDeathAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41835);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41844);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddDefaultInventory()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41847);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CalcCamera(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41848);
			byte params[36] = { NULL };
			*(float*)params = fDeltaTime;
			*(Vector*)&params[4] = out_CamLoc;
			*(Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Vector*)&params[4];
			out_CamRot = *(Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
			return *(bool*)&params[32];
		}
		void SetThirdPersonCamera(bool bNewBehindView)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41854);
			byte params[4] = { NULL };
			*(bool*)params = bNewBehindView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FindGoodEndView(class PlayerController* InPC, Rotator& GoodRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41857);
			byte params[16] = { NULL };
			*(class PlayerController**)params = InPC;
			*(Rotator*)&params[4] = GoodRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			GoodRotation = *(Rotator*)&params[4];
		}
		bool TryNewCamRot(class UTPlayerController* PC, Rotator ViewRotation, float& CamDist)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41867);
			byte params[24] = { NULL };
			*(class UTPlayerController**)params = PC;
			*(Rotator*)&params[4] = ViewRotation;
			*(float*)&params[16] = CamDist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CamDist = *(float*)&params[16];
			return *(bool*)&params[20];
		}
		void SetHeroCam(Rotator& out_CamRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41875);
			byte params[12] = { NULL };
			*(Rotator*)params = out_CamRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamRot = *(Rotator*)params;
		}
		bool CalcThirdPersonCam(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41878);
			byte params[36] = { NULL };
			*(float*)params = fDeltaTime;
			*(Vector*)&params[4] = out_CamLoc;
			*(Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Vector*)&params[4];
			out_CamRot = *(Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
			return *(bool*)&params[32];
		}
		Vector GetWeaponStartTraceLocation(class Weapon* CurrentWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41893);
			byte params[16] = { NULL };
			*(class Weapon**)params = CurrentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[4];
		}
		bool Dodge(Actor::EDoubleClickDir DoubleClickMove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41896);
			byte params[5] = { NULL };
			*(Actor::EDoubleClickDir*)params = DoubleClickMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		Vector BotDodge(Vector Dir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41910);
			byte params[24] = { NULL };
			*(Vector*)params = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		bool PerformDodge(Actor::EDoubleClickDir DoubleClickMove, Vector Dir, Vector Cross)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41916);
			byte params[29] = { NULL };
			*(Actor::EDoubleClickDir*)params = DoubleClickMove;
			*(Vector*)&params[4] = Dir;
			*(Vector*)&params[16] = Cross;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void DoDoubleJump(bool bUpdating)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41925);
			byte params[4] = { NULL };
			*(bool*)params = bUpdating;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Gasp()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41928);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFlying()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41929);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopFlying()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41930);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DoJump(bool bUpdating)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41931);
			byte params[8] = { NULL };
			*(bool*)params = bUpdating;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void Landed(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41935);
			byte params[16] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void JumpOutOfWater(Vector JumpDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41941);
			byte params[12] = { NULL };
			*(Vector*)params = JumpDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanMultiJump()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41943);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PlayDyingSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41945);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41946);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void SetPawnAmbientSound(class SoundCue* NewAmbientSound)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41956);
			byte params[4] = { NULL };
			*(class SoundCue**)params = NewAmbientSound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class SoundCue* GetPawnAmbientSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41958);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundCue**)params;
		}
		void SetWeaponAmbientSound(class SoundCue* NewAmbientSound)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41960);
			byte params[4] = { NULL };
			*(class SoundCue**)params = NewAmbientSound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class SoundCue* GetWeaponAmbientSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41962);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundCue**)params;
		}
		void SetOverlayMaterial(class MaterialInterface* NewOverlay)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41964);
			byte params[4] = { NULL };
			*(class MaterialInterface**)params = NewOverlay;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class MaterialInterface* GetShieldMaterialInstance(bool bTeamGame)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41967);
			byte params[8] = { NULL };
			*(bool*)params = bTeamGame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MaterialInterface**)&params[4];
		}
		class MaterialInterface* GetOverlayMaterial()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41972);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MaterialInterface**)params;
		}
		void SetWeaponOverlayFlag(byte FlagToSet)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41974);
			byte params[1] = { NULL };
			*params = FlagToSet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearWeaponOverlayFlag(byte FlagToClear)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41976);
			byte params[1] = { NULL };
			*params = FlagToClear;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyWeaponOverlayFlags(byte NewFlags)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41978);
			byte params[1] = { NULL };
			*params = NewFlags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartFeignDeathRecoveryAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41982);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FeignDeathDelayTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41984);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayFeignDeath()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41987);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool SetFeignEndLocation(Vector HitLocation, Vector FeignLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42001);
			byte params[28] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = FeignLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool CheckValidLocation(Vector FeignLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42006);
			byte params[16] = { NULL };
			*(Vector*)params = FeignLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void ServerFeignDeath()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42012);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FeignDeath()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42013);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceRagdoll()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42014);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FiringModeUpdated(class Weapon* InWeapon, byte InFiringMode, bool bViaReplication)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42015);
			byte params[9] = { NULL };
			*(class Weapon**)params = InWeapon;
			params[4] = InFiringMode;
			*(bool*)&params[8] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBigHead()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42019);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FireRateChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42021);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42022);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHeadScale(float NewScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42026);
			byte params[4] = { NULL };
			*(float*)params = NewScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPuttingDownWeapon(bool bNowPuttingDownWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42029);
			byte params[4] = { NULL };
			*(bool*)params = bNowPuttingDownWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetPuttingDownWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42031);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42033);
			byte params[68] = { NULL };
			*(int*)params = Damage;
			*(class Controller**)&params[4] = EventInstigator;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WeaponFired(class Weapon* InWeapon, bool bViaReplication, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42045);
			byte params[20] = { NULL };
			*(class Weapon**)params = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			*(Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WeaponStoppedFiring(class Weapon* InWeapon, bool bViaReplication)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42050);
			byte params[8] = { NULL };
			*(class Weapon**)params = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WeaponChanged(class UTWeapon* NewWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42053);
			byte params[4] = { NULL };
			*(class UTWeapon**)params = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WeaponAttachmentChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42056);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayHit(float Damage, class Controller* InstigatedBy, Vector HitLocation, ScriptClass* DamageType, Vector Momentum, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42057);
			byte params[64] = { NULL };
			*(float*)params = Damage;
			*(class Controller**)&params[4] = InstigatedBy;
			*(Vector*)&params[8] = HitLocation;
			*(ScriptClass**)&params[20] = DamageType;
			*(Vector*)&params[24] = Momentum;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayTakeHitEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42069);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeHitBlendedOut()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42080);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerHoverboard()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42081);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUseHoverboard(class UTSeqAct_UseHoverboard* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42093);
			byte params[4] = { NULL };
			*(class UTSeqAct_UseHoverboard**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchWeapon(byte NewGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42097);
			byte params[1] = { NULL };
			*params = NewGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDrowningDamage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42099);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsLocationOnHead(Actor::ImpactInfo& Impact, float AdditionalScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42100);
			byte params[88] = { NULL };
			*(Actor::ImpactInfo*)params = Impact;
			*(float*)&params[80] = AdditionalScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Impact = *(Actor::ImpactInfo*)params;
			return *(bool*)&params[84];
		}
		void ModifyRotForDebugFreeCam(Rotator& out_CamRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42108);
			byte params[12] = { NULL };
			*(Rotator*)params = out_CamRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamRot = *(Rotator*)params;
		}
		void AdjustCameraScale(bool bMoveCameraIn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42112);
			byte params[4] = { NULL };
			*(bool*)params = bMoveCameraIn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Rotator GetViewRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42116);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)params;
		}
		void TornOff()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42119);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetOverlayVisibility(bool bVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42121);
			byte params[4] = { NULL };
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeFallingDamage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42123);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RigidBodyCollision(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* HitComponent, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComponent, Actor::CollisionImpactData& RigidCollisionData, int ContactIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42126);
			byte params[48] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = HitComponent;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42131);
			byte params[12] = { NULL };
			*(class SVehicle**)params = Vehicle;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = RunOverComponent;
			*(int*)&params[8] = WheelIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StuckFalling()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42136);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnExitVehicle(class UTSeqAct_ExitVehicle* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42137);
			byte params[4] = { NULL };
			*(class UTSeqAct_ExitVehicle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnInfiniteAmmo(class UTSeqAct_InfiniteAmmo* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42139);
			byte params[4] = { NULL };
			*(class UTSeqAct_InfiniteAmmo**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PossessedBy(class Controller* C, bool bVehicleTransition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42144);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool NeedToTurn(Vector targ)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42147);
			byte params[16] = { NULL };
			*(Vector*)params = targ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		ScriptClass* GetFamilyInfo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42273);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)params;
		}
		void PostTeleport(class Teleporter* OutTeleporter)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42276);
			byte params[4] = { NULL };
			*(class Teleporter**)params = OutTeleporter;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBigTeleport()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42278);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
	const float UTPawn::MINTIMEBETWEENPAINSOUNDS = 0.35f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
