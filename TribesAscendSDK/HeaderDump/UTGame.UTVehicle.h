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
		struct MaterialList
		{
		public:
			ADD_STRUCT(ScriptArray<class MaterialInterface*>, Materials, 0)
		};
		struct TimePosition
		{
		public:
			ADD_STRUCT(float, Time, 12)
			ADD_STRUCT(Vector, Position, 0)
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
		ADD_STRUCT(Vector, OldCameraPosition, 2696)
		ADD_OBJECT(UTGib, DeathCameraGib, 2692)
		ADD_STRUCT(float, MinCameraDistSq, 2688)
		ADD_STRUCT(float, LookForwardDist, 2684)
		ADD_STRUCT(Vector, CameraOffset, 2672)
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
		ADD_STRUCT(Vector, PassengerTeamBeaconOffset, 2528)
		ADD_OBJECT(PlayerReplicationInfo, PassengerPRI, 2512)
		ADD_STRUCT(Vector, TeamBeaconOffset, 2500)
		ADD_STRUCT(float, HealthPulseTime, 2496)
		ADD_STRUCT(int, LastHealth, 2492)
		ADD_STRUCT(UIRoot::TextureCoordinates, DropOrbIconCoords, 2476)
		ADD_STRUCT(UIRoot::TextureCoordinates, DropFlagIconCoords, 2460)
		ADD_STRUCT(UIRoot::TextureCoordinates, EnterToolTipIconCoords, 2444)
		ADD_STRUCT(UIRoot::TextureCoordinates, FlipToolTipIconCoords, 2428)
		ADD_STRUCT(UIRoot::TextureCoordinates, IconCoords, 2412)
		ADD_STRUCT(float, MapSize, 2408)
		ADD_STRUCT(ScriptName, FlagBone, 2400)
		ADD_STRUCT(Rotator, FlagRotation, 2388)
		ADD_STRUCT(Vector, FlagOffset, 2376)
		ADD_OBJECT(SoundCue, BoostPadSound, 2372)
		ADD_OBJECT(SoundCue, SpawnOutSound, 2368)
		ADD_OBJECT(SoundCue, SpawnInSound, 2364)
		ADD_STRUCT(float, SpawnRadius, 2360)
		ADD_STRUCT(ScriptName, BurnTimeParameterName, 2352)
		ADD_OBJECT(SoundCue, ExplosionSound, 2348)
		ADD_STRUCT(float, TurretExplosiveForce, 2344)
		ADD_OBJECT(StaticMesh, DestroyedTurretTemplate, 2340)
		ADD_OBJECT(UTVehicleDeathPiece, DestroyedTurret, 2336)
		ADD_STRUCT(Vector, TurretOffset, 2324)
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36430);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool InCustomEntryRadius(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36452);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39358);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateShadowSettings(bool bWantShadow)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39360);
			byte params[4] = { NULL };
			*(bool*)params = bWantShadow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReattachMesh()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39364);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateDamageMaterialInstance()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39365);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateLookSteerStatus()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39366);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInputs(float InForward, float InStrafe, float InUp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39368);
			byte params[12] = { NULL };
			*(float*)params = InForward;
			*(float*)&params[4] = InStrafe;
			*(float*)&params[8] = InUp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39384);
			byte params[4] = { NULL };
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetChargePower()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39386);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void PlaySpawnEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39388);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopSpawnEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39391);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EjectSeat(int SeatIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39393);
			byte params[4] = { NULL };
			*(int*)params = SeatIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptClass* GetRanOverDamageType()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39396);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)params;
		}
		void DisplayWeaponBar(class Canvas* Canvas, class UTHUD* HUD)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39398);
			byte params[8] = { NULL };
			*(class Canvas**)params = Canvas;
			*(class UTHUD**)&params[4] = HUD;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawKillIcon(class Canvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39402);
			byte params[20] = { NULL };
			*(class Canvas**)params = Canvas;
			*(float*)&params[4] = ScreenX;
			*(float*)&params[8] = ScreenY;
			*(float*)&params[12] = HUDScaleX;
			*(float*)&params[16] = HUDScaleY;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderMapIcon(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, Object::LinearColor FinalColor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39411);
			byte params[28] = { NULL };
			*(class UTMapInfo**)params = MP;
			*(class Canvas**)&params[4] = Canvas;
			*(class UTPlayerController**)&params[8] = PlayerOwner;
			*(Object::LinearColor*)&params[12] = FinalColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float AdjustedStrength()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39417);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		bool ContinueOnFoot()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39419);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsDriverSeat(class Vehicle* TestSeatPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39426);
			byte params[8] = { NULL };
			*(class Vehicle**)params = TestSeatPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool RecommendCharge(class UTBot* B, class Pawn* Enemy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39429);
			byte params[12] = { NULL };
			*(class UTBot**)params = B;
			*(class Pawn**)&params[4] = Enemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool CriticalChargeAttack(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39433);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void CreateVehicleEffect(int EffectIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39436);
			byte params[4] = { NULL };
			*(int*)params = EffectIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitializeEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39439);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetVehicleEffectParms(ScriptName TriggerName, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39440);
			byte params[12] = { NULL };
			*(ScriptName*)params = TriggerName;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[8] = PSC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TriggerVehicleEffect(ScriptName EventTag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39444);
			byte params[8] = { NULL };
			*(ScriptName*)params = EventTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayVehicleSound(ScriptName SoundTag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39447);
			byte params[8] = { NULL };
			*(ScriptName*)params = SoundTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayVehicleAnimation(ScriptName EventTag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39450);
			byte params[8] = { NULL };
			*(ScriptName*)params = EventTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleEvent(ScriptName EventTag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39455);
			byte params[8] = { NULL };
			*(ScriptName*)params = EventTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EntryAnnouncement(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39457);
			byte params[4] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Rotator ExitRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39460);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)params;
		}
		bool FindAutoExit(class Pawn* ExitingDriver)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39462);
			byte params[8] = { NULL };
			*(class Pawn**)params = ExitingDriver;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void RanInto(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39472);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PancakeOther(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39479);
			byte params[4] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeWaterDamage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39481);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DriverRadiusDamage(float DamageAmount, float DamageRadius, class Controller* EventInstigator, ScriptClass* DamageType, float Momentum, Vector HitLocation, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39483);
			byte params[40] = { NULL };
			*(float*)params = DamageAmount;
			*(float*)&params[4] = DamageRadius;
			*(class Controller**)&params[8] = EventInstigator;
			*(ScriptClass**)&params[12] = DamageType;
			*(float*)&params[16] = Momentum;
			*(Vector*)&params[20] = HitLocation;
			*(class Actor**)&params[32] = DamageCauser;
			*(float*)&params[36] = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39495);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetTexturesToBeResident(bool bActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39500);
			byte params[4] = { NULL };
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DisableVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39505);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void EnableVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39508);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeFireDamage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39509);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetSeatIndexFromPrefix(ScriptString* Prefix)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39511);
			byte params[16] = { NULL };
			*(ScriptString**)params = Prefix;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		void ServerSetConsoleTurning(bool bNewConsoleTurning)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39515);
			byte params[4] = { NULL };
			*(bool*)params = bNewConsoleTurning;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessViewRotation(float DeltaTime, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39517);
			byte params[28] = { NULL };
			*(float*)params = DeltaTime;
			*(Rotator*)&params[4] = out_ViewRotation;
			*(Rotator*)&params[16] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Rotator*)&params[4];
			out_DeltaRot = *(Rotator*)&params[16];
		}
		Rotator GetClampedViewRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39524);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)params;
		}
		bool ShouldClamp()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39532);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		Rotator GetViewRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39534);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)params;
		}
		void WeaponRotationChanged(int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39536);
			byte params[4] = { NULL };
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39539);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetKeyVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39543);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrivingStatusChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39544);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39545);
			byte params[12] = { NULL };
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)&params[4] = PlayedTime;
			*(float*)&params[8] = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SeatAvailable(int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39549);
			byte params[8] = { NULL };
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AnySeatAvailable()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39552);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		int GetSeatIndexForController(class Controller* ControllerToMove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39555);
			byte params[8] = { NULL };
			*(class Controller**)params = ControllerToMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		class Controller* GetControllerForSeatIndex(int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39559);
			byte params[8] = { NULL };
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Controller**)&params[4];
		}
		void ServerAdjacentSeat(int Direction, class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39562);
			byte params[8] = { NULL };
			*(int*)params = Direction;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerChangeSeat(int RequestedSeat)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39567);
			byte params[4] = { NULL };
			*(int*)params = RequestedSeat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HasPriority(class Controller* first, class Controller* Second)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39569);
			byte params[12] = { NULL };
			*(class Controller**)params = first;
			*(class Controller**)&params[4] = Second;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool ChangeSeat(class Controller* ControllerToMove, int RequestedSeat)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39573);
			byte params[12] = { NULL };
			*(class Controller**)params = ControllerToMove;
			*(int*)&params[4] = RequestedSeat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void TornOff()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39581);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Controller* GetCollisionDamageInstigator()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39582);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Controller**)params;
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39584);
			byte params[24] = { NULL };
			*(class Controller**)params = Killer;
			*(ScriptClass**)&params[4] = DamageType;
			*(Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		void BlowupVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39595);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class PlayerReplicationInfo* GetSeatPRI(int SeatNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39598);
			byte params[8] = { NULL };
			*(int*)params = SeatNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerReplicationInfo**)&params[4];
		}
		bool CanEnterVehicle(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39601);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool KickOutBot()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39614);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void VehicleLocked(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39618);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldShowUseable(class PlayerController* PC, float Dist)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39621);
			byte params[12] = { NULL };
			*(class PlayerController**)params = PC;
			*(float*)&params[4] = Dist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39626);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetDisplayedHealth()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39648);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void RenderPassengerBeacons(class PlayerController* PC, class Canvas* Canvas, Object::LinearColor TeamColor, Object::Color TextColor, class UTWeapon* Weap)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39650);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::LinearColor*)&params[8] = TeamColor;
			*(Object::Color*)&params[24] = TextColor;
			*(class UTWeapon**)&params[28] = Weap;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRenderPassengerBeacon(class PlayerController* PC, class Canvas* Canvas, Object::LinearColor TeamColor, Object::Color TextColor, class UTWeapon* Weap, class PlayerReplicationInfo* InPassengerPRI, Vector InPassengerTeamBeaconOffset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39656);
			byte params[48] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::LinearColor*)&params[8] = TeamColor;
			*(Object::Color*)&params[24] = TextColor;
			*(class UTWeapon**)&params[28] = Weap;
			*(class PlayerReplicationInfo**)&params[32] = InPassengerPRI;
			*(Vector*)&params[36] = InPassengerTeamBeaconOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTeamNum(byte T)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39671);
			byte params[1] = { NULL };
			*params = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39673);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TeamChanged_VehicleEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39675);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool Dodge(Actor::EDoubleClickDir DoubleClickMove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39680);
			byte params[5] = { NULL };
			*(Actor::EDoubleClickDir*)params = DoubleClickMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void IncomingMissile(class Projectile* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39683);
			byte params[4] = { NULL };
			*(class Projectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShootMissile(class Projectile* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39686);
			byte params[4] = { NULL };
			*(class Projectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendLockOnMessage(int Switch)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39688);
			byte params[4] = { NULL };
			*(int*)params = Switch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LockOnWarning(class UDKProjectile* IncomingMissile)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39693);
			byte params[4] = { NULL };
			*(class UDKProjectile**)params = IncomingMissile;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool TooCloseToAttack(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39695);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckTurretPitchLimit(int NeededPitch, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39701);
			byte params[12] = { NULL };
			*(int*)params = NeededPitch;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void PlayHorn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39706);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DriverLeave(bool bForceLeave)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39713);
			byte params[8] = { NULL };
			*(bool*)params = bForceLeave;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void UpdateControllerOnPossess(bool bVehicleTransition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39715);
			byte params[4] = { NULL };
			*(bool*)params = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int NumPassengers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39717);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		class UTVehicle* GetMoveTargetFor(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39721);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTVehicle**)&params[4];
		}
		void HandleEnteringFlag(class UTPlayerReplicationInfo* EnteringPRI, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39724);
			byte params[8] = { NULL };
			*(class UTPlayerReplicationInfo**)params = EnteringPRI;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DriverEnter(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39729);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void HoldGameObject(class UDKCarriedObject* GameObj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39734);
			byte params[4] = { NULL };
			*(class UDKCarriedObject**)params = GameObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AttachFlag(class UTCarriedObject* FlagActor, class Pawn* NewDriver)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39738);
			byte params[8] = { NULL };
			*(class UTCarriedObject**)params = FlagActor;
			*(class Pawn**)&params[4] = NewDriver;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DriverLeft()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39741);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetFirstAvailableSeat(bool bSeatMustAllowFlag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39744);
			byte params[8] = { NULL };
			*(bool*)params = bSeatMustAllowFlag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool PassengerEnter(class Pawn* P, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39748);
			byte params[12] = { NULL };
			*(class Pawn**)params = P;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void PassengerLeave(int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39755);
			byte params[4] = { NULL };
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckReset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39757);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool Occupied()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39760);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool OpenPositionFor(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39763);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float BotDesireability(class UTSquadAI* S, int TeamIndex, class Actor* Objective)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39769);
			byte params[16] = { NULL };
			*(class UTSquadAI**)params = S;
			*(int*)&params[4] = TeamIndex;
			*(class Actor**)&params[8] = Objective;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float ReservationCostMultiplier(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39776);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		bool SpokenFor(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39779);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39783);
			byte params[8] = { NULL };
			*(class Projectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SetReservation(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39786);
			byte params[4] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool TeamLink(int TeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39788);
			byte params[8] = { NULL };
			*(int*)params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AllowLinkThroughOwnedActor(class Actor* OwnedActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39791);
			byte params[8] = { NULL };
			*(class Actor**)params = OwnedActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HealDamage(int Amount, class Controller* Healer, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39794);
			byte params[16] = { NULL };
			*(int*)params = Amount;
			*(class Controller**)&params[4] = Healer;
			*(ScriptClass**)&params[8] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void IncrementLinkedToCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39799);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DecrementLinkedToCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39800);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartLinkedEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39801);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopLinkedEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39806);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayHit(float Damage, class Controller* InstigatedBy, Vector HitLocation, ScriptClass* DamageType, Vector Momentum, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39810);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39822);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyTakeHit(class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39824);
			byte params[36] = { NULL };
			*(class Controller**)params = InstigatedBy;
			*(Vector*)&params[4] = HitLocation;
			*(int*)&params[16] = Damage;
			*(ScriptClass**)&params[20] = DamageType;
			*(Vector*)&params[24] = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39831);
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
		class Actor* GetHomingTarget(class UTProjectile* Seeker, class Controller* InstigatedBy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39843);
			byte params[12] = { NULL };
			*(class UTProjectile**)params = Seeker;
			*(class Controller**)&params[4] = InstigatedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[8];
		}
		bool ImportantVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39847);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void InitializeSeats()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39849);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreCacheSeatNames()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39853);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitializeTurrets()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39855);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PossessedBy(class Controller* C, bool bVehicleTransition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39862);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFiringMode(class Weapon* Weap, byte FiringModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39865);
			byte params[5] = { NULL };
			*(class Weapon**)params = Weap;
			params[4] = FiringModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFlashCount(class Weapon* Who)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39868);
			byte params[4] = { NULL };
			*(class Weapon**)params = Who;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IncrementFlashCount(class Weapon* Who, byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39871);
			byte params[5] = { NULL };
			*(class Weapon**)params = Who;
			params[4] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFlashLocation(class Weapon* Who, byte FireModeNum, Vector NewLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39875);
			byte params[17] = { NULL };
			*(class Weapon**)params = Who;
			params[4] = FireModeNum;
			*(Vector*)&params[8] = NewLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFlashLocation(class Weapon* Who)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39880);
			byte params[4] = { NULL };
			*(class Weapon**)params = Who;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetBarrelLocationAndRotation(int SeatIndex, Vector& SocketLocation, Rotator& SocketRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39883);
			byte params[28] = { NULL };
			*(int*)params = SeatIndex;
			*(Vector*)&params[4] = SocketLocation;
			*(Rotator*)&params[16] = SocketRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SocketLocation = *(Vector*)&params[4];
			SocketRotation = *(Rotator*)&params[16];
		}
		Vector GetEffectLocation(int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39887);
			byte params[16] = { NULL };
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[4];
		}
		Vector GetPhysicalFireStartLoc(class UTWeapon* ForWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39891);
			byte params[16] = { NULL };
			*(class UTWeapon**)params = ForWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[4];
		}
		Rotator GetWeaponAim(class UTVehicleWeapon* VWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39895);
			byte params[16] = { NULL };
			*(class UTVehicleWeapon**)params = VWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[4];
		}
		bool OverrideBeginFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39919);
			byte params[5] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool OverrideEndFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39922);
			byte params[5] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void GetWeaponViewAxes(class UTWeapon* WhichWeapon, Vector& XAxis, Vector& YAxis, Vector& ZAxis)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39925);
			byte params[40] = { NULL };
			*(class UTWeapon**)params = WhichWeapon;
			*(Vector*)&params[4] = XAxis;
			*(Vector*)&params[16] = YAxis;
			*(Vector*)&params[28] = ZAxis;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			XAxis = *(Vector*)&params[4];
			YAxis = *(Vector*)&params[16];
			ZAxis = *(Vector*)&params[28];
		}
		void CauseMuzzleFlashLight(int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39930);
			byte params[4] = { NULL };
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WeaponFired(class Weapon* InWeapon, bool bViaReplication, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39932);
			byte params[20] = { NULL };
			*(class Weapon**)params = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			*(Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleWeaponFired(bool bViaReplication, Vector HitLocation, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39936);
			byte params[20] = { NULL };
			*(bool*)params = bViaReplication;
			*(Vector*)&params[4] = HitLocation;
			*(int*)&params[16] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WeaponStoppedFiring(class Weapon* InWeapon, bool bViaReplication)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39940);
			byte params[8] = { NULL };
			*(class Weapon**)params = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleWeaponStoppedFiring(bool bViaReplication, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39943);
			byte params[8] = { NULL };
			*(bool*)params = bViaReplication;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleWeaponFireEffects(Vector HitLocation, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39949);
			byte params[16] = { NULL };
			*(Vector*)params = HitLocation;
			*(int*)&params[12] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Actor* FindWeaponHitNormal(Vector& HitLocation, Vector& HitNormal, Vector End, Vector Start, Actor::TraceHitInfo& HitInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39952);
			byte params[80] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			*(Vector*)&params[24] = End;
			*(Vector*)&params[36] = Start;
			*(Actor::TraceHitInfo*)&params[48] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			HitLocation = *(Vector*)params;
			HitNormal = *(Vector*)&params[12];
			HitInfo = *(Actor::TraceHitInfo*)&params[48];
			return *(class Actor**)&params[76];
		}
		void VehicleWeaponImpactEffects(Vector HitLocation, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39959);
			byte params[16] = { NULL };
			*(Vector*)params = HitLocation;
			*(int*)&params[12] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnImpactEmitter(Vector HitLocation, Vector HitNormal, UDKPawn::MaterialImpactEffect& ImpactEffect, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39977);
			byte params[76] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			*(UDKPawn::MaterialImpactEffect*)&params[24] = ImpactEffect;
			*(int*)&params[72] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ImpactEffect = *(UDKPawn::MaterialImpactEffect*)&params[24];
		}
		void VehicleAdjustFlashCount(int SeatIndex, byte FireModeNum, bool bClear)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39982);
			byte params[9] = { NULL };
			*(int*)params = SeatIndex;
			params[4] = FireModeNum;
			*(bool*)&params[8] = bClear;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleAdjustFlashLocation(int SeatIndex, byte FireModeNum, Vector NewLocation, bool bClear)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39986);
			byte params[21] = { NULL };
			*(int*)params = SeatIndex;
			params[4] = FireModeNum;
			*(Vector*)&params[8] = NewLocation;
			*(bool*)&params[20] = bClear;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FindGoodEndView(class PlayerController* PC, Rotator& GoodRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39991);
			byte params[16] = { NULL };
			*(class PlayerController**)params = PC;
			*(Rotator*)&params[4] = GoodRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			GoodRotation = *(Rotator*)&params[4];
		}
		bool CalcCamera(float DeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40001);
			byte params[36] = { NULL };
			*(float*)params = DeltaTime;
			*(Vector*)&params[4] = out_CamLoc;
			*(Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Vector*)&params[4];
			out_CamRot = *(Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
			return *(bool*)&params[32];
		}
		Vector GetCameraFocus(int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40008);
			byte params[16] = { NULL };
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[4];
		}
		Vector GetCameraStart(int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40015);
			byte params[16] = { NULL };
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[4];
		}
		float LimitCameraZ(float CurrentCamZ, float OriginalCamZ, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40026);
			byte params[16] = { NULL };
			*(float*)params = CurrentCamZ;
			*(float*)&params[4] = OriginalCamZ;
			*(int*)&params[8] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		void VehicleCalcCamera(float DeltaTime, int SeatIndex, Vector& out_CamLoc, Rotator& out_CamRot, Vector& CamStart, bool bPivotOnly)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40033);
			byte params[48] = { NULL };
			*(float*)params = DeltaTime;
			*(int*)&params[4] = SeatIndex;
			*(Vector*)&params[8] = out_CamLoc;
			*(Rotator*)&params[20] = out_CamRot;
			*(Vector*)&params[32] = CamStart;
			*(bool*)&params[44] = bPivotOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Vector*)&params[8];
			out_CamRot = *(Rotator*)&params[20];
			CamStart = *(Vector*)&params[32];
		}
		void AdjustCameraScale(bool bMoveCameraIn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40060);
			byte params[4] = { NULL };
			*(bool*)params = bMoveCameraIn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartBurnOut()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40062);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TurnOffShadows()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40065);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableDamageSmoke()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40066);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableCollision()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40067);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetBurnOut()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40068);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldSpawnExplosionLight(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40075);
			byte params[28] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void RBPenetrationDestroy()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40081);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RigidBodyCollision(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* HitComponent, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComponent, Actor::CollisionImpactData& Collision, int ContactIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40149);
			byte params[48] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = HitComponent;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40169);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopVehicleSounds()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40174);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckDamageSmoke()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40176);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AttachDriver(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40177);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SitDriver(class UTPawn* UTP, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40180);
			byte params[8] = { NULL };
			*(class UTPawn**)params = UTP;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnDriverPhysicsAssetChanged(class UTPawn* UTP)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40183);
			byte params[4] = { NULL };
			*(class UTPawn**)params = UTP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetHumanReadableName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40185);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void OnPropertyChange(ScriptName PropName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40187);
			byte params[8] = { NULL };
			*(ScriptName*)params = PropName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetHealth(int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40190);
			byte params[8] = { NULL };
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		float GetCollisionDamageModifier(ScriptArray<Actor::RigidBodyContactInfo>& ContactInfos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40193);
			byte params[16] = { NULL };
			*(ScriptArray<Actor::RigidBodyContactInfo>*)params = ContactInfos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ContactInfos = *(ScriptArray<Actor::RigidBodyContactInfo>*)params;
			return *(float*)&params[12];
		}
		void InitializeMorphs()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40208);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceivedHealthChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40211);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyMorphHeal(int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40213);
			byte params[4] = { NULL };
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyRandomMorphDamage(int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40220);
			byte params[4] = { NULL };
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class UTGib* SpawnGibVehicle(Vector SpawnLocation, Rotator SpawnRotation, class StaticMesh* TheMesh, Vector HitLocation, bool bSpinGib, Vector ImpulseDirection, class ParticleSystem* PS_OnBreak, class ParticleSystem* PS_Trail)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40227);
			byte params[68] = { NULL };
			*(Vector*)params = SpawnLocation;
			*(Rotator*)&params[12] = SpawnRotation;
			*(class StaticMesh**)&params[24] = TheMesh;
			*(Vector*)&params[28] = HitLocation;
			*(bool*)&params[40] = bSpinGib;
			*(Vector*)&params[44] = ImpulseDirection;
			*(class ParticleSystem**)&params[56] = PS_OnBreak;
			*(class ParticleSystem**)&params[60] = PS_Trail;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTGib**)&params[64];
		}
		void GetSVehicleDebug(ScriptArray<ScriptString*>& DebugInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40247);
			byte params[12] = { NULL };
			*(ScriptArray<ScriptString*>*)params = DebugInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DebugInfo = *(ScriptArray<ScriptString*>*)params;
		}
		void OnExitVehicle(class UTSeqAct_ExitVehicle* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40251);
			byte params[4] = { NULL };
			*(class UTSeqAct_ExitVehicle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetShieldActive(int SeatIndex, bool bActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40255);
			byte params[8] = { NULL };
			*(int*)params = SeatIndex;
			*(bool*)&params[4] = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSeatStoragePawn(int SeatIndex, class Pawn* PawnToSit)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40258);
			byte params[8] = { NULL };
			*(int*)params = SeatIndex;
			*(class Pawn**)&params[4] = PawnToSit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMovementEffect(int SeatIndex, bool bSetActive, class UTPawn* UTP)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40262);
			byte params[12] = { NULL };
			*(int*)params = SeatIndex;
			*(bool*)&params[4] = bSetActive;
			*(class UTPawn**)&params[8] = UTP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachDriver(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40268);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanAttack(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40270);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptName GetVehicleKillStatName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40275);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)params;
		}
		void DisplayHud(class UTHUD* HUD, class Canvas* Canvas, Object::Vector2D HudPOS, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40278);
			byte params[20] = { NULL };
			*(class UTHUD**)params = HUD;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector2D*)&params[8] = HudPOS;
			*(int*)&params[16] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawBarGraph(float X, float Y, float Width, float MaxWidth, float Height, class Canvas* DrawCanvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40299);
			byte params[24] = { NULL };
			*(float*)params = X;
			*(float*)&params[4] = Y;
			*(float*)&params[8] = Width;
			*(float*)&params[12] = MaxWidth;
			*(float*)&params[16] = Height;
			*(class Canvas**)&params[20] = DrawCanvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayExtraHud(class UTHUD* HUD, class Canvas* Canvas, Object::Vector2D pos, float Width, float Height, int SIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40306);
			byte params[28] = { NULL };
			*(class UTHUD**)params = HUD;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector2D*)&params[8] = pos;
			*(float*)&params[16] = Width;
			*(float*)&params[20] = Height;
			*(int*)&params[24] = SIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplaySeats(class UTHUD* HUD, class Canvas* Canvas, float PosX, float PosY, float Width, float Height, int SIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40313);
			byte params[28] = { NULL };
			*(class UTHUD**)params = HUD;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40326);
			byte params[24] = { NULL };
			*(int*)params = SeatIndex;
			*(bool*)&params[4] = bIsPlayersSeat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::LinearColor*)&params[8];
		}
		void ApplyWeaponEffects(int OverlayFlags, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40332);
			byte params[8] = { NULL };
			*(int*)params = OverlayFlags;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldLeaveForCombat(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40342);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
