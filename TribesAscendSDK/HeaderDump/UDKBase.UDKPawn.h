#pragma once
#include "Core.Object.h"
#include "GameFramework.GamePawn.h"
#include "Engine.SkelControlFootPlacement.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.Material.h"
#include "UDKBase.UDKBot.h"
#include "Engine.AnimNodeAimOffset.h"
#include "GameFramework.GameSkelCtrl_Recoil.h"
#include "Engine.SkelControlLimb.h"
#include "Engine.SoundCue.h"
#include "Engine.SkelControlSingleBone.h"
#include "Engine.MaterialInterface.h"
#include "Engine.Actor.h"
#include "UDKBase.UDKCarriedObject.h"
#include "Engine.PlayerController.h"
#include "Engine.Canvas.h"
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
	class UDKPawn : public GamePawn
	{
	public:
		class DrivenWeaponPawnInfo
		{
		public:
			ADD_OBJECT(PlayerReplicationInfo, PRI, 8)
			ADD_STRUCT(byte, SeatIndex, 4)
			ADD_OBJECT(UDKVehicle, BaseVehicle, 0)
		};
		class UTTakeHitInfo
		{
		public:
			ADD_BOOL(m_bDamagedSelf, 40, 0x1)
			ADD_STRUCT(ScriptName, HitBone, 32)
			ADD_OBJECT(ScriptClass, DamageType, 28)
			ADD_STRUCT(Object::Vector, Momentum, 16)
			ADD_STRUCT(Object::Vector, HitLocation, 4)
			ADD_STRUCT(int, Damage, 0)
		};
		class PlayEmoteInfo
		{
		public:
			ADD_BOOL(bNewData, 12, 0x1)
			ADD_STRUCT(int, EmoteID, 8)
			ADD_STRUCT(ScriptName, EmoteTag, 0)
		};
		class MaterialImpactEffect
		{
		public:
			ADD_STRUCT(ScriptArray<class MaterialInterface*>, DecalMaterials, 12)
			ADD_OBJECT(ParticleSystem, ParticleTemplate, 44)
			ADD_STRUCT(float, DecalHeight, 40)
			ADD_STRUCT(float, DecalWidth, 36)
			ADD_STRUCT(ScriptName, DecalDissolveParamName, 28)
			ADD_STRUCT(float, DurationOfDecal, 24)
			ADD_OBJECT(SoundCue, Sound, 8)
			ADD_STRUCT(ScriptName, MaterialType, 0)
		};
		class MaterialSoundEffect
		{
		public:
			ADD_OBJECT(SoundCue, Sound, 8)
			ADD_STRUCT(ScriptName, MaterialType, 0)
		};
		class MaterialParticleEffect
		{
		public:
			ADD_OBJECT(ParticleSystem, ParticleTemplate, 8)
			ADD_STRUCT(ScriptName, MaterialType, 0)
		};
		class DistanceBasedParticleTemplate
		{
		public:
			ADD_STRUCT(float, MinDistance, 4)
			ADD_OBJECT(ParticleSystem, Template, 0)
		};
		class EmoteInfo
		{
		public:
			ADD_BOOL(bRequiresPlayer, 48, 0x1)
			ADD_STRUCT(ScriptName, Command, 40)
			ADD_BOOL(bTopHalfEmote, 36, 0x2)
			ADD_BOOL(bVictoryEmote, 36, 0x1)
			ADD_STRUCT(ScriptName, EmoteAnim, 28)
			ADD_STRUCT(ScriptString*, EmoteName, 16)
			ADD_STRUCT(ScriptName, EmoteTag, 8)
			ADD_STRUCT(ScriptName, CategoryName, 0)
		};
		ADD_BOOL(bNotifyStopFalling, 1148, 0x40)
		ADD_BOOL(bReadyToDoubleJump, 1148, 0x1)
		ADD_STRUCT(ScriptArray<class MaterialInstanceConstant*>, BodyMaterialInstances, 1316)
		ADD_STRUCT(ScriptArray<class UDKBot*>, Trackers, 1352)
		ADD_STRUCT(Object::Vector, HUDLocation, 1604)
		ADD_STRUCT(Object::Vector2D, CurrentSkelAim, 1596)
		ADD_STRUCT(int, MaxYawAim, 1592)
		ADD_STRUCT(float, RootYawSpeed, 1588)
		ADD_STRUCT(int, RootYaw, 1584)
		ADD_STRUCT(float, TakeHitPhysicsBlendOutSpeed, 1572)
		ADD_STRUCT(float, CrouchMeshZOffset, 1568)
		ADD_STRUCT(float, SwimmingZOffsetSpeed, 1564)
		ADD_STRUCT(float, SwimmingZOffset, 1560)
		ADD_STRUCT(float, FeignDeathPhysicsBlendOutSpeed, 1556)
		ADD_STRUCT(int, MaxLeanRoll, 1552)
		ADD_OBJECT(AnimNodeAimOffset, FlyingDirOffset, 1548)
		ADD_STRUCT(float, SlopeBoostFriction, 1544)
		ADD_STRUCT(float, StartedFallingTime, 1540)
		ADD_STRUCT(float, TeamBeaconMaxDist, 1536)
		ADD_STRUCT(float, LastPostRenderTraceTime, 1532)
		ADD_STRUCT(ScriptName, SaturationParameterName, 1524)
		ADD_STRUCT(ScriptName, DamageParameterName, 1516)
		ADD_OBJECT(SkelControlLimb, RightHandIK, 1512)
		ADD_OBJECT(SkelControlLimb, LeftHandIK, 1508)
		ADD_OBJECT(SkelControlFootPlacement, RightLegControl, 1504)
		ADD_OBJECT(SkelControlFootPlacement, LeftLegControl, 1500)
		ADD_STRUCT(float, MaxFootPlacementDistSquared, 1496)
		ADD_STRUCT(float, ZSmoothingRate, 1492)
		ADD_STRUCT(float, OldLocationZ, 1488)
		ADD_STRUCT(float, CrouchTranslationOffset, 1484)
		ADD_STRUCT(float, BaseTranslationOffset, 1480)
		ADD_STRUCT(ScriptName, RightFootControlName, 1472)
		ADD_STRUCT(ScriptName, LeftFootControlName, 1464)
		ADD_STRUCT(ScriptName, RightFootBone, 1456)
		ADD_STRUCT(ScriptName, LeftFootBone, 1448)
		ADD_STRUCT(float, FallSpeedThreshold, 1436)
		ADD_OBJECT(SoundCue, FallImpactSound, 1432)
		ADD_STRUCT(ScriptName, TorsoBoneName, 1424)
		ADD_STRUCT(float, StartFallImpactTime, 1420)
		ADD_STRUCT(Object::Rotator, CompressedBodyMatColor, 1408)
		ADD_STRUCT(Object::LinearColor, BodyMatColor, 1392)
		ADD_STRUCT(float, ClientBodyMatDuration, 1388)
		ADD_STRUCT(float, RemainingBodyMatDuration, 1384)
		ADD_STRUCT(Object::LinearColor, CurrentBodyMatColor, 1368)
		ADD_STRUCT(float, BodyMatFadeDuration, 1364)
		ADD_OBJECT(GameSkelCtrl_Recoil, RightRecoilNode, 1348)
		ADD_OBJECT(GameSkelCtrl_Recoil, LeftRecoilNode, 1344)
		ADD_OBJECT(GameSkelCtrl_Recoil, GunRecoilNode, 1340)
		ADD_OBJECT(AnimNodeAimOffset, AimNode, 1336)
		ADD_OBJECT(SkelControlSingleBone, RootRotControl, 1332)
		ADD_OBJECT(MaterialInterface, OverlayMaterialInstance, 1328)
		ADD_OBJECT(Material, ReplicatedBodyMaterial, 1312)
		ADD_OBJECT(SoundCue, WeaponAmbientSoundCue, 1308)
		ADD_STRUCT(UDKPawn::DrivenWeaponPawnInfo, DrivenWeaponPawn, 1292)
		ADD_OBJECT(SoundCue, PawnAmbientSoundCue, 1288)
		ADD_STRUCT(float, OldZ, 1280)
		ADD_STRUCT(Object::Vector, MeshTranslationOffset, 1268)
		ADD_STRUCT(float, SmoothNetUpdateTime, 1264)
		ADD_STRUCT(float, NoSmoothNetUpdateDist, 1260)
		ADD_STRUCT(float, MaxSmoothNetUpdateDist, 1256)
		ADD_STRUCT(float, HeadScale, 1252)
		ADD_STRUCT(float, FireRateMultiplier, 1248)
		ADD_STRUCT(float, LastTakeHitTimeout, 1244)
		ADD_STRUCT(UDKPawn::UTTakeHitInfo, LastTakeHitInfo, 1200)
		ADD_STRUCT(byte, WeaponOverlayFlags, 1197)
		ADD_STRUCT(byte, BigTeleportCount, 1196)
		ADD_STRUCT(float, MinTimeBetweenEmotes, 1192)
		ADD_STRUCT(float, LastEmoteTime, 1188)
		ADD_STRUCT(UDKPawn::PlayEmoteInfo, EmoteRepInfo, 1172)
		ADD_STRUCT(float, CustomGravityScaling, 1168)
		ADD_STRUCT(int, MultiJumpBoost, 1164)
		ADD_STRUCT(int, MaxMultiJump, 1160)
		ADD_STRUCT(int, MultiJumpRemaining, 1156)
		ADD_STRUCT(float, MaxDoubleJumpHeight, 1152)
		ADD_BOOL(bTearOffGibs, 1148, 0x10000)
		ADD_BOOL(bUpdateEyeheight, 1148, 0x8000)
		ADD_BOOL(bBlendOutTakeHitPhysics, 1148, 0x4000)
		ADD_BOOL(bPostRenderOtherTeam, 1148, 0x2000)
		ADD_BOOL(bEnableFootPlacement, 1148, 0x1000)
		ADD_BOOL(bCanPlayFallingImpacts, 1148, 0x800)
		ADD_BOOL(bPlayingFeignDeathRecovery, 1148, 0x400)
		ADD_BOOL(bPuttingDownWeapon, 1148, 0x200)
		ADD_BOOL(bSmoothNetUpdates, 1148, 0x100)
		ADD_BOOL(bIsInvisible, 1148, 0x80)
		ADD_BOOL(bFeigningDeath, 1148, 0x20)
		ADD_BOOL(bIsHoverboardAnimPawn, 1148, 0x10)
		ADD_BOOL(bNoJumpAdjust, 1148, 0x8)
		ADD_BOOL(bCanDoubleJump, 1148, 0x4)
		ADD_BOOL(bRequiresDoubleJump, 1148, 0x2)
		void GetBoundingCylinder(float& CollisionRadius, float& CollisionHeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.GetBoundingCylinder");
			byte params[8] = { NULL };
			*(float*)&params[0] = CollisionRadius;
			*(float*)&params[4] = CollisionHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CollisionRadius = *(float*)&params[0];
			CollisionHeight = *(float*)&params[4];
		}
		void RestorePreRagdollCollisionComponent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.RestorePreRagdollCollisionComponent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnsureOverlayComponentLast()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.EnsureOverlayComponentLast");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Object::Vector GetTargetLocation(class Actor* RequestedBy, bool bRequestAlternateLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.GetTargetLocation");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = RequestedBy;
			*(bool*)&params[4] = bRequestAlternateLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[8];
		}
		bool IsInvisible()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.IsInvisible");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void HoldGameObject(class UDKCarriedObject* UDKGameObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.HoldGameObject");
			byte params[4] = { NULL };
			*(class UDKCarriedObject**)&params[0] = UDKGameObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StoppedFalling()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.StoppedFalling");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndCrouch(float HeightAdjust)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.EndCrouch");
			byte params[4] = { NULL };
			*(float*)&params[0] = HeightAdjust;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartCrouch(float HeightAdjust)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.StartCrouch");
			byte params[4] = { NULL };
			*(float*)&params[0] = HeightAdjust;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SuggestJumpVelocity(Object::Vector& JumpVelocity, Object::Vector Destination, Object::Vector Start, bool bRequireFallLanding)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.SuggestJumpVelocity");
			byte params[44] = { NULL };
			*(Object::Vector*)&params[0] = JumpVelocity;
			*(Object::Vector*)&params[12] = Destination;
			*(Object::Vector*)&params[24] = Start;
			*(bool*)&params[36] = bRequireFallLanding;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			JumpVelocity = *(Object::Vector*)&params[0];
			return *(bool*)&params[40];
		}
		void SetHUDLocation(Object::Vector NewHUDLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.SetHUDLocation");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = NewHUDLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NativePostRenderFor(class PlayerController* PC, class Canvas* Canvas, Object::Vector CameraPosition, Object::Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.NativePostRenderFor");
			byte params[32] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector*)&params[8] = CameraPosition;
			*(Object::Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetWeaponAttachmentVisibility(bool bAttachmentVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.SetWeaponAttachmentVisibility");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bAttachmentVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHandIKEnabled(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.SetHandIKEnabled");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartFeignDeathRecoveryAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.StartFeignDeathRecoveryAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeHitBlendedOut()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.TakeHitBlendedOut");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateEyeHeight(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.UpdateEyeHeight");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StuckFalling()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKPawn.StuckFalling");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
