#pragma once
#include "UTGame.UTVehicle.h"
#include "TribesGame.TrVehicleStation.h"
#include "TribesGame.TrStatsInterface.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "UDKBase.UDKCarriedObject.h"
#include "TribesGame.TrObject.h"
#include "Engine.MaterialInstanceConstant.h"
#include "UDKBase.UDKPawn.h"
#include "TribesGame.TrPawn.h"
#include "Engine.Pawn.h"
#include "Engine.Controller.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.Projectile.h"
#include "Engine.PlayerController.h"
#include "TribesGame.TrProj_Tracer.h"
#include "Engine.Canvas.h"
#include "UTGame.UTPawn.h"
#include "TribesGame.TrHUD.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "Engine.ParticleSystem.h"
#include "Engine.PlayerReplicationInfo.h"
#include "UTGame.UTVehicleWeapon.h"
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
	class TrVehicle : public UTVehicle
	{
	public:
		ADD_STRUCT(float, m_fCurrentPowerPool, 2804)
		ADD_STRUCT(float, r_fMaxPowerPool, 2812)
		ADD_STRUCT(ScriptString*, m_sName, 2932)
		ADD_STRUCT(int, m_nIconIndex, 2944)
		ADD_BOOL(m_bClientPhysDirty, 2776, 0x100)
		ADD_STRUCT(Actor::RigidBodyState, m_ClientRBState, 3136)
		ADD_BOOL(m_bServerCorrectionForce, 2776, 0x200)
		ADD_BOOL(m_bImprovedLagSupport, 2776, 0x4)
		ADD_STRUCT(TrObject::EVehicleTypes, m_VehicleType, 2780)
		ADD_BOOL(m_bUsesArmoredMultiplier, 2776, 0x80)
		ADD_STRUCT(ScriptString*, m_sWeapon1Name, 3092)
		ADD_STRUCT(ScriptString*, m_sWeapon2Name, 3104)
		ADD_STRUCT(ScriptArray<UDKPawn::MaterialImpactEffect>, m_DustEffects, 2948)
		ADD_STRUCT(float, m_fMaxPawnLeaveSpeed, 3208)
		ADD_STRUCT(int, m_nDetectedByEnemyScannerCount, 3204)
		ADD_STRUCT(int, m_nServerTickCount, 3200)
		ADD_STRUCT(float, m_fClientPhysDeltaTime, 3120)
		ADD_OBJECT(TrStatsInterface, Stats, 3116)
		ADD_STRUCT(Object::Vector, m_vDeathCamStartOffset, 3080)
		ADD_STRUCT(float, m_fVehicleHealthBarHeight, 3076)
		ADD_STRUCT(float, m_fVehicleHealthBarWidth, 3072)
		ADD_STRUCT(float, m_fVehicleHealthBarPlacementY, 3068)
		ADD_STRUCT(float, m_fVehicleHealthBarPlacementX, 3064)
		ADD_OBJECT(MaterialInstanceConstant, m_MarkerMIC, 3060)
		ADD_OBJECT(MaterialInstanceConstant, m_Passenger4HealthBarMIC, 3056)
		ADD_OBJECT(MaterialInstanceConstant, m_Passenger3HealthBarMIC, 3052)
		ADD_OBJECT(MaterialInstanceConstant, m_Passenger2HealthBarMIC, 3048)
		ADD_OBJECT(MaterialInstanceConstant, m_Passenger1HealthBarMIC, 3044)
		ADD_OBJECT(MaterialInstanceConstant, m_DriverHealthBarMIC, 3040)
		ADD_OBJECT(MaterialInstanceConstant, m_HealthBarMIC, 3036)
		ADD_STRUCT(float, m_fRemainingSeekingTargetHUDZoomTime, 3032)
		ADD_STRUCT(Object::Rotator, m_rPotentialSeekingTargetHUDRotation, 3020)
		ADD_STRUCT(float, m_fRemainingPotentialSeekingTargetHUDZoomTime, 3016)
		ADD_STRUCT(float, m_fContrailSpeed, 3012)
		ADD_STRUCT(UDKPawn::MaterialImpactEffect, m_DefaultDustEffect, 2960)
		ADD_STRUCT(float, ShowHeaderUntil, 2928)
		ADD_STRUCT(float, m_fBoostFadeOutTime, 2920)
		ADD_STRUCT(float, m_fBoostFadeInTime, 2916)
		ADD_STRUCT(float, m_fDivingMaxSpeedMultiplier, 2912)
		ADD_STRUCT(int, r_nBaseMaxSpeed, 2908)
		ADD_STRUCT(float, m_fWallDamageTickTime, 2904)
		ADD_STRUCT(float, m_fLastWallDamageTime, 2900)
		ADD_STRUCT(float, m_fWallMaxDamage, 2896)
		ADD_STRUCT(float, m_fWallMinDamage, 2892)
		ADD_STRUCT(float, m_fWallMinDamageSpeed, 2888)
		ADD_STRUCT(float, m_fWallMaxDamageSpeed, 2884)
		ADD_OBJECT(ScriptClass, WallCollisionDamageType, 2880)
		ADD_STRUCT(float, m_fVehicleDamageTickTime, 2876)
		ADD_STRUCT(float, m_fLastVehicleDamageTime, 2872)
		ADD_STRUCT(float, m_fVehicleMaxDamage, 2868)
		ADD_STRUCT(float, m_fVehicleMinDamage, 2864)
		ADD_STRUCT(float, m_fVehicleMinDamageSpeed, 2860)
		ADD_STRUCT(float, m_fVehicleMaxDamageSpeed, 2856)
		ADD_OBJECT(ScriptClass, VehicleCollisionDamageType, 2852)
		ADD_STRUCT(float, m_fPawnDamageTickTime, 2848)
		ADD_STRUCT(float, m_fPawnMaxDamage, 2844)
		ADD_STRUCT(float, m_fPawnMinDamage, 2840)
		ADD_STRUCT(float, m_fPawnMaxDamageSpeed, 2836)
		ADD_STRUCT(float, m_fPawnPushSpeed, 2832)
		ADD_STRUCT(float, m_fFlagPushSpeed, 2828)
		ADD_STRUCT(float, m_CrashDamageSeverity, 2824)
		ADD_STRUCT(float, m_fPowerPoolTickRate, 2820)
		ADD_STRUCT(float, m_fPowerPoolRechargeRate, 2816)
		ADD_STRUCT(float, r_fCurrentPowerPool, 2808)
		ADD_STRUCT(float, m_fBoostReactivatePct, 2800)
		ADD_STRUCT(float, m_fBoostEnergyPerSec, 2796)
		ADD_STRUCT(float, m_fBoostMultiplier, 2792)
		ADD_STRUCT(float, m_fTimeToReset, 2788)
		ADD_OBJECT(TrVehicleStation, m_OwnerStation, 2784)
		ADD_STRUCT(TrObject::EMissileLock, m_MissileLockStatus, 2782)
		ADD_STRUCT(TrObject::EMissileLock, r_MissileLock, 2781)
		ADD_BOOL(r_bDetectedByEnemyScanner, 2776, 0x400)
		ADD_BOOL(r_LevelFlightEnabled, 2776, 0x40)
		ADD_BOOL(m_bLowPowerPool, 2776, 0x20)
		ADD_BOOL(r_BoostersEnabled, 2776, 0x10)
		ADD_BOOL(r_bIsInvulnerable, 2776, 0x8)
		ADD_BOOL(m_bBoostRequiresThrust, 2776, 0x2)
		ADD_BOOL(m_bPostSpawnLocked, 2776, 0x1)
		ADD_OBJECT(TrPawn, m_PawnToTeleport, 2772)
		ADD_OBJECT(Pawn, Passenger, 2756)
		bool IsEmpty()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.IsEmpty");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool RidingPawnLeave(int SeatIndex, bool bForceLeave)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.RidingPawnLeave");
			byte params[12] = { NULL };
			*(int*)&params[0] = SeatIndex;
			*(bool*)&params[4] = bForceLeave;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		int GetSeatIndexForController(class Controller* ControllerToMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetSeatIndexForController");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = ControllerToMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool CalcOtherWatchingCam(float fDeltaTime, Object::Vector& out_CamLoc, Object::Rotator& out_CamRot, float& out_FOV, class TrPlayerController* WatcherController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.CalcOtherWatchingCam");
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
		bool SetScannerDetect(bool detected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SetScannerDetect");
			byte params[8] = { NULL };
			*(bool*)&params[0] = detected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.StopsProjectile");
			byte params[8] = { NULL };
			*(class Projectile**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void NativePostRenderFor(class PlayerController* PC, class Canvas* Canvas, Object::Vector CameraPosition, Object::Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.NativePostRenderFor");
			byte params[32] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector*)&params[8] = CameraPosition;
			*(Object::Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ConsumePowerPool(float fAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ConsumePowerPool");
			byte params[4] = { NULL };
			*(float*)&params[0] = fAmount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetPowerPoolPercent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetPowerPoolPercent");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void RegainPowerPool(float fDeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.RegainPowerPool");
			byte params[4] = { NULL };
			*(float*)&params[0] = fDeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SyncClientCurrentPowerPool()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SyncClientCurrentPowerPool");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PostInitAnimTree");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDetectedByEnemyScanner(bool detected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SetDetectedByEnemyScanner");
			byte params[4] = { NULL };
			*(bool*)&params[0] = detected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetDetectedByEnemyScanner()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetDetectedByEnemyScanner");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void PancakeOther(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PancakeOther");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Controller* GetCollisionDamageInstigator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetCollisionDamageInstigator");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Controller**)&params[0];
		}
		float GetDamageAmountForCollision(float Speed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetDamageAmountForCollision");
			byte params[8] = { NULL };
			*(float*)&params[0] = Speed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void RigidBodyCollision(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* HitComponent, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComponent, Actor::CollisionImpactData& Collision, int ContactIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.RigidBodyCollision");
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
		void RanInto(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.RanInto");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SitDriver(class UTPawn* UTP, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SitDriver");
			byte params[8] = { NULL };
			*(class UTPawn**)&params[0] = UTP;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachDriver(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.DetachDriver");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPawnToTeleport(class TrPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SetPawnToTeleport");
			byte params[4] = { NULL };
			*(class TrPawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPostSpawnLocked(bool bLocked)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SetPostSpawnLocked");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bLocked;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendLockOnMessage(int Switch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SendLockOnMessage");
			byte params[4] = { NULL };
			*(int*)&params[0] = Switch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.Died");
			byte params[24] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(ScriptClass**)&params[4] = DamageType;
			*(Object::Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		void KillControllerForTeamChange(class Controller* ControllerToKill)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.KillControllerForTeamChange");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = ControllerToKill;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeleportDriverToSeat()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.TeleportDriverToSeat");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanArmorDriveVehicle(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.CanArmorDriveVehicle");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CanArmorEnterVehicle(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.CanArmorEnterVehicle");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int GetFirstAvailableSeat(bool bSeatMustAllowFlag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetFirstAvailableSeat");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bSeatMustAllowFlag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool TryToDrive(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.TryToDrive");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DriverLeft()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.DriverLeft");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PassengerLeave(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PassengerLeave");
			byte params[4] = { NULL };
			*(int*)&params[0] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckReset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.CheckReset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetResetTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ResetResetTime");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HandleMomentum(Object::Vector Momentum, Object::Vector HitLocation, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.HandleMomentum");
			byte params[56] = { NULL };
			*(Object::Vector*)&params[0] = Momentum;
			*(Object::Vector*)&params[12] = HitLocation;
			*(ScriptClass**)&params[24] = DamageType;
			*(Actor::TraceHitInfo*)&params[28] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ToggleBoosters(bool bEnabled, bool ToggleTimer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ToggleBoosters");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bEnabled;
			*(bool*)&params[4] = ToggleTimer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ConsumeBoostPowerPool()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ConsumeBoostPowerPool");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanActivateBoosters()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.CanActivateBoosters");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool ShouldRechargePowerPool()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ShouldRechargePowerPool");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ServerToggleLevelFlight(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ServerToggleLevelFlight");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BoostSoundFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.BoostSoundFinished");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = AC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayBoosterEffects(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PlayBoosterEffects");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayMissileLockSounds()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PlayMissileLockSounds");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Occupied()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.Occupied");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Object::Vector CameraPosition, Object::Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PostRenderFor");
			byte params[32] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector*)&params[8] = CameraPosition;
			*(Object::Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RenderDriverPassengerMarker(class Canvas* Canvas, bool friendly, class TrHUD* HUD, class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.RenderDriverPassengerMarker");
			byte params[20] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			*(bool*)&params[4] = friendly;
			*(class TrHUD**)&params[8] = HUD;
			*(class TrPlayerController**)&params[12] = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void SetSeatStoragePawn(int SeatIndex, class Pawn* PawnToSit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SetSeatStoragePawn");
			byte params[8] = { NULL };
			*(int*)&params[0] = SeatIndex;
			*(class Pawn**)&params[4] = PawnToSit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetSVehicleDebug(ScriptArray<ScriptString*>& DebugInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetSVehicleDebug");
			byte params[12] = { NULL };
			*(ScriptArray<ScriptString*>*)&params[0] = DebugInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DebugInfo = *(ScriptArray<ScriptString*>*)&params[0];
		}
		void InitializeSeats()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.InitializeSeats");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool PassengerEnter(class Pawn* P, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PassengerEnter");
			byte params[12] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AttachDriver(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.AttachDriver");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AttachRidingPawn(class TrPawn* PawnToSit, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.AttachRidingPawn");
			byte params[8] = { NULL };
			*(class TrPawn**)&params[0] = PawnToSit;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachRidingPawn(class TrPawn* PawnLeft)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.DetachRidingPawn");
			byte params[4] = { NULL };
			*(class TrPawn**)&params[0] = PawnLeft;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateSeatAnimations(class TrPawn* PawnToSit, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.UpdateSeatAnimations");
			byte params[8] = { NULL };
			*(class TrPawn**)&params[0] = PawnToSit;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HoldGameObject(class UDKCarriedObject* GameObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.HoldGameObject");
			byte params[4] = { NULL };
			*(class UDKCarriedObject**)&params[0] = GameObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HandleEnteringFlag(class UTPlayerReplicationInfo* EnteringPRI, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.HandleEnteringFlag");
			byte params[8] = { NULL };
			*(class UTPlayerReplicationInfo**)&params[0] = EnteringPRI;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DriverEnter(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.DriverEnter");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class PlayerReplicationInfo* GetSeatPRI(int SeatNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetSeatPRI");
			byte params[8] = { NULL };
			*(int*)&params[0] = SeatNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerReplicationInfo**)&params[4];
		}
		void ServerChangeSeat(int RequestedSeat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ServerChangeSeat");
			byte params[4] = { NULL };
			*(int*)&params[0] = RequestedSeat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchSeat(int RequestedSeat, class Controller* ControllerRequestingSeatChange)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SwitchSeat");
			byte params[8] = { NULL };
			*(int*)&params[0] = RequestedSeat;
			*(class Controller**)&params[4] = ControllerRequestingSeatChange;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ChangeSeat(class Controller* ControllerToMove, int RequestedSeat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ChangeSeat");
			byte params[12] = { NULL };
			*(class Controller**)&params[0] = ControllerToMove;
			*(int*)&params[4] = RequestedSeat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void SwitchWeapon(byte NewGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SwitchWeapon");
			byte params[1] = { NULL };
			params[0] = NewGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetSeatIndexForStoragePawn(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetSeatIndexForStoragePawn");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool PlaceExitingDriver(class Pawn* ExitingDriver)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PlaceExitingDriver");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = ExitingDriver;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool TryExitPos(class Pawn* ExitingDriver, Object::Vector ExitPos, bool bMustFindGround)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.TryExitPos");
			byte params[24] = { NULL };
			*(class Pawn**)&params[0] = ExitingDriver;
			*(Object::Vector*)&params[4] = ExitPos;
			*(bool*)&params[16] = bMustFindGround;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool SeatAvailable(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SeatAvailable");
			byte params[8] = { NULL };
			*(int*)&params[0] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AnySeatAvailable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.AnySeatAvailable");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		Object::Rotator GetWeaponAim(class UTVehicleWeapon* VWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetWeaponAim");
			byte params[16] = { NULL };
			*(class UTVehicleWeapon**)&params[0] = VWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[4];
		}
		void WeaponRotationChanged(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.WeaponRotationChanged");
			byte params[4] = { NULL };
			*(int*)&params[0] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HealDamage(int Amount, class Controller* Healer, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.HealDamage");
			byte params[16] = { NULL };
			*(int*)&params[0] = Amount;
			*(class Controller**)&params[4] = Healer;
			*(ScriptClass**)&params[8] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void DoRepairs(int HealAmount, class Controller* EventInstigator, Object::Vector HitLocation, Object::Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.DoRepairs");
			byte params[68] = { NULL };
			*(int*)&params[0] = HealAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DriverRadiusDamage(float DamageAmount, float DamageRadius, class Controller* EventInstigator, ScriptClass* DamageType, float Momentum, Object::Vector HitLocation, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.DriverRadiusDamage");
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
		void Suicide()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.Suicide");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Object::Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.TakeRadiusDamage");
			byte params[44] = { NULL };
			*(class Controller**)&params[0] = InstigatedBy;
			*(float*)&params[4] = BaseDamage;
			*(float*)&params[8] = DamageRadius;
			*(ScriptClass**)&params[12] = DamageType;
			*(float*)&params[16] = Momentum;
			*(Object::Vector*)&params[20] = HurtOrigin;
			*(bool*)&params[32] = bFullDamage;
			*(class Actor**)&params[36] = DamageCauser;
			*(float*)&params[40] = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Object::Vector HitLocation, Object::Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.TakeDamage");
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
		void CheckDamageSmoke()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.CheckDamageSmoke");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BlowupVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.BlowupVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void VehicleWeaponFireEffects(Object::Vector HitLocation, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.VehicleWeaponFireEffects");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(int*)&params[12] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleWeaponStoppedFiring(bool bViaReplication, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.VehicleWeaponStoppedFiring");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bViaReplication;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ThirdPersonFireEffects(Object::Vector HitLocation, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ThirdPersonFireEffects");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(int*)&params[12] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnTracerBeam(Object::Vector Start, Object::Vector End, class ParticleSystem* TracerBeamTemplate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SpawnTracerBeam");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = Start;
			*(Object::Vector*)&params[12] = End;
			*(class ParticleSystem**)&params[24] = TracerBeamTemplate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class TrProj_Tracer* SpawnTracerEffect(TrObject::EWeaponTracerType TracerType, Object::Vector EffectLocation, Object::Vector HitLocation, float HitDistance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SpawnTracerEffect");
			byte params[33] = { NULL };
			*(TrObject::EWeaponTracerType*)&params[0] = TracerType;
			*(Object::Vector*)&params[4] = EffectLocation;
			*(Object::Vector*)&params[16] = HitLocation;
			*(float*)&params[28] = HitDistance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrProj_Tracer**)&params[32];
		}
		void ProcessViewRotation(float DeltaTime, Object::Rotator& out_ViewRotation, Object::Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ProcessViewRotation");
			byte params[28] = { NULL };
			*(float*)&params[0] = DeltaTime;
			*(Object::Rotator*)&params[4] = out_ViewRotation;
			*(Object::Rotator*)&params[16] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Object::Rotator*)&params[4];
			out_DeltaRot = *(Object::Rotator*)&params[16];
		}
		void ProcessViewRotationBasedOnSeat(int SeatIndex, float DeltaTime, Object::Rotator& out_ViewRotation, Object::Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ProcessViewRotationBasedOnSeat");
			byte params[32] = { NULL };
			*(int*)&params[0] = SeatIndex;
			*(float*)&params[4] = DeltaTime;
			*(Object::Rotator*)&params[8] = out_ViewRotation;
			*(Object::Rotator*)&params[20] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Object::Rotator*)&params[8];
			out_DeltaRot = *(Object::Rotator*)&params[20];
		}
		bool ShouldShowUseable(class PlayerController* PC, float Dist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ShouldShowUseable");
			byte params[12] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(float*)&params[4] = Dist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void SetDriving(bool bNewDriving)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SetDriving");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewDriving;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayVehicleEvent(ScriptName EventTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PlayVehicleEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = EventTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleEvent(ScriptName EventTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.VehicleEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = EventTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayClientVehicleSound(ScriptName SoundTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PlayClientVehicleSound");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = SoundTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MigrateVehicleSounds(class Pawn* P, bool bIsRiding)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.MigrateVehicleSounds");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(bool*)&params[4] = bIsRiding;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopVehicleSounds()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.StopVehicleSounds");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Object::Vector GetCameraFocus(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetCameraFocus");
			byte params[16] = { NULL };
			*(int*)&params[0] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[4];
		}
		ScriptString* GetSpectatorName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetSpectatorName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void PlayHorn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PlayHorn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GoInvulnerable(float InvulnerableTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GoInvulnerable");
			byte params[4] = { NULL };
			*(float*)&params[0] = InvulnerableTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearInvulnerability()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ClearInvulnerability");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
