#pragma once
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.ParticleSystem.h"
#include "UDKBase.UDKVehicle.h"
#include "Engine.SoundCue.h"
#include "Engine.MaterialInterface.h"
#include "UDKBase.UDKPawn.h"
#include "UDKBase.UDKProjectile.h"
#include "UTGame.UTGib.h"
#include "Engine.StaticMesh.h"
#include "Engine.SoundNodeWave.h"
#include "Core.Object.h"
#include "Engine.UIRoot.h"
#include "Engine.Texture2D.h"
#include "Engine.Actor.h"
#include "UTGame.UTVehicleDeathPiece.h"
#include "UTGame.UTPlayerController.h"
#include "Engine.CameraAnim.h"
#include "UTGame.UTBot.h"
#include "Engine.Emitter.h"
#include "UDKBase.UDKPlayerController.h"
#include "UTGame.UTVehicleFactory.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.Weapon.h"
#include "Engine.Pawn.h"
#include "Engine.Canvas.h"
#include "UTGame.UTWeapon.h"
#include "UTGame.UTHUD.h"
#include "UTGame.UTMapInfo.h"
#include "Engine.Vehicle.h"
#include "Engine.Controller.h"
#include "Engine.AnimNodeSequence.h"
#include "Engine.PlayerController.h"
#include "UTGame.UTCarriedObject.h"
#include "Engine.Projectile.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "UDKBase.UDKCarriedObject.h"
#include "UTGame.UTSquadAI.h"
#include "UTGame.UTVehicleWeapon.h"
#include "UTGame.UTProjectile.h"
#include "UTGame.UTPawn.h"
#include "UTGame.UTSeqAct_ExitVehicle.h"
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
	class UTVehicle : public UDKVehicle
	{
	public:
		static const auto UTVEHICLE_UNSET_TEAM = 255;
		enum EAIVehiclePurpose : byte
		{
			AIP_Offensive = 0,
			AIP_Defensive = 1,
			AIP_Any = 2,
			AIP_MAX = 3,
		};
		class MaterialList
		{
		public:
			ADD_STRUCT(ScriptArray<class MaterialInterface*>, Materials, 0)
		};
		class TimePosition
		{
		public:
			ADD_STRUCT(float, Time, 12)
			ADD_STRUCT(Object::Vector, Position, 0)
		};
		ADD_BOOL(bCanCarryFlag, 1976, 0x2)
		ADD_BOOL(bRequestedEntryWithFlag, 1976, 0x200000)
		ADD_BOOL(bHasCustomEntryRadius, 1976, 0x10)
		ADD_OBJECT(UTVehicle, NextVehicle, 2112)
		ADD_STRUCT(float, DefaultFOV, 2652)
		ADD_BOOL(bDropDetailWhenDriving, 1976, 0x10000)
		ADD_BOOL(bSpectatedView, 1980, 0x200)
		ADD_STRUCT(ScriptArray<class SoundCue*>, HornSounds, 2048)
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, TeamMaterials, 2196)
		ADD_STRUCT(ScriptArray<UDKPawn::DistanceBasedParticleTemplate>, BigExplosionTemplates, 2232)
		ADD_STRUCT(ScriptArray<UDKPawn::DistanceBasedParticleTemplate>, DistanceTurretExplosionTemplates, 2312)
		ADD_STRUCT(ScriptArray<class ParticleSystem*>, SpawnInTemplates, 2560)
		ADD_STRUCT(ScriptArray<UTVehicle::MaterialList>, SpawnMaterialLists, 2572)
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, OriginalMaterials, 2608)
		ADD_STRUCT(ScriptArray<UTVehicle::TimePosition>, OldPositions, 2656)
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, EnemyVehicleSound, 2732)
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, VehicleDestroyedSound, 2744)
		ADD_STRUCT(float, LastEnemyWarningTime, 2728)
		ADD_OBJECT(StaticMesh, ReferenceMovementMesh, 2724)
		ADD_OBJECT(ParticleSystem, DisabledTemplate, 2716)
		ADD_STRUCT(float, TimeLastDisabled, 2712)
		ADD_STRUCT(float, DisabledTime, 2708)
		ADD_STRUCT(Object::Vector, OldCameraPosition, 2696)
		ADD_OBJECT(UTGib, DeathCameraGib, 2692)
		ADD_STRUCT(float, MinCameraDistSq, 2688)
		ADD_STRUCT(float, LookForwardDist, 2684)
		ADD_STRUCT(Object::Vector, CameraOffset, 2672)
		ADD_STRUCT(float, CameraLag, 2668)
		ADD_STRUCT(float, CameraSmoothingFactor, 2648)
		ADD_STRUCT(float, OldCamPosZ, 2644)
		ADD_STRUCT(float, SeatCameraScale, 2640)
		ADD_STRUCT(float, LastCollisionDamageTime, 2636)
		ADD_STRUCT(float, CollisionDamageMult, 2632)
		ADD_OBJECT(MaterialInterface, BurnOutMaterial, 2624)
		ADD_STRUCT(float, SpawnInTime, 2620)
		ADD_STRUCT(Object::InterpCurveFloat, SpawnMaterialParameterCurve, 2592)
		ADD_STRUCT(ScriptName, SpawnMaterialParameterName, 2584)
		ADD_STRUCT(UIRoot::TextureCoordinates, HudCoords, 2544)
		ADD_OBJECT(Texture2D, HudIcons, 2540)
		ADD_STRUCT(Object::Vector, PassengerTeamBeaconOffset, 2528)
		ADD_OBJECT(PlayerReplicationInfo, PassengerPRI, 2512)
		ADD_STRUCT(Object::Vector, TeamBeaconOffset, 2500)
		ADD_STRUCT(float, HealthPulseTime, 2496)
		ADD_STRUCT(int, LastHealth, 2492)
		ADD_STRUCT(UIRoot::TextureCoordinates, DropOrbIconCoords, 2476)
		ADD_STRUCT(UIRoot::TextureCoordinates, DropFlagIconCoords, 2460)
		ADD_STRUCT(UIRoot::TextureCoordinates, EnterToolTipIconCoords, 2444)
		ADD_STRUCT(UIRoot::TextureCoordinates, FlipToolTipIconCoords, 2428)
		ADD_STRUCT(UIRoot::TextureCoordinates, IconCoords, 2412)
		ADD_STRUCT(float, MapSize, 2408)
		ADD_STRUCT(ScriptName, FlagBone, 2400)
		ADD_STRUCT(Object::Rotator, FlagRotation, 2388)
		ADD_STRUCT(Object::Vector, FlagOffset, 2376)
		ADD_OBJECT(SoundCue, BoostPadSound, 2372)
		ADD_OBJECT(SoundCue, SpawnOutSound, 2368)
		ADD_OBJECT(SoundCue, SpawnInSound, 2364)
		ADD_STRUCT(float, SpawnRadius, 2360)
		ADD_STRUCT(ScriptName, BurnTimeParameterName, 2352)
		ADD_OBJECT(SoundCue, ExplosionSound, 2348)
		ADD_STRUCT(float, TurretExplosiveForce, 2344)
		ADD_OBJECT(StaticMesh, DestroyedTurretTemplate, 2340)
		ADD_OBJECT(UTVehicleDeathPiece, DestroyedTurret, 2336)
		ADD_STRUCT(Object::Vector, TurretOffset, 2324)
		ADD_STRUCT(ScriptName, TurretSocketName, 2304)
		ADD_STRUCT(ScriptName, TurretScaleControlName, 2296)
		ADD_STRUCT(float, OuterExplosionShakeRadius, 2292)
		ADD_STRUCT(float, InnerExplosionShakeRadius, 2288)
		ADD_OBJECT(CameraAnim, DeathExplosionShake, 2284)
		ADD_STRUCT(float, ExplosionInAirAngVel, 2280)
		ADD_STRUCT(float, ExplosionMomentum, 2276)
		ADD_STRUCT(float, ExplosionRadius, 2272)
		ADD_STRUCT(float, ExplosionDamage, 2268)
		ADD_STRUCT(int, DelayedBurnoutCount, 2264)
		ADD_STRUCT(float, DeadVehicleLifeSpan, 2260)
		ADD_STRUCT(float, BurnOutTime, 2256)
		ADD_STRUCT(ScriptName, BigExplosionSocket, 2248)
		ADD_OBJECT(ParticleSystem, SecondaryExplosion, 2244)
		ADD_OBJECT(ParticleSystem, ExplosionTemplate, 2228)
		ADD_STRUCT(float, MaxFireEffectDistance, 2224)
		ADD_STRUCT(float, MaxImpactEffectDistance, 2220)
		ADD_OBJECT(ScriptClass, ExplosionDamageType, 2216)
		ADD_STRUCT(float, DamageSmokeThreshold, 2212)
		ADD_OBJECT(ScriptClass, VehiclePieceClass, 2208)
		ADD_STRUCT(int, ClientHealth, 2192)
		ADD_STRUCT(float, TimeTilSecondaryVehicleExplosion, 2188)
		ADD_OBJECT(Emitter, DeathExplosion, 2184)
		ADD_STRUCT(float, MaxExplosionLightDistance, 2180)
		ADD_OBJECT(ScriptClass, ExplosionLightClass, 2176)
		ADD_OBJECT(ScriptClass, VehicleDrowningDamType, 2172)
		ADD_STRUCT(float, HUDExtent, 2168)
		ADD_STRUCT(float, TeamBeaconPlayerInfoMaxDist, 2164)
		ADD_STRUCT(UDKPlayerController::ObjectiveAnnouncementInfo, NeedToPickUpAnnouncement, 2148)
		ADD_STRUCT(ScriptString*, VehicleNameString, 2136)
		ADD_STRUCT(ScriptString*, VehiclePositionString, 2124)
		ADD_OBJECT(UTBot, Reservation, 2120)
		ADD_OBJECT(UTVehicleFactory, ParentFactory, 2116)
		ADD_OBJECT(SoundCue, StolenSound, 2108)
		ADD_STRUCT(int, StolenAnnouncementIndex, 2104)
		ADD_OBJECT(SoundCue, RanOverSound, 2100)
		ADD_OBJECT(ScriptClass, RanOverDamageType, 2096)
		ADD_OBJECT(SoundCue, LockedOnSound, 2092)
		ADD_STRUCT(float, ConsoleSteerScale, 2088)
		ADD_STRUCT(float, LookSteerDeadZone, 2084)
		ADD_STRUCT(float, LookSteerDamping, 2080)
		ADD_STRUCT(float, LookSteerSensitivity, 2076)
		ADD_STRUCT(float, LeftStickDirDeadZone, 2072)
		ADD_STRUCT(int, HornIndex, 2068)
		ADD_STRUCT(float, LastHornTime, 2064)
		ADD_STRUCT(float, HornAIRadius, 2060)
		ADD_STRUCT(float, MaxDesireability, 2044)
		ADD_OBJECT(SoundCue, LinkedEndSound, 2040)
		ADD_OBJECT(SoundCue, LinkedToCue, 2036)
		ADD_STRUCT(float, LinkHealMult, 2028)
		ADD_STRUCT(float, InitialSpawnDelay, 2024)
		ADD_STRUCT(float, RespawnTime, 2020)
		ADD_STRUCT(float, PlayerStartTime, 2016)
		ADD_STRUCT(float, VehicleLostTime, 2012)
		ADD_OBJECT(PhysicalMaterial, DefaultPhysicalMaterial, 2004)
		ADD_OBJECT(PhysicalMaterial, DrivingPhysicalMaterial, 2000)
		ADD_STRUCT(float, DeflectionReverseThresh, 1996)
		ADD_OBJECT(Actor, NoPassengerObjective, 1992)
		ADD_STRUCT(byte, LinkedToCount, 1989)
		ADD_STRUCT(UTVehicle::EAIVehiclePurpose, AIPurpose, 1988)
		ADD_BOOL(bDriverHoldsFlag, 1976, 0x1)
		ADD_OBJECT(SoundCue, VehicleLockedSound, 1984)
		ADD_BOOL(bIsNecrisVehicle, 1980, 0x100)
		ADD_BOOL(bHasEnemyVehicleSound, 1980, 0x80)
		ADD_BOOL(bStealthVehicle, 1980, 0x40)
		ADD_BOOL(bShowDamageDebug, 1980, 0x20)
		ADD_BOOL(bAcceptTurretJump, 1980, 0x10)
		ADD_BOOL(bIsConsoleTurning, 1980, 0x8)
		ADD_BOOL(bStopDeathCamera, 1980, 0x4)
		ADD_BOOL(bCameraNeverHidesVehicle, 1980, 0x2)
		ADD_BOOL(bFixedCamZ, 1980, 0x1)
		ADD_BOOL(bNoFollowJumpZ, 1976, 0x80000000)
		ADD_BOOL(bLimitCameraZLookingUp, 1976, 0x40000000)
		ADD_BOOL(bNoZSmoothing, 1976, 0x20000000)
		ADD_BOOL(bRotateCameraUnderVehicle, 1976, 0x10000000)
		ADD_BOOL(bReducedFallingCollisionDamage, 1976, 0x8000000)
		ADD_BOOL(bPlayingSpawnEffect, 1976, 0x4000000)
		ADD_BOOL(bPostRenderTraceSucceeded, 1976, 0x2000000)
		ADD_BOOL(bHasTurretExplosion, 1976, 0x1000000)
		ADD_BOOL(bRagdollDriverOnDarkwalkerHorn, 1976, 0x800000)
		ADD_BOOL(bInitializedVehicleEffects, 1976, 0x400000)
		ADD_BOOL(bFindGroundExit, 1976, 0x100000)
		ADD_BOOL(bUsingLookSteer, 1976, 0x80000)
		ADD_BOOL(bLookSteerOnSimpleControls, 1976, 0x40000)
		ADD_BOOL(bLookSteerOnNormalControls, 1976, 0x20000)
		ADD_BOOL(bHasBeenDriven, 1976, 0x8000)
		ADD_BOOL(bDriverCastsShadow, 1976, 0x4000)
		ADD_BOOL(bDrawHealthOnHUD, 1976, 0x2000)
		ADD_BOOL(bShouldLeaveForCombat, 1976, 0x1000)
		ADD_BOOL(bNeverReset, 1976, 0x800)
		ADD_BOOL(bHasWeaponBar, 1976, 0x400)
		ADD_BOOL(bShouldAutoCenterViewPitch, 1976, 0x200)
		ADD_BOOL(bStickDeflectionThrottle, 1976, 0x100)
		ADD_BOOL(bOverrideAVRiLLocks, 1976, 0x80)
		ADD_BOOL(bMustBeUpright, 1976, 0x40)
		ADD_BOOL(bKeyVehicle, 1976, 0x20)
		ADD_BOOL(bEnteringUnlocks, 1976, 0x8)
		ADD_BOOL(bValidLinkTarget, 1976, 0x4)
		bool TryToDrive(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TryToDrive");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool InCustomEntryRadius(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.InCustomEntryRadius");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateShadowSettings(bool bWantShadow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.UpdateShadowSettings");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWantShadow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReattachMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ReattachMesh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateDamageMaterialInstance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.CreateDamageMaterialInstance");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateLookSteerStatus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.UpdateLookSteerStatus");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInputs(float InForward, float InStrafe, float InUp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetInputs");
			byte params[12] = { NULL };
			*(float*)&params[0] = InForward;
			*(float*)&params[4] = InStrafe;
			*(float*)&params[8] = InUp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.FellOutOfWorld");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetChargePower()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetChargePower");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void PlaySpawnEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PlaySpawnEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopSpawnEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.StopSpawnEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EjectSeat(int SeatIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.EjectSeat");
			byte params[4] = { NULL };
			*(int*)&params[0] = SeatIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptClass* GetRanOverDamageType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetRanOverDamageType");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[0];
		}
		void DisplayWeaponBar(class Canvas* Canvas, class UTHUD* HUD)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DisplayWeaponBar");
			byte params[8] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			*(class UTHUD**)&params[4] = HUD;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawKillIcon(class Canvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DrawKillIcon");
			byte params[20] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			*(float*)&params[4] = ScreenX;
			*(float*)&params[8] = ScreenY;
			*(float*)&params[12] = HUDScaleX;
			*(float*)&params[16] = HUDScaleY;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderMapIcon(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, Object::LinearColor FinalColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.RenderMapIcon");
			byte params[28] = { NULL };
			*(class UTMapInfo**)&params[0] = MP;
			*(class Canvas**)&params[4] = Canvas;
			*(class UTPlayerController**)&params[8] = PlayerOwner;
			*(Object::LinearColor*)&params[12] = FinalColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float AdjustedStrength()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.AdjustedStrength");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		bool ContinueOnFoot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ContinueOnFoot");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsDriverSeat(class Vehicle* TestSeatPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.IsDriverSeat");
			byte params[8] = { NULL };
			*(class Vehicle**)&params[0] = TestSeatPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool RecommendCharge(class UTBot* B, class Pawn* Enemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.RecommendCharge");
			byte params[12] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(class Pawn**)&params[4] = Enemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool CriticalChargeAttack(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.CriticalChargeAttack");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void CreateVehicleEffect(int EffectIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.CreateVehicleEffect");
			byte params[4] = { NULL };
			*(int*)&params[0] = EffectIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitializeEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.InitializeEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetVehicleEffectParms(ScriptName TriggerName, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetVehicleEffectParms");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = TriggerName;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[8] = PSC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TriggerVehicleEffect(ScriptName EventTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TriggerVehicleEffect");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = EventTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayVehicleSound(ScriptName SoundTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PlayVehicleSound");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = SoundTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayVehicleAnimation(ScriptName EventTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PlayVehicleAnimation");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = EventTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleEvent(ScriptName EventTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.VehicleEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = EventTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EntryAnnouncement(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.EntryAnnouncement");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Rotator ExitRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ExitRotation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[0];
		}
		bool FindAutoExit(class Pawn* ExitingDriver)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.FindAutoExit");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = ExitingDriver;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void RanInto(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.RanInto");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PancakeOther(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PancakeOther");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeWaterDamage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TakeWaterDamage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DriverRadiusDamage(float DamageAmount, float DamageRadius, class Controller* EventInstigator, ScriptClass* DamageType, float Momentum, Object::Vector HitLocation, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DriverRadiusDamage");
			byte params[40] = { NULL };
			*(float*)&params[0] = DamageAmount;
			*(float*)&params[4] = DamageRadius;
			*(class Controller**)&params[8] = EventInstigator;
			*(ScriptClass**)&params[12] = DamageType;
			*(float*)&params[16] = Momentum;
			*(Object::Vector*)&params[20] = HitLocation;
			*(class Actor**)&params[32] = DamageCauser;
			*(float*)&params[36] = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetTexturesToBeResident(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetTexturesToBeResident");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DisableVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DisableVehicle");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void EnableVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.EnableVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeFireDamage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TakeFireDamage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetSeatIndexFromPrefix(ScriptString* Prefix)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetSeatIndexFromPrefix");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Prefix;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		void ServerSetConsoleTurning(bool bNewConsoleTurning)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ServerSetConsoleTurning");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewConsoleTurning;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessViewRotation(float DeltaTime, Object::Rotator& out_ViewRotation, Object::Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ProcessViewRotation");
			byte params[28] = { NULL };
			*(float*)&params[0] = DeltaTime;
			*(Object::Rotator*)&params[4] = out_ViewRotation;
			*(Object::Rotator*)&params[16] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Object::Rotator*)&params[4];
			out_DeltaRot = *(Object::Rotator*)&params[16];
		}
		Object::Rotator GetClampedViewRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetClampedViewRotation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[0];
		}
		bool ShouldClamp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ShouldClamp");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		Object::Rotator GetViewRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetViewRotation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[0];
		}
		void WeaponRotationChanged(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.WeaponRotationChanged");
			byte params[4] = { NULL };
			*(int*)&params[0] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetKeyVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetKeyVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrivingStatusChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DrivingStatusChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.OnAnimEnd");
			byte params[12] = { NULL };
			*(class AnimNodeSequence**)&params[0] = SeqNode;
			*(float*)&params[4] = PlayedTime;
			*(float*)&params[8] = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SeatAvailable(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SeatAvailable");
			byte params[8] = { NULL };
			*(int*)&params[0] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AnySeatAvailable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.AnySeatAvailable");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		int GetSeatIndexForController(class Controller* ControllerToMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetSeatIndexForController");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = ControllerToMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		class Controller* GetControllerForSeatIndex(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetControllerForSeatIndex");
			byte params[8] = { NULL };
			*(int*)&params[0] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Controller**)&params[4];
		}
		void ServerAdjacentSeat(int Direction, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ServerAdjacentSeat");
			byte params[8] = { NULL };
			*(int*)&params[0] = Direction;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerChangeSeat(int RequestedSeat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ServerChangeSeat");
			byte params[4] = { NULL };
			*(int*)&params[0] = RequestedSeat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HasPriority(class Controller* first, class Controller* Second)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.HasPriority");
			byte params[12] = { NULL };
			*(class Controller**)&params[0] = first;
			*(class Controller**)&params[4] = Second;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool ChangeSeat(class Controller* ControllerToMove, int RequestedSeat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ChangeSeat");
			byte params[12] = { NULL };
			*(class Controller**)&params[0] = ControllerToMove;
			*(int*)&params[4] = RequestedSeat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void TornOff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TornOff");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Controller* GetCollisionDamageInstigator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetCollisionDamageInstigator");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Controller**)&params[0];
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.Died");
			byte params[24] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(ScriptClass**)&params[4] = DamageType;
			*(Object::Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		void BlowupVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.BlowupVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class PlayerReplicationInfo* GetSeatPRI(int SeatNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetSeatPRI");
			byte params[8] = { NULL };
			*(int*)&params[0] = SeatNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerReplicationInfo**)&params[4];
		}
		bool CanEnterVehicle(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.CanEnterVehicle");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool KickOutBot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.KickOutBot");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void VehicleLocked(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.VehicleLocked");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldShowUseable(class PlayerController* PC, float Dist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ShouldShowUseable");
			byte params[12] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(float*)&params[4] = Dist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Object::Vector CameraPosition, Object::Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PostRenderFor");
			byte params[32] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector*)&params[8] = CameraPosition;
			*(Object::Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetDisplayedHealth()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetDisplayedHealth");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void RenderPassengerBeacons(class PlayerController* PC, class Canvas* Canvas, Object::LinearColor TeamColor, Object::Color TextColor, class UTWeapon* Weap)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.RenderPassengerBeacons");
			byte params[32] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::LinearColor*)&params[8] = TeamColor;
			*(Object::Color*)&params[24] = TextColor;
			*(class UTWeapon**)&params[28] = Weap;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRenderPassengerBeacon(class PlayerController* PC, class Canvas* Canvas, Object::LinearColor TeamColor, Object::Color TextColor, class UTWeapon* Weap, class PlayerReplicationInfo* InPassengerPRI, Object::Vector InPassengerTeamBeaconOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PostRenderPassengerBeacon");
			byte params[48] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::LinearColor*)&params[8] = TeamColor;
			*(Object::Color*)&params[24] = TextColor;
			*(class UTWeapon**)&params[28] = Weap;
			*(class PlayerReplicationInfo**)&params[32] = InPassengerPRI;
			*(Object::Vector*)&params[36] = InPassengerTeamBeaconOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTeamNum(byte T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetTeamNum");
			byte params[1] = { NULL };
			params[0] = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TeamChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TeamChanged_VehicleEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TeamChanged_VehicleEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool Dodge(Actor::EDoubleClickDir DoubleClickMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.Dodge");
			byte params[5] = { NULL };
			*(Actor::EDoubleClickDir*)&params[0] = DoubleClickMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void IncomingMissile(class Projectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.IncomingMissile");
			byte params[4] = { NULL };
			*(class Projectile**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShootMissile(class Projectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ShootMissile");
			byte params[4] = { NULL };
			*(class Projectile**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendLockOnMessage(int Switch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SendLockOnMessage");
			byte params[4] = { NULL };
			*(int*)&params[0] = Switch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LockOnWarning(class UDKProjectile* IncomingMissile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.LockOnWarning");
			byte params[4] = { NULL };
			*(class UDKProjectile**)&params[0] = IncomingMissile;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool TooCloseToAttack(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TooCloseToAttack");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckTurretPitchLimit(int NeededPitch, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.CheckTurretPitchLimit");
			byte params[12] = { NULL };
			*(int*)&params[0] = NeededPitch;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void PlayHorn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PlayHorn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DriverLeave(bool bForceLeave)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DriverLeave");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bForceLeave;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void UpdateControllerOnPossess(bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.UpdateControllerOnPossess");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int NumPassengers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.NumPassengers");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		class UTVehicle* GetMoveTargetFor(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetMoveTargetFor");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTVehicle**)&params[4];
		}
		void HandleEnteringFlag(class UTPlayerReplicationInfo* EnteringPRI, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.HandleEnteringFlag");
			byte params[8] = { NULL };
			*(class UTPlayerReplicationInfo**)&params[0] = EnteringPRI;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DriverEnter(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DriverEnter");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void HoldGameObject(class UDKCarriedObject* GameObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.HoldGameObject");
			byte params[4] = { NULL };
			*(class UDKCarriedObject**)&params[0] = GameObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AttachFlag(class UTCarriedObject* FlagActor, class Pawn* NewDriver)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.AttachFlag");
			byte params[8] = { NULL };
			*(class UTCarriedObject**)&params[0] = FlagActor;
			*(class Pawn**)&params[4] = NewDriver;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DriverLeft()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DriverLeft");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetFirstAvailableSeat(bool bSeatMustAllowFlag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetFirstAvailableSeat");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bSeatMustAllowFlag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool PassengerEnter(class Pawn* P, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PassengerEnter");
			byte params[12] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void PassengerLeave(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PassengerLeave");
			byte params[4] = { NULL };
			*(int*)&params[0] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckReset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.CheckReset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool Occupied()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.Occupied");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool OpenPositionFor(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.OpenPositionFor");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float BotDesireability(class UTSquadAI* S, int TeamIndex, class Actor* Objective)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.BotDesireability");
			byte params[16] = { NULL };
			*(class UTSquadAI**)&params[0] = S;
			*(int*)&params[4] = TeamIndex;
			*(class Actor**)&params[8] = Objective;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float ReservationCostMultiplier(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ReservationCostMultiplier");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		bool SpokenFor(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SpokenFor");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.StopsProjectile");
			byte params[8] = { NULL };
			*(class Projectile**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SetReservation(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetReservation");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool TeamLink(int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TeamLink");
			byte params[8] = { NULL };
			*(int*)&params[0] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AllowLinkThroughOwnedActor(class Actor* OwnedActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.AllowLinkThroughOwnedActor");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = OwnedActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HealDamage(int Amount, class Controller* Healer, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.HealDamage");
			byte params[16] = { NULL };
			*(int*)&params[0] = Amount;
			*(class Controller**)&params[4] = Healer;
			*(ScriptClass**)&params[8] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void IncrementLinkedToCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.IncrementLinkedToCount");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DecrementLinkedToCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DecrementLinkedToCount");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartLinkedEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.StartLinkedEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopLinkedEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.StopLinkedEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayHit(float Damage, class Controller* InstigatedBy, Object::Vector HitLocation, ScriptClass* DamageType, Object::Vector Momentum, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PlayHit");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PlayTakeHitEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyTakeHit(class Controller* InstigatedBy, Object::Vector HitLocation, int Damage, ScriptClass* DamageType, Object::Vector Momentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.NotifyTakeHit");
			byte params[36] = { NULL };
			*(class Controller**)&params[0] = InstigatedBy;
			*(Object::Vector*)&params[4] = HitLocation;
			*(int*)&params[16] = Damage;
			*(ScriptClass**)&params[20] = DamageType;
			*(Object::Vector*)&params[24] = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Object::Vector HitLocation, Object::Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TakeDamage");
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
		class Actor* GetHomingTarget(class UTProjectile* Seeker, class Controller* InstigatedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetHomingTarget");
			byte params[12] = { NULL };
			*(class UTProjectile**)&params[0] = Seeker;
			*(class Controller**)&params[4] = InstigatedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[8];
		}
		bool ImportantVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ImportantVehicle");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void InitializeSeats()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.InitializeSeats");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreCacheSeatNames()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PreCacheSeatNames");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitializeTurrets()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.InitializeTurrets");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PossessedBy(class Controller* C, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PossessedBy");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = C;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFiringMode(class Weapon* Weap, byte FiringModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetFiringMode");
			byte params[5] = { NULL };
			*(class Weapon**)&params[0] = Weap;
			params[4] = FiringModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFlashCount(class Weapon* Who)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ClearFlashCount");
			byte params[4] = { NULL };
			*(class Weapon**)&params[0] = Who;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IncrementFlashCount(class Weapon* Who, byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.IncrementFlashCount");
			byte params[5] = { NULL };
			*(class Weapon**)&params[0] = Who;
			params[4] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFlashLocation(class Weapon* Who, byte FireModeNum, Object::Vector NewLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetFlashLocation");
			byte params[17] = { NULL };
			*(class Weapon**)&params[0] = Who;
			params[4] = FireModeNum;
			*(Object::Vector*)&params[8] = NewLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFlashLocation(class Weapon* Who)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ClearFlashLocation");
			byte params[4] = { NULL };
			*(class Weapon**)&params[0] = Who;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetBarrelLocationAndRotation(int SeatIndex, Object::Vector& SocketLocation, Object::Rotator& SocketRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetBarrelLocationAndRotation");
			byte params[28] = { NULL };
			*(int*)&params[0] = SeatIndex;
			*(Object::Vector*)&params[4] = SocketLocation;
			*(Object::Rotator*)&params[16] = SocketRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SocketLocation = *(Object::Vector*)&params[4];
			SocketRotation = *(Object::Rotator*)&params[16];
		}
		Object::Vector GetEffectLocation(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetEffectLocation");
			byte params[16] = { NULL };
			*(int*)&params[0] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[4];
		}
		Object::Vector GetPhysicalFireStartLoc(class UTWeapon* ForWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetPhysicalFireStartLoc");
			byte params[16] = { NULL };
			*(class UTWeapon**)&params[0] = ForWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[4];
		}
		Object::Rotator GetWeaponAim(class UTVehicleWeapon* VWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetWeaponAim");
			byte params[16] = { NULL };
			*(class UTVehicleWeapon**)&params[0] = VWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[4];
		}
		bool OverrideBeginFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.OverrideBeginFire");
			byte params[5] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool OverrideEndFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.OverrideEndFire");
			byte params[5] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void GetWeaponViewAxes(class UTWeapon* WhichWeapon, Object::Vector& XAxis, Object::Vector& YAxis, Object::Vector& ZAxis)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetWeaponViewAxes");
			byte params[40] = { NULL };
			*(class UTWeapon**)&params[0] = WhichWeapon;
			*(Object::Vector*)&params[4] = XAxis;
			*(Object::Vector*)&params[16] = YAxis;
			*(Object::Vector*)&params[28] = ZAxis;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			XAxis = *(Object::Vector*)&params[4];
			YAxis = *(Object::Vector*)&params[16];
			ZAxis = *(Object::Vector*)&params[28];
		}
		void CauseMuzzleFlashLight(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.CauseMuzzleFlashLight");
			byte params[4] = { NULL };
			*(int*)&params[0] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WeaponFired(class Weapon* InWeapon, bool bViaReplication, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.WeaponFired");
			byte params[20] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			*(Object::Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleWeaponFired(bool bViaReplication, Object::Vector HitLocation, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.VehicleWeaponFired");
			byte params[20] = { NULL };
			*(bool*)&params[0] = bViaReplication;
			*(Object::Vector*)&params[4] = HitLocation;
			*(int*)&params[16] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WeaponStoppedFiring(class Weapon* InWeapon, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.WeaponStoppedFiring");
			byte params[8] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleWeaponStoppedFiring(bool bViaReplication, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.VehicleWeaponStoppedFiring");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bViaReplication;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleWeaponFireEffects(Object::Vector HitLocation, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.VehicleWeaponFireEffects");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(int*)&params[12] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Actor* FindWeaponHitNormal(Object::Vector& HitLocation, Object::Vector& HitNormal, Object::Vector End, Object::Vector Start, Actor::TraceHitInfo& HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.FindWeaponHitNormal");
			byte params[80] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(Object::Vector*)&params[12] = HitNormal;
			*(Object::Vector*)&params[24] = End;
			*(Object::Vector*)&params[36] = Start;
			*(Actor::TraceHitInfo*)&params[48] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			HitLocation = *(Object::Vector*)&params[0];
			HitNormal = *(Object::Vector*)&params[12];
			HitInfo = *(Actor::TraceHitInfo*)&params[48];
			return *(class Actor**)&params[76];
		}
		void VehicleWeaponImpactEffects(Object::Vector HitLocation, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.VehicleWeaponImpactEffects");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(int*)&params[12] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnImpactEmitter(Object::Vector HitLocation, Object::Vector HitNormal, UDKPawn::MaterialImpactEffect& ImpactEffect, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SpawnImpactEmitter");
			byte params[76] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(Object::Vector*)&params[12] = HitNormal;
			*(UDKPawn::MaterialImpactEffect*)&params[24] = ImpactEffect;
			*(int*)&params[72] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ImpactEffect = *(UDKPawn::MaterialImpactEffect*)&params[24];
		}
		void VehicleAdjustFlashCount(int SeatIndex, byte FireModeNum, bool bClear)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.VehicleAdjustFlashCount");
			byte params[9] = { NULL };
			*(int*)&params[0] = SeatIndex;
			params[4] = FireModeNum;
			*(bool*)&params[8] = bClear;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleAdjustFlashLocation(int SeatIndex, byte FireModeNum, Object::Vector NewLocation, bool bClear)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.VehicleAdjustFlashLocation");
			byte params[21] = { NULL };
			*(int*)&params[0] = SeatIndex;
			params[4] = FireModeNum;
			*(Object::Vector*)&params[8] = NewLocation;
			*(bool*)&params[20] = bClear;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FindGoodEndView(class PlayerController* PC, Object::Rotator& GoodRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.FindGoodEndView");
			byte params[16] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(Object::Rotator*)&params[4] = GoodRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			GoodRotation = *(Object::Rotator*)&params[4];
		}
		bool CalcCamera(float DeltaTime, Object::Vector& out_CamLoc, Object::Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.CalcCamera");
			byte params[36] = { NULL };
			*(float*)&params[0] = DeltaTime;
			*(Object::Vector*)&params[4] = out_CamLoc;
			*(Object::Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Object::Vector*)&params[4];
			out_CamRot = *(Object::Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
			return *(bool*)&params[32];
		}
		Object::Vector GetCameraFocus(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetCameraFocus");
			byte params[16] = { NULL };
			*(int*)&params[0] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[4];
		}
		Object::Vector GetCameraStart(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetCameraStart");
			byte params[16] = { NULL };
			*(int*)&params[0] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[4];
		}
		float LimitCameraZ(float CurrentCamZ, float OriginalCamZ, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.LimitCameraZ");
			byte params[16] = { NULL };
			*(float*)&params[0] = CurrentCamZ;
			*(float*)&params[4] = OriginalCamZ;
			*(int*)&params[8] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		void VehicleCalcCamera(float DeltaTime, int SeatIndex, Object::Vector& out_CamLoc, Object::Rotator& out_CamRot, Object::Vector& CamStart, bool bPivotOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.VehicleCalcCamera");
			byte params[48] = { NULL };
			*(float*)&params[0] = DeltaTime;
			*(int*)&params[4] = SeatIndex;
			*(Object::Vector*)&params[8] = out_CamLoc;
			*(Object::Rotator*)&params[20] = out_CamRot;
			*(Object::Vector*)&params[32] = CamStart;
			*(bool*)&params[44] = bPivotOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Object::Vector*)&params[8];
			out_CamRot = *(Object::Rotator*)&params[20];
			CamStart = *(Object::Vector*)&params[32];
		}
		void AdjustCameraScale(bool bMoveCameraIn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.AdjustCameraScale");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bMoveCameraIn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartBurnOut()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.StartBurnOut");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TurnOffShadows()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TurnOffShadows");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableDamageSmoke()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DisableDamageSmoke");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableCollision()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DisableCollision");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetBurnOut()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetBurnOut");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldSpawnExplosionLight(Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ShouldSpawnExplosionLight");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(Object::Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void RBPenetrationDestroy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.RBPenetrationDestroy");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RigidBodyCollision(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* HitComponent, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComponent, Actor::CollisionImpactData& Collision, int ContactIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.RigidBodyCollision");
			byte params[48] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = HitComponent;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComponent;
			*(Actor::CollisionImpactData*)&params[8] = Collision;
			*(int*)&params[44] = ContactIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Collision = *(Actor::CollisionImpactData*)&params[8];
		}
		void TurretExplosion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TurretExplosion");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopVehicleSounds()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.StopVehicleSounds");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckDamageSmoke()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.CheckDamageSmoke");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AttachDriver(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.AttachDriver");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SitDriver(class UTPawn* UTP, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SitDriver");
			byte params[8] = { NULL };
			*(class UTPawn**)&params[0] = UTP;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnDriverPhysicsAssetChanged(class UTPawn* UTP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.OnDriverPhysicsAssetChanged");
			byte params[4] = { NULL };
			*(class UTPawn**)&params[0] = UTP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetHumanReadableName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetHumanReadableName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void OnPropertyChange(ScriptName PropName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.OnPropertyChange");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = PropName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetHealth(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetHealth");
			byte params[8] = { NULL };
			*(int*)&params[0] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		float GetCollisionDamageModifier(ScriptArray<Actor::RigidBodyContactInfo>& ContactInfos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetCollisionDamageModifier");
			byte params[16] = { NULL };
			*(ScriptArray<Actor::RigidBodyContactInfo>*)&params[0] = ContactInfos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ContactInfos = *(ScriptArray<Actor::RigidBodyContactInfo>*)&params[0];
			return *(float*)&params[12];
		}
		void InitializeMorphs()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.InitializeMorphs");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceivedHealthChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ReceivedHealthChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyMorphHeal(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ApplyMorphHeal");
			byte params[4] = { NULL };
			*(int*)&params[0] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyRandomMorphDamage(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ApplyRandomMorphDamage");
			byte params[4] = { NULL };
			*(int*)&params[0] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class UTGib* SpawnGibVehicle(Object::Vector SpawnLocation, Object::Rotator SpawnRotation, class StaticMesh* TheMesh, Object::Vector HitLocation, bool bSpinGib, Object::Vector ImpulseDirection, class ParticleSystem* PS_OnBreak, class ParticleSystem* PS_Trail)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SpawnGibVehicle");
			byte params[68] = { NULL };
			*(Object::Vector*)&params[0] = SpawnLocation;
			*(Object::Rotator*)&params[12] = SpawnRotation;
			*(class StaticMesh**)&params[24] = TheMesh;
			*(Object::Vector*)&params[28] = HitLocation;
			*(bool*)&params[40] = bSpinGib;
			*(Object::Vector*)&params[44] = ImpulseDirection;
			*(class ParticleSystem**)&params[56] = PS_OnBreak;
			*(class ParticleSystem**)&params[60] = PS_Trail;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTGib**)&params[64];
		}
		void GetSVehicleDebug(ScriptArray<ScriptString*>& DebugInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetSVehicleDebug");
			byte params[12] = { NULL };
			*(ScriptArray<ScriptString*>*)&params[0] = DebugInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DebugInfo = *(ScriptArray<ScriptString*>*)&params[0];
		}
		void OnExitVehicle(class UTSeqAct_ExitVehicle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.OnExitVehicle");
			byte params[4] = { NULL };
			*(class UTSeqAct_ExitVehicle**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetShieldActive(int SeatIndex, bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetShieldActive");
			byte params[8] = { NULL };
			*(int*)&params[0] = SeatIndex;
			*(bool*)&params[4] = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSeatStoragePawn(int SeatIndex, class Pawn* PawnToSit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetSeatStoragePawn");
			byte params[8] = { NULL };
			*(int*)&params[0] = SeatIndex;
			*(class Pawn**)&params[4] = PawnToSit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMovementEffect(int SeatIndex, bool bSetActive, class UTPawn* UTP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetMovementEffect");
			byte params[12] = { NULL };
			*(int*)&params[0] = SeatIndex;
			*(bool*)&params[4] = bSetActive;
			*(class UTPawn**)&params[8] = UTP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachDriver(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DetachDriver");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanAttack(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.CanAttack");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptName GetVehicleKillStatName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetVehicleKillStatName");
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[0];
		}
		void DisplayHud(class UTHUD* HUD, class Canvas* Canvas, Object::Vector2D HudPOS, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DisplayHud");
			byte params[20] = { NULL };
			*(class UTHUD**)&params[0] = HUD;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector2D*)&params[8] = HudPOS;
			*(int*)&params[16] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawBarGraph(float X, float Y, float Width, float MaxWidth, float Height, class Canvas* DrawCanvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DrawBarGraph");
			byte params[24] = { NULL };
			*(float*)&params[0] = X;
			*(float*)&params[4] = Y;
			*(float*)&params[8] = Width;
			*(float*)&params[12] = MaxWidth;
			*(float*)&params[16] = Height;
			*(class Canvas**)&params[20] = DrawCanvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayExtraHud(class UTHUD* HUD, class Canvas* Canvas, Object::Vector2D pos, float Width, float Height, int SIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DisplayExtraHud");
			byte params[28] = { NULL };
			*(class UTHUD**)&params[0] = HUD;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector2D*)&params[8] = pos;
			*(float*)&params[16] = Width;
			*(float*)&params[20] = Height;
			*(int*)&params[24] = SIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplaySeats(class UTHUD* HUD, class Canvas* Canvas, float PosX, float PosY, float Width, float Height, int SIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DisplaySeats");
			byte params[28] = { NULL };
			*(class UTHUD**)&params[0] = HUD;
			*(class Canvas**)&params[4] = Canvas;
			*(float*)&params[8] = PosX;
			*(float*)&params[12] = PosY;
			*(float*)&params[16] = Width;
			*(float*)&params[20] = Height;
			*(int*)&params[24] = SIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::LinearColor GetSeatColor(int SeatIndex, bool bIsPlayersSeat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetSeatColor");
			byte params[24] = { NULL };
			*(int*)&params[0] = SeatIndex;
			*(bool*)&params[4] = bIsPlayersSeat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::LinearColor*)&params[8];
		}
		void ApplyWeaponEffects(int OverlayFlags, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ApplyWeaponEffects");
			byte params[8] = { NULL };
			*(int*)&params[0] = OverlayFlags;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldLeaveForCombat(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ShouldLeaveForCombat");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
