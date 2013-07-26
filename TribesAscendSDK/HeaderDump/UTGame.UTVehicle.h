#pragma once
#include "UDKBase.UDKPlayerController.ObjectiveAnnouncementInfo.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.ParticleSystem.h"
#include "UDKBase.UDKVehicle.h"
#include "UDKBase.UDKProjectile.h"
#include "UTGame.UTGib.h"
#include "Engine.StaticMesh.h"
#include "Core.Object.Vector.h"
#include "UTGame.UTWeapon.h"
#include "UTGame.UTHUD.h"
#include "Engine.UIRoot.TextureCoordinates.h"
#include "Engine.MaterialInterface.h"
#include "UTGame.UTMapInfo.h"
#include "Core.Object.InterpCurveFloat.h"
#include "Engine.Texture2D.h"
#include "Core.Object.Rotator.h"
#include "Engine.SoundCue.h"
#include "Engine.Actor.h"
#include "UTGame.UTVehicleDeathPiece.h"
#include "UTGame.UTPlayerController.h"
#include "Engine.CameraAnim.h"
#include "UTGame.UTBot.h"
#include "Engine.Emitter.h"
#include "UTGame.UTVehicleFactory.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.Weapon.h"
#include "Engine.Pawn.h"
#include "Engine.Canvas.h"
#include "Core.Object.LinearColor.h"
#include "Engine.Vehicle.h"
#include "Engine.Controller.h"
#include "Engine.AnimNodeSequence.h"
#include "Engine.PlayerController.h"
#include "Core.Object.Color.h"
#include "UTGame.UTCarriedObject.h"
#include "Engine.Projectile.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "UDKBase.UDKCarriedObject.h"
#include "UTGame.UTSquadAI.h"
#include "Engine.Actor.TraceHitInfo.h"
#include "UTGame.UTVehicleWeapon.h"
#include "UTGame.UTProjectile.h"
#include "UDKBase.UDKPawn.MaterialImpactEffect.h"
#include "Engine.Actor.CollisionImpactData.h"
#include "UTGame.UTPawn.h"
#include "UTGame.UTSeqAct_ExitVehicle.h"
#include "Core.Object.Vector2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTVehicle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTVehicle : public UDKVehicle
	{
	public:
		ADD_VAR(::BoolProperty, bCanCarryFlag, 0x2)
		ADD_VAR(::BoolProperty, bRequestedEntryWithFlag, 0x200000)
		ADD_VAR(::BoolProperty, bHasCustomEntryRadius, 0x10)
		ADD_OBJECT(UTVehicle, NextVehicle)
		ADD_VAR(::FloatProperty, DefaultFOV, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDropDetailWhenDriving, 0x10000)
		ADD_VAR(::BoolProperty, bSpectatedView, 0x200)
		ADD_VAR(::FloatProperty, LastEnemyWarningTime, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, ReferenceMovementMesh)
		ADD_OBJECT(ParticleSystem, DisabledTemplate)
		ADD_VAR(::FloatProperty, TimeLastDisabled, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DisabledTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, OldCameraPosition, 0xFFFFFFFF)
		ADD_OBJECT(UTGib, DeathCameraGib)
		ADD_VAR(::FloatProperty, MinCameraDistSq, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookForwardDist, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, CameraOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraLag, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraSmoothingFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldCamPosZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SeatCameraScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastCollisionDamageTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CollisionDamageMult, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, BurnOutMaterial)
		ADD_VAR(::FloatProperty, SpawnInTime, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<InterpCurveFloat>, SpawnMaterialParameterCurve, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SpawnMaterialParameterName, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, HudCoords, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, HudIcons)
		ADD_STRUCT(::VectorProperty, PassengerTeamBeaconOffset, 0xFFFFFFFF)
		ADD_OBJECT(PlayerReplicationInfo, PassengerPRI)
		ADD_STRUCT(::VectorProperty, TeamBeaconOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HealthPulseTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastHealth, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, DropOrbIconCoords, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, DropFlagIconCoords, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, EnterToolTipIconCoords, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, FlipToolTipIconCoords, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, IconCoords, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MapSize, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, FlagBone, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, FlagRotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FlagOffset, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, BoostPadSound)
		ADD_OBJECT(SoundCue, SpawnOutSound)
		ADD_OBJECT(SoundCue, SpawnInSound)
		ADD_VAR(::FloatProperty, SpawnRadius, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BurnTimeParameterName, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, ExplosionSound)
		ADD_VAR(::FloatProperty, TurretExplosiveForce, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, DestroyedTurretTemplate)
		ADD_OBJECT(UTVehicleDeathPiece, DestroyedTurret)
		ADD_STRUCT(::VectorProperty, TurretOffset, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, TurretSocketName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, TurretScaleControlName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OuterExplosionShakeRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InnerExplosionShakeRadius, 0xFFFFFFFF)
		ADD_OBJECT(CameraAnim, DeathExplosionShake)
		ADD_VAR(::FloatProperty, ExplosionInAirAngVel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExplosionMomentum, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExplosionRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExplosionDamage, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DelayedBurnoutCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeadVehicleLifeSpan, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BurnOutTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BigExplosionSocket, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, SecondaryExplosion)
		ADD_OBJECT(ParticleSystem, ExplosionTemplate)
		ADD_VAR(::FloatProperty, MaxFireEffectDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxImpactEffectDistance, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, ExplosionDamageType)
		ADD_VAR(::FloatProperty, DamageSmokeThreshold, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, VehiclePieceClass)
		ADD_VAR(::IntProperty, ClientHealth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeTilSecondaryVehicleExplosion, 0xFFFFFFFF)
		ADD_OBJECT(Emitter, DeathExplosion)
		ADD_VAR(::FloatProperty, MaxExplosionLightDistance, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, ExplosionLightClass)
		ADD_OBJECT(ScriptClass, VehicleDrowningDamType)
		ADD_VAR(::FloatProperty, HUDExtent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TeamBeaconPlayerInfoMaxDist, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ObjectiveAnnouncementInfo>, NeedToPickUpAnnouncement, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, VehicleNameString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, VehiclePositionString, 0xFFFFFFFF)
		ADD_OBJECT(UTBot, Reservation)
		ADD_OBJECT(UTVehicleFactory, ParentFactory)
		ADD_OBJECT(SoundCue, StolenSound)
		ADD_VAR(::IntProperty, StolenAnnouncementIndex, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, RanOverSound)
		ADD_OBJECT(ScriptClass, RanOverDamageType)
		ADD_OBJECT(SoundCue, LockedOnSound)
		ADD_VAR(::FloatProperty, ConsoleSteerScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookSteerDeadZone, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookSteerDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookSteerSensitivity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LeftStickDirDeadZone, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HornIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastHornTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HornAIRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDesireability, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, LinkedEndSound)
		ADD_OBJECT(SoundCue, LinkedToCue)
		ADD_VAR(::FloatProperty, LinkHealMult, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InitialSpawnDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RespawnTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PlayerStartTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VehicleLostTime, 0xFFFFFFFF)
		ADD_OBJECT(PhysicalMaterial, DefaultPhysicalMaterial)
		ADD_OBJECT(PhysicalMaterial, DrivingPhysicalMaterial)
		ADD_VAR(::FloatProperty, DeflectionReverseThresh, 0xFFFFFFFF)
		ADD_OBJECT(Actor, NoPassengerObjective)
		ADD_VAR(::ByteProperty, LinkedToCount, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AIPurpose, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDriverHoldsFlag, 0x1)
		ADD_OBJECT(SoundCue, VehicleLockedSound)
		ADD_VAR(::BoolProperty, bIsNecrisVehicle, 0x100)
		ADD_VAR(::BoolProperty, bHasEnemyVehicleSound, 0x80)
		ADD_VAR(::BoolProperty, bStealthVehicle, 0x40)
		ADD_VAR(::BoolProperty, bShowDamageDebug, 0x20)
		ADD_VAR(::BoolProperty, bAcceptTurretJump, 0x10)
		ADD_VAR(::BoolProperty, bIsConsoleTurning, 0x8)
		ADD_VAR(::BoolProperty, bStopDeathCamera, 0x4)
		ADD_VAR(::BoolProperty, bCameraNeverHidesVehicle, 0x2)
		ADD_VAR(::BoolProperty, bFixedCamZ, 0x1)
		ADD_VAR(::BoolProperty, bNoFollowJumpZ, 0x80000000)
		ADD_VAR(::BoolProperty, bLimitCameraZLookingUp, 0x40000000)
		ADD_VAR(::BoolProperty, bNoZSmoothing, 0x20000000)
		ADD_VAR(::BoolProperty, bRotateCameraUnderVehicle, 0x10000000)
		ADD_VAR(::BoolProperty, bReducedFallingCollisionDamage, 0x8000000)
		ADD_VAR(::BoolProperty, bPlayingSpawnEffect, 0x4000000)
		ADD_VAR(::BoolProperty, bPostRenderTraceSucceeded, 0x2000000)
		ADD_VAR(::BoolProperty, bHasTurretExplosion, 0x1000000)
		ADD_VAR(::BoolProperty, bRagdollDriverOnDarkwalkerHorn, 0x800000)
		ADD_VAR(::BoolProperty, bInitializedVehicleEffects, 0x400000)
		ADD_VAR(::BoolProperty, bFindGroundExit, 0x100000)
		ADD_VAR(::BoolProperty, bUsingLookSteer, 0x80000)
		ADD_VAR(::BoolProperty, bLookSteerOnSimpleControls, 0x40000)
		ADD_VAR(::BoolProperty, bLookSteerOnNormalControls, 0x20000)
		ADD_VAR(::BoolProperty, bHasBeenDriven, 0x8000)
		ADD_VAR(::BoolProperty, bDriverCastsShadow, 0x4000)
		ADD_VAR(::BoolProperty, bDrawHealthOnHUD, 0x2000)
		ADD_VAR(::BoolProperty, bShouldLeaveForCombat, 0x1000)
		ADD_VAR(::BoolProperty, bNeverReset, 0x800)
		ADD_VAR(::BoolProperty, bHasWeaponBar, 0x400)
		ADD_VAR(::BoolProperty, bShouldAutoCenterViewPitch, 0x200)
		ADD_VAR(::BoolProperty, bStickDeflectionThrottle, 0x100)
		ADD_VAR(::BoolProperty, bOverrideAVRiLLocks, 0x80)
		ADD_VAR(::BoolProperty, bMustBeUpright, 0x40)
		ADD_VAR(::BoolProperty, bKeyVehicle, 0x20)
		ADD_VAR(::BoolProperty, bEnteringUnlocks, 0x8)
		ADD_VAR(::BoolProperty, bValidLinkTarget, 0x4)
		bool TryToDrive(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TryToDrive");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool InCustomEntryRadius(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.InCustomEntryRadius");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateShadowSettings(bool bWantShadow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.UpdateShadowSettings");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWantShadow;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(12);
			*(float*)params = InForward;
			*(float*)(params + 4) = InStrafe;
			*(float*)(params + 8) = InUp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.FellOutOfWorld");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetChargePower()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetChargePower");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			*(int*)params = SeatIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptClass* GetRanOverDamageType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetRanOverDamageType");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)params;
			free(params);
			return returnVal;
		}
		void DisplayWeaponBar(class Canvas* Canvas, class UTHUD* HUD)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DisplayWeaponBar");
			byte* params = (byte*)malloc(8);
			*(class Canvas**)params = Canvas;
			*(class UTHUD**)(params + 4) = HUD;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawKillIcon(class Canvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DrawKillIcon");
			byte* params = (byte*)malloc(20);
			*(class Canvas**)params = Canvas;
			*(float*)(params + 4) = ScreenX;
			*(float*)(params + 8) = ScreenY;
			*(float*)(params + 12) = HUDScaleX;
			*(float*)(params + 16) = HUDScaleY;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RenderMapIcon(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, LinearColor FinalColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.RenderMapIcon");
			byte* params = (byte*)malloc(28);
			*(class UTMapInfo**)params = MP;
			*(class Canvas**)(params + 4) = Canvas;
			*(class UTPlayerController**)(params + 8) = PlayerOwner;
			*(LinearColor*)(params + 12) = FinalColor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float AdjustedStrength()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.AdjustedStrength");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		bool ContinueOnFoot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ContinueOnFoot");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsDriverSeat(class Vehicle* TestSeatPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.IsDriverSeat");
			byte* params = (byte*)malloc(8);
			*(class Vehicle**)params = TestSeatPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool RecommendCharge(class UTBot* B, class Pawn* Enemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.RecommendCharge");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(class Pawn**)(params + 4) = Enemy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool CriticalChargeAttack(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.CriticalChargeAttack");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void CreateVehicleEffect(int EffectIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.CreateVehicleEffect");
			byte* params = (byte*)malloc(4);
			*(int*)params = EffectIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = TriggerName;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 8) = PSC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TriggerVehicleEffect(ScriptName EventTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TriggerVehicleEffect");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = EventTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayVehicleSound(ScriptName SoundTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PlayVehicleSound");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = SoundTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayVehicleAnimation(ScriptName EventTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PlayVehicleAnimation");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = EventTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void VehicleEvent(ScriptName EventTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.VehicleEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = EventTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EntryAnnouncement(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.EntryAnnouncement");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Rotator ExitRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ExitRotation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)params;
			free(params);
			return returnVal;
		}
		bool FindAutoExit(class Pawn* ExitingDriver)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.FindAutoExit");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = ExitingDriver;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void RanInto(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.RanInto");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PancakeOther(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PancakeOther");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeWaterDamage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TakeWaterDamage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DriverRadiusDamage(float DamageAmount, float DamageRadius, class Controller* EventInstigator, ScriptClass* DamageType, float Momentum, Vector HitLocation, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DriverRadiusDamage");
			byte* params = (byte*)malloc(40);
			*(float*)params = DamageAmount;
			*(float*)(params + 4) = DamageRadius;
			*(class Controller**)(params + 8) = EventInstigator;
			*(ScriptClass**)(params + 12) = DamageType;
			*(float*)(params + 16) = Momentum;
			*(Vector*)(params + 20) = HitLocation;
			*(class Actor**)(params + 32) = DamageCauser;
			*(float*)(params + 36) = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetTexturesToBeResident(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetTexturesToBeResident");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool DisableVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DisableVehicle");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
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
		int GetSeatIndexFromPrefix(ScriptArray<wchar_t> Prefix)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetSeatIndexFromPrefix");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Prefix;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		void ServerSetConsoleTurning(bool bNewConsoleTurning)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ServerSetConsoleTurning");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewConsoleTurning;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessViewRotation(float DeltaTime, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ProcessViewRotation");
			byte* params = (byte*)malloc(28);
			*(float*)params = DeltaTime;
			*(Rotator*)(params + 4) = out_ViewRotation;
			*(Rotator*)(params + 16) = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ViewRotation = *(Rotator*)(params + 4);
			out_DeltaRot = *(Rotator*)(params + 16);
			free(params);
		}
		Rotator GetClampedViewRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetClampedViewRotation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)params;
			free(params);
			return returnVal;
		}
		bool ShouldClamp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ShouldClamp");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		Rotator GetViewRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetViewRotation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)params;
			free(params);
			return returnVal;
		}
		void WeaponRotationChanged(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.WeaponRotationChanged");
			byte* params = (byte*)malloc(4);
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(12);
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)(params + 4) = PlayedTime;
			*(float*)(params + 8) = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool SeatAvailable(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SeatAvailable");
			byte* params = (byte*)malloc(8);
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool AnySeatAvailable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.AnySeatAvailable");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		int GetSeatIndexForController(class Controller* ControllerToMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetSeatIndexForController");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = ControllerToMove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		class Controller* GetControllerForSeatIndex(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetControllerForSeatIndex");
			byte* params = (byte*)malloc(8);
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Controller**)(params + 4);
			free(params);
			return returnVal;
		}
		void ServerAdjacentSeat(int Direction, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ServerAdjacentSeat");
			byte* params = (byte*)malloc(8);
			*(int*)params = Direction;
			*(class Controller**)(params + 4) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerChangeSeat(int RequestedSeat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ServerChangeSeat");
			byte* params = (byte*)malloc(4);
			*(int*)params = RequestedSeat;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool HasPriority(class Controller* first, class Controller* Second)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.HasPriority");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = first;
			*(class Controller**)(params + 4) = Second;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool ChangeSeat(class Controller* ControllerToMove, int RequestedSeat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ChangeSeat");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = ControllerToMove;
			*(int*)(params + 4) = RequestedSeat;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void TornOff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TornOff");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Controller* GetCollisionDamageInstigator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetCollisionDamageInstigator");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Controller**)params;
			free(params);
			return returnVal;
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.Died");
			byte* params = (byte*)malloc(24);
			*(class Controller**)params = Killer;
			*(ScriptClass**)(params + 4) = DamageType;
			*(Vector*)(params + 8) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		void BlowupVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.BlowupVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class PlayerReplicationInfo* GetSeatPRI(int SeatNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetSeatPRI");
			byte* params = (byte*)malloc(8);
			*(int*)params = SeatNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PlayerReplicationInfo**)(params + 4);
			free(params);
			return returnVal;
		}
		bool CanEnterVehicle(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.CanEnterVehicle");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool KickOutBot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.KickOutBot");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void VehicleLocked(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.VehicleLocked");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldShowUseable(class PlayerController* PC, float Dist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ShouldShowUseable");
			byte* params = (byte*)malloc(12);
			*(class PlayerController**)params = PC;
			*(float*)(params + 4) = Dist;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PostRenderFor");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetDisplayedHealth()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetDisplayedHealth");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void RenderPassengerBeacons(class PlayerController* PC, class Canvas* Canvas, LinearColor TeamColor, Color TextColor, class UTWeapon* Weap)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.RenderPassengerBeacons");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(LinearColor*)(params + 8) = TeamColor;
			*(Color*)(params + 24) = TextColor;
			*(class UTWeapon**)(params + 28) = Weap;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostRenderPassengerBeacon(class PlayerController* PC, class Canvas* Canvas, LinearColor TeamColor, Color TextColor, class UTWeapon* Weap, class PlayerReplicationInfo* InPassengerPRI, Vector InPassengerTeamBeaconOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PostRenderPassengerBeacon");
			byte* params = (byte*)malloc(48);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(LinearColor*)(params + 8) = TeamColor;
			*(Color*)(params + 24) = TextColor;
			*(class UTWeapon**)(params + 28) = Weap;
			*(class PlayerReplicationInfo**)(params + 32) = InPassengerPRI;
			*(Vector*)(params + 36) = InPassengerTeamBeaconOffset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetTeamNum(byte T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetTeamNum");
			byte* params = (byte*)malloc(1);
			*params = T;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		bool Dodge(byte DoubleClickMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.Dodge");
			byte* params = (byte*)malloc(5);
			*params = DoubleClickMove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void IncomingMissile(class Projectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.IncomingMissile");
			byte* params = (byte*)malloc(4);
			*(class Projectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShootMissile(class Projectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ShootMissile");
			byte* params = (byte*)malloc(4);
			*(class Projectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendLockOnMessage(int Switch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SendLockOnMessage");
			byte* params = (byte*)malloc(4);
			*(int*)params = Switch;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LockOnWarning(class UDKProjectile* IncomingMissile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.LockOnWarning");
			byte* params = (byte*)malloc(4);
			*(class UDKProjectile**)params = IncomingMissile;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool TooCloseToAttack(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TooCloseToAttack");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CheckTurretPitchLimit(int NeededPitch, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.CheckTurretPitchLimit");
			byte* params = (byte*)malloc(12);
			*(int*)params = NeededPitch;
			*(int*)(params + 4) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void PlayHorn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PlayHorn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DriverLeave(bool bForceLeave)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DriverLeave");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bForceLeave;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void UpdateControllerOnPossess(bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.UpdateControllerOnPossess");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int NumPassengers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.NumPassengers");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		class UTVehicle* GetMoveTargetFor(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetMoveTargetFor");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTVehicle**)(params + 4);
			free(params);
			return returnVal;
		}
		void HandleEnteringFlag(class UTPlayerReplicationInfo* EnteringPRI, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.HandleEnteringFlag");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerReplicationInfo**)params = EnteringPRI;
			*(int*)(params + 4) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool DriverEnter(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DriverEnter");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void HoldGameObject(class UDKCarriedObject* GameObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.HoldGameObject");
			byte* params = (byte*)malloc(4);
			*(class UDKCarriedObject**)params = GameObj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AttachFlag(class UTCarriedObject* FlagActor, class Pawn* NewDriver)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.AttachFlag");
			byte* params = (byte*)malloc(8);
			*(class UTCarriedObject**)params = FlagActor;
			*(class Pawn**)(params + 4) = NewDriver;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DriverLeft()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DriverLeft");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetFirstAvailableSeat(bool bSeatMustAllowFlag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetFirstAvailableSeat");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bSeatMustAllowFlag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool PassengerEnter(class Pawn* P, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PassengerEnter");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = P;
			*(int*)(params + 4) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void PassengerLeave(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PassengerLeave");
			byte* params = (byte*)malloc(4);
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CheckReset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.CheckReset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool Occupied()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.Occupied");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool OpenPositionFor(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.OpenPositionFor");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		float BotDesireability(class UTSquadAI* S, int TeamIndex, class Actor* Objective)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.BotDesireability");
			byte* params = (byte*)malloc(16);
			*(class UTSquadAI**)params = S;
			*(int*)(params + 4) = TeamIndex;
			*(class Actor**)(params + 8) = Objective;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		float ReservationCostMultiplier(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ReservationCostMultiplier");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SpokenFor(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SpokenFor");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.StopsProjectile");
			byte* params = (byte*)malloc(8);
			*(class Projectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetReservation(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetReservation");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool TeamLink(int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TeamLink");
			byte* params = (byte*)malloc(8);
			*(int*)params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool AllowLinkThroughOwnedActor(class Actor* OwnedActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.AllowLinkThroughOwnedActor");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = OwnedActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool HealDamage(int Amount, class Controller* Healer, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.HealDamage");
			byte* params = (byte*)malloc(16);
			*(int*)params = Amount;
			*(class Controller**)(params + 4) = Healer;
			*(ScriptClass**)(params + 8) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
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
		void PlayHit(float Damage, class Controller* InstigatedBy, Vector HitLocation, ScriptClass* DamageType, Vector Momentum, TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PlayHit");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.PlayTakeHitEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyTakeHit(class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.NotifyTakeHit");
			byte* params = (byte*)malloc(36);
			*(class Controller**)params = InstigatedBy;
			*(Vector*)(params + 4) = HitLocation;
			*(int*)(params + 16) = Damage;
			*(ScriptClass**)(params + 20) = DamageType;
			*(Vector*)(params + 24) = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.TakeDamage");
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
		class Actor* GetHomingTarget(class UTProjectile* Seeker, class Controller* InstigatedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetHomingTarget");
			byte* params = (byte*)malloc(12);
			*(class UTProjectile**)params = Seeker;
			*(class Controller**)(params + 4) = InstigatedBy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 8);
			free(params);
			return returnVal;
		}
		bool ImportantVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ImportantVehicle");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			*(bool*)(params + 4) = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFiringMode(class Weapon* Weap, byte FiringModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetFiringMode");
			byte* params = (byte*)malloc(5);
			*(class Weapon**)params = Weap;
			*(params + 4) = FiringModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearFlashCount(class Weapon* Who)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ClearFlashCount");
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = Who;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void IncrementFlashCount(class Weapon* Who, byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.IncrementFlashCount");
			byte* params = (byte*)malloc(5);
			*(class Weapon**)params = Who;
			*(params + 4) = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFlashLocation(class Weapon* Who, byte FireModeNum, Vector NewLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetFlashLocation");
			byte* params = (byte*)malloc(17);
			*(class Weapon**)params = Who;
			*(params + 4) = FireModeNum;
			*(Vector*)(params + 8) = NewLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearFlashLocation(class Weapon* Who)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ClearFlashLocation");
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = Who;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetBarrelLocationAndRotation(int SeatIndex, Vector& SocketLocation, Rotator& SocketRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetBarrelLocationAndRotation");
			byte* params = (byte*)malloc(28);
			*(int*)params = SeatIndex;
			*(Vector*)(params + 4) = SocketLocation;
			*(Rotator*)(params + 16) = SocketRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			SocketLocation = *(Vector*)(params + 4);
			SocketRotation = *(Rotator*)(params + 16);
			free(params);
		}
		Vector GetEffectLocation(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetEffectLocation");
			byte* params = (byte*)malloc(16);
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 4);
			free(params);
			return returnVal;
		}
		Vector GetPhysicalFireStartLoc(class UTWeapon* ForWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetPhysicalFireStartLoc");
			byte* params = (byte*)malloc(16);
			*(class UTWeapon**)params = ForWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 4);
			free(params);
			return returnVal;
		}
		Rotator GetWeaponAim(class UTVehicleWeapon* VWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetWeaponAim");
			byte* params = (byte*)malloc(16);
			*(class UTVehicleWeapon**)params = VWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 4);
			free(params);
			return returnVal;
		}
		bool OverrideBeginFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.OverrideBeginFire");
			byte* params = (byte*)malloc(5);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool OverrideEndFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.OverrideEndFire");
			byte* params = (byte*)malloc(5);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void GetWeaponViewAxes(class UTWeapon* WhichWeapon, Vector& XAxis, Vector& YAxis, Vector& ZAxis)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetWeaponViewAxes");
			byte* params = (byte*)malloc(40);
			*(class UTWeapon**)params = WhichWeapon;
			*(Vector*)(params + 4) = XAxis;
			*(Vector*)(params + 16) = YAxis;
			*(Vector*)(params + 28) = ZAxis;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			XAxis = *(Vector*)(params + 4);
			YAxis = *(Vector*)(params + 16);
			ZAxis = *(Vector*)(params + 28);
			free(params);
		}
		void CauseMuzzleFlashLight(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.CauseMuzzleFlashLight");
			byte* params = (byte*)malloc(4);
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WeaponFired(class Weapon* InWeapon, bool bViaReplication, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.WeaponFired");
			byte* params = (byte*)malloc(20);
			*(class Weapon**)params = InWeapon;
			*(bool*)(params + 4) = bViaReplication;
			*(Vector*)(params + 8) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void VehicleWeaponFired(bool bViaReplication, Vector HitLocation, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.VehicleWeaponFired");
			byte* params = (byte*)malloc(20);
			*(bool*)params = bViaReplication;
			*(Vector*)(params + 4) = HitLocation;
			*(int*)(params + 16) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WeaponStoppedFiring(class Weapon* InWeapon, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.WeaponStoppedFiring");
			byte* params = (byte*)malloc(8);
			*(class Weapon**)params = InWeapon;
			*(bool*)(params + 4) = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void VehicleWeaponStoppedFiring(bool bViaReplication, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.VehicleWeaponStoppedFiring");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bViaReplication;
			*(int*)(params + 4) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void VehicleWeaponFireEffects(Vector HitLocation, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.VehicleWeaponFireEffects");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = HitLocation;
			*(int*)(params + 12) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Actor* FindWeaponHitNormal(Vector& HitLocation, Vector& HitNormal, Vector End, Vector Start, TraceHitInfo& HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.FindWeaponHitNormal");
			byte* params = (byte*)malloc(80);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			*(Vector*)(params + 24) = End;
			*(Vector*)(params + 36) = Start;
			*(TraceHitInfo*)(params + 48) = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			HitLocation = *(Vector*)params;
			HitNormal = *(Vector*)(params + 12);
			HitInfo = *(TraceHitInfo*)(params + 48);
			auto returnVal = *(class Actor**)(params + 76);
			free(params);
			return returnVal;
		}
		void VehicleWeaponImpactEffects(Vector HitLocation, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.VehicleWeaponImpactEffects");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = HitLocation;
			*(int*)(params + 12) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpawnImpactEmitter(Vector HitLocation, Vector HitNormal, MaterialImpactEffect& ImpactEffect, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SpawnImpactEmitter");
			byte* params = (byte*)malloc(76);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			*(MaterialImpactEffect*)(params + 24) = ImpactEffect;
			*(int*)(params + 72) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ImpactEffect = *(MaterialImpactEffect*)(params + 24);
			free(params);
		}
		void VehicleAdjustFlashCount(int SeatIndex, byte FireModeNum, bool bClear)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.VehicleAdjustFlashCount");
			byte* params = (byte*)malloc(9);
			*(int*)params = SeatIndex;
			*(params + 4) = FireModeNum;
			*(bool*)(params + 8) = bClear;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void VehicleAdjustFlashLocation(int SeatIndex, byte FireModeNum, Vector NewLocation, bool bClear)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.VehicleAdjustFlashLocation");
			byte* params = (byte*)malloc(21);
			*(int*)params = SeatIndex;
			*(params + 4) = FireModeNum;
			*(Vector*)(params + 8) = NewLocation;
			*(bool*)(params + 20) = bClear;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FindGoodEndView(class PlayerController* PC, Rotator& GoodRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.FindGoodEndView");
			byte* params = (byte*)malloc(16);
			*(class PlayerController**)params = PC;
			*(Rotator*)(params + 4) = GoodRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			GoodRotation = *(Rotator*)(params + 4);
			free(params);
		}
		bool CalcCamera(float DeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.CalcCamera");
			byte* params = (byte*)malloc(36);
			*(float*)params = DeltaTime;
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
		Vector GetCameraFocus(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetCameraFocus");
			byte* params = (byte*)malloc(16);
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 4);
			free(params);
			return returnVal;
		}
		Vector GetCameraStart(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetCameraStart");
			byte* params = (byte*)malloc(16);
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 4);
			free(params);
			return returnVal;
		}
		float LimitCameraZ(float CurrentCamZ, float OriginalCamZ, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.LimitCameraZ");
			byte* params = (byte*)malloc(16);
			*(float*)params = CurrentCamZ;
			*(float*)(params + 4) = OriginalCamZ;
			*(int*)(params + 8) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		void VehicleCalcCamera(float DeltaTime, int SeatIndex, Vector& out_CamLoc, Rotator& out_CamRot, Vector& CamStart, bool bPivotOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.VehicleCalcCamera");
			byte* params = (byte*)malloc(48);
			*(float*)params = DeltaTime;
			*(int*)(params + 4) = SeatIndex;
			*(Vector*)(params + 8) = out_CamLoc;
			*(Rotator*)(params + 20) = out_CamRot;
			*(Vector*)(params + 32) = CamStart;
			*(bool*)(params + 44) = bPivotOnly;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_CamLoc = *(Vector*)(params + 8);
			out_CamRot = *(Rotator*)(params + 20);
			CamStart = *(Vector*)(params + 32);
			free(params);
		}
		void AdjustCameraScale(bool bMoveCameraIn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.AdjustCameraScale");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bMoveCameraIn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		bool ShouldSpawnExplosionLight(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ShouldSpawnExplosionLight");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
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
void* OtherComponent, CollisionImpactData& Collision, int ContactIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.RigidBodyCollision");
			byte* params = (byte*)malloc(48);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = HitComponent;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = OtherComponent;
			*(CollisionImpactData*)(params + 8) = Collision;
			*(int*)(params + 44) = ContactIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Collision = *(CollisionImpactData*)(params + 8);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SitDriver(class UTPawn* UTP, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SitDriver");
			byte* params = (byte*)malloc(8);
			*(class UTPawn**)params = UTP;
			*(int*)(params + 4) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnDriverPhysicsAssetChanged(class UTPawn* UTP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.OnDriverPhysicsAssetChanged");
			byte* params = (byte*)malloc(4);
			*(class UTPawn**)params = UTP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetHumanReadableName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetHumanReadableName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void OnPropertyChange(ScriptName PropName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.OnPropertyChange");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = PropName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetHealth(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetHealth");
			byte* params = (byte*)malloc(8);
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		float GetCollisionDamageModifier(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ContactInfos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetCollisionDamageModifier");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = ContactInfos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ContactInfos = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ApplyRandomMorphDamage(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ApplyRandomMorphDamage");
			byte* params = (byte*)malloc(4);
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class UTGib* SpawnGibVehicle(Vector SpawnLocation, Rotator SpawnRotation, class StaticMesh* TheMesh, Vector HitLocation, bool bSpinGib, Vector ImpulseDirection, class ParticleSystem* PS_OnBreak, class ParticleSystem* PS_Trail)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SpawnGibVehicle");
			byte* params = (byte*)malloc(68);
			*(Vector*)params = SpawnLocation;
			*(Rotator*)(params + 12) = SpawnRotation;
			*(class StaticMesh**)(params + 24) = TheMesh;
			*(Vector*)(params + 28) = HitLocation;
			*(bool*)(params + 40) = bSpinGib;
			*(Vector*)(params + 44) = ImpulseDirection;
			*(class ParticleSystem**)(params + 56) = PS_OnBreak;
			*(class ParticleSystem**)(params + 60) = PS_Trail;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTGib**)(params + 64);
			free(params);
			return returnVal;
		}
		void GetSVehicleDebug(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& DebugInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetSVehicleDebug");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = DebugInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			DebugInfo = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void OnExitVehicle(class UTSeqAct_ExitVehicle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.OnExitVehicle");
			byte* params = (byte*)malloc(4);
			*(class UTSeqAct_ExitVehicle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetShieldActive(int SeatIndex, bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetShieldActive");
			byte* params = (byte*)malloc(8);
			*(int*)params = SeatIndex;
			*(bool*)(params + 4) = bActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSeatStoragePawn(int SeatIndex, class Pawn* PawnToSit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetSeatStoragePawn");
			byte* params = (byte*)malloc(8);
			*(int*)params = SeatIndex;
			*(class Pawn**)(params + 4) = PawnToSit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMovementEffect(int SeatIndex, bool bSetActive, class UTPawn* UTP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.SetMovementEffect");
			byte* params = (byte*)malloc(12);
			*(int*)params = SeatIndex;
			*(bool*)(params + 4) = bSetActive;
			*(class UTPawn**)(params + 8) = UTP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DetachDriver(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DetachDriver");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanAttack(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.CanAttack");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptName GetVehicleKillStatName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetVehicleKillStatName");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)params;
			free(params);
			return returnVal;
		}
		void DisplayHud(class UTHUD* HUD, class Canvas* Canvas, Vector2D HudPOS, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DisplayHud");
			byte* params = (byte*)malloc(20);
			*(class UTHUD**)params = HUD;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector2D*)(params + 8) = HudPOS;
			*(int*)(params + 16) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawBarGraph(float X, float Y, float Width, float MaxWidth, float Height, class Canvas* DrawCanvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DrawBarGraph");
			byte* params = (byte*)malloc(24);
			*(float*)params = X;
			*(float*)(params + 4) = Y;
			*(float*)(params + 8) = Width;
			*(float*)(params + 12) = MaxWidth;
			*(float*)(params + 16) = Height;
			*(class Canvas**)(params + 20) = DrawCanvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayExtraHud(class UTHUD* HUD, class Canvas* Canvas, Vector2D pos, float Width, float Height, int SIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DisplayExtraHud");
			byte* params = (byte*)malloc(28);
			*(class UTHUD**)params = HUD;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector2D*)(params + 8) = pos;
			*(float*)(params + 16) = Width;
			*(float*)(params + 20) = Height;
			*(int*)(params + 24) = SIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplaySeats(class UTHUD* HUD, class Canvas* Canvas, float PosX, float PosY, float Width, float Height, int SIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.DisplaySeats");
			byte* params = (byte*)malloc(28);
			*(class UTHUD**)params = HUD;
			*(class Canvas**)(params + 4) = Canvas;
			*(float*)(params + 8) = PosX;
			*(float*)(params + 12) = PosY;
			*(float*)(params + 16) = Width;
			*(float*)(params + 20) = Height;
			*(int*)(params + 24) = SIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		LinearColor GetSeatColor(int SeatIndex, bool bIsPlayersSeat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.GetSeatColor");
			byte* params = (byte*)malloc(24);
			*(int*)params = SeatIndex;
			*(bool*)(params + 4) = bIsPlayersSeat;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(LinearColor*)(params + 8);
			free(params);
			return returnVal;
		}
		void ApplyWeaponEffects(int OverlayFlags, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ApplyWeaponEffects");
			byte* params = (byte*)malloc(8);
			*(int*)params = OverlayFlags;
			*(int*)(params + 4) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldLeaveForCombat(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicle.ShouldLeaveForCombat");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
