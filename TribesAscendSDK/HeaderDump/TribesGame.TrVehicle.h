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
		ADD_STRUCT(Vector, m_vDeathCamStartOffset, 3080)
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
		ADD_STRUCT(Rotator, m_rPotentialSeekingTargetHUDRotation, 3020)
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71964);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool RidingPawnLeave(int SeatIndex, bool bForceLeave)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73029);
			byte params[12] = { NULL };
			*(int*)params = SeatIndex;
			*(bool*)&params[4] = bForceLeave;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		int GetSeatIndexForController(class Controller* ControllerToMove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76774);
			byte params[8] = { NULL };
			*(class Controller**)params = ControllerToMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool CalcOtherWatchingCam(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV, class TrPlayerController* WatcherController)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77526);
			byte params[40] = { NULL };
			*(float*)params = fDeltaTime;
			*(Vector*)&params[4] = out_CamLoc;
			*(Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			*(class TrPlayerController**)&params[32] = WatcherController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Vector*)&params[4];
			out_CamRot = *(Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
			return *(bool*)&params[36];
		}
		bool SetScannerDetect(bool detected)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79956);
			byte params[8] = { NULL };
			*(bool*)params = detected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107771);
			byte params[8] = { NULL };
			*(class Projectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void NativePostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114071);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ConsumePowerPool(float fAmount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114076);
			byte params[4] = { NULL };
			*(float*)params = fAmount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetPowerPoolPercent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114078);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void RegainPowerPool(float fDeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114080);
			byte params[4] = { NULL };
			*(float*)params = fDeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SyncClientCurrentPowerPool()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114082);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114083);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114087);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114088);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDetectedByEnemyScanner(bool detected)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114094);
			byte params[4] = { NULL };
			*(bool*)params = detected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetDetectedByEnemyScanner()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114096);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PancakeOther(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114099);
			byte params[4] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Controller* GetCollisionDamageInstigator()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114101);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Controller**)params;
		}
		float GetDamageAmountForCollision(float Speed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114103);
			byte params[8] = { NULL };
			*(float*)params = Speed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void RigidBodyCollision(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* HitComponent, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComponent, Actor::CollisionImpactData& Collision, int ContactIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114106);
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
		void RanInto(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114120);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SitDriver(class UTPawn* UTP, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114133);
			byte params[8] = { NULL };
			*(class UTPawn**)params = UTP;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachDriver(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114136);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPawnToTeleport(class TrPawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114139);
			byte params[4] = { NULL };
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPostSpawnLocked(bool bLocked)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114145);
			byte params[4] = { NULL };
			*(bool*)params = bLocked;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendLockOnMessage(int Switch)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114147);
			byte params[4] = { NULL };
			*(int*)params = Switch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114151);
			byte params[24] = { NULL };
			*(class Controller**)params = Killer;
			*(ScriptClass**)&params[4] = DamageType;
			*(Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		void KillControllerForTeamChange(class Controller* ControllerToKill)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114161);
			byte params[4] = { NULL };
			*(class Controller**)params = ControllerToKill;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeleportDriverToSeat()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114165);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanArmorDriveVehicle(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114166);
			byte params[8] = { NULL };
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CanArmorEnterVehicle(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114171);
			byte params[8] = { NULL };
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int GetFirstAvailableSeat(bool bSeatMustAllowFlag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114176);
			byte params[8] = { NULL };
			*(bool*)params = bSeatMustAllowFlag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool TryToDrive(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114180);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DriverLeft()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114192);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PassengerLeave(int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114197);
			byte params[4] = { NULL };
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckReset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114200);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetResetTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114201);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HandleMomentum(Vector Momentum, Vector HitLocation, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114202);
			byte params[56] = { NULL };
			*(Vector*)params = Momentum;
			*(Vector*)&params[12] = HitLocation;
			*(ScriptClass**)&params[24] = DamageType;
			*(Actor::TraceHitInfo*)&params[28] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ToggleBoosters(bool bEnabled, bool ToggleTimer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114207);
			byte params[8] = { NULL };
			*(bool*)params = bEnabled;
			*(bool*)&params[4] = ToggleTimer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ConsumeBoostPowerPool()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114211);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanActivateBoosters()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114212);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool ShouldRechargePowerPool()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114214);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ServerToggleLevelFlight(bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114216);
			byte params[4] = { NULL };
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BoostSoundFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114218);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = AC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayBoosterEffects(bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114220);
			byte params[4] = { NULL };
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayMissileLockSounds()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114222);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114225);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Occupied()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114227);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114230);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RenderDriverPassengerMarker(class Canvas* Canvas, bool friendly, class TrHUD* HUD, class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114261);
			byte params[20] = { NULL };
			*(class Canvas**)params = Canvas;
			*(bool*)&params[4] = friendly;
			*(class TrHUD**)&params[8] = HUD;
			*(class TrPlayerController**)&params[12] = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void SetSeatStoragePawn(int SeatIndex, class Pawn* PawnToSit)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114278);
			byte params[8] = { NULL };
			*(int*)params = SeatIndex;
			*(class Pawn**)&params[4] = PawnToSit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetSVehicleDebug(ScriptArray<ScriptString*>& DebugInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114282);
			byte params[12] = { NULL };
			*(ScriptArray<ScriptString*>*)params = DebugInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DebugInfo = *(ScriptArray<ScriptString*>*)params;
		}
		void InitializeSeats()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114285);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool PassengerEnter(class Pawn* P, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114287);
			byte params[12] = { NULL };
			*(class Pawn**)params = P;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AttachDriver(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114294);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AttachRidingPawn(class TrPawn* PawnToSit, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114296);
			byte params[8] = { NULL };
			*(class TrPawn**)params = PawnToSit;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachRidingPawn(class TrPawn* PawnLeft)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114300);
			byte params[4] = { NULL };
			*(class TrPawn**)params = PawnLeft;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateSeatAnimations(class TrPawn* PawnToSit, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114302);
			byte params[8] = { NULL };
			*(class TrPawn**)params = PawnToSit;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HoldGameObject(class UDKCarriedObject* GameObj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114311);
			byte params[4] = { NULL };
			*(class UDKCarriedObject**)params = GameObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HandleEnteringFlag(class UTPlayerReplicationInfo* EnteringPRI, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114313);
			byte params[8] = { NULL };
			*(class UTPlayerReplicationInfo**)params = EnteringPRI;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DriverEnter(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114323);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class PlayerReplicationInfo* GetSeatPRI(int SeatNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114329);
			byte params[8] = { NULL };
			*(int*)params = SeatNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerReplicationInfo**)&params[4];
		}
		void ServerChangeSeat(int RequestedSeat)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114332);
			byte params[4] = { NULL };
			*(int*)params = RequestedSeat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchSeat(int RequestedSeat, class Controller* ControllerRequestingSeatChange)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114334);
			byte params[8] = { NULL };
			*(int*)params = RequestedSeat;
			*(class Controller**)&params[4] = ControllerRequestingSeatChange;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ChangeSeat(class Controller* ControllerToMove, int RequestedSeat)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114337);
			byte params[12] = { NULL };
			*(class Controller**)params = ControllerToMove;
			*(int*)&params[4] = RequestedSeat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void SwitchWeapon(byte NewGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114344);
			byte params[1] = { NULL };
			*params = NewGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetSeatIndexForStoragePawn(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114348);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool PlaceExitingDriver(class Pawn* ExitingDriver)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114352);
			byte params[8] = { NULL };
			*(class Pawn**)params = ExitingDriver;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool TryExitPos(class Pawn* ExitingDriver, Vector ExitPos, bool bMustFindGround)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114359);
			byte params[24] = { NULL };
			*(class Pawn**)params = ExitingDriver;
			*(Vector*)&params[4] = ExitPos;
			*(bool*)&params[16] = bMustFindGround;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool SeatAvailable(int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114369);
			byte params[8] = { NULL };
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AnySeatAvailable()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114372);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		Rotator GetWeaponAim(class UTVehicleWeapon* VWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114375);
			byte params[16] = { NULL };
			*(class UTVehicleWeapon**)params = VWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[4];
		}
		void WeaponRotationChanged(int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114385);
			byte params[4] = { NULL };
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HealDamage(int Amount, class Controller* Healer, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114390);
			byte params[16] = { NULL };
			*(int*)params = Amount;
			*(class Controller**)&params[4] = Healer;
			*(ScriptClass**)&params[8] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void DoRepairs(int HealAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114395);
			byte params[68] = { NULL };
			*(int*)params = HealAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DriverRadiusDamage(float DamageAmount, float DamageRadius, class Controller* EventInstigator, ScriptClass* DamageType, float Momentum, Vector HitLocation, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114405);
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
		void Suicide()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114423);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114424);
			byte params[44] = { NULL };
			*(class Controller**)params = InstigatedBy;
			*(float*)&params[4] = BaseDamage;
			*(float*)&params[8] = DamageRadius;
			*(ScriptClass**)&params[12] = DamageType;
			*(float*)&params[16] = Momentum;
			*(Vector*)&params[20] = HurtOrigin;
			*(bool*)&params[32] = bFullDamage;
			*(class Actor**)&params[36] = DamageCauser;
			*(float*)&params[40] = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114440);
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
		void CheckDamageSmoke()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114472);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BlowupVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114474);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void VehicleWeaponFireEffects(Vector HitLocation, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114475);
			byte params[16] = { NULL };
			*(Vector*)params = HitLocation;
			*(int*)&params[12] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleWeaponStoppedFiring(bool bViaReplication, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114479);
			byte params[8] = { NULL };
			*(bool*)params = bViaReplication;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ThirdPersonFireEffects(Vector HitLocation, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114484);
			byte params[16] = { NULL };
			*(Vector*)params = HitLocation;
			*(int*)&params[12] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnTracerBeam(Vector Start, Vector End, class ParticleSystem* TracerBeamTemplate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114496);
			byte params[28] = { NULL };
			*(Vector*)params = Start;
			*(Vector*)&params[12] = End;
			*(class ParticleSystem**)&params[24] = TracerBeamTemplate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class TrProj_Tracer* SpawnTracerEffect(TrObject::EWeaponTracerType TracerType, Vector EffectLocation, Vector HitLocation, float HitDistance)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114501);
			byte params[33] = { NULL };
			*(TrObject::EWeaponTracerType*)params = TracerType;
			*(Vector*)&params[4] = EffectLocation;
			*(Vector*)&params[16] = HitLocation;
			*(float*)&params[28] = HitDistance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrProj_Tracer**)&params[32];
		}
		void ProcessViewRotation(float DeltaTime, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114510);
			byte params[28] = { NULL };
			*(float*)params = DeltaTime;
			*(Rotator*)&params[4] = out_ViewRotation;
			*(Rotator*)&params[16] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Rotator*)&params[4];
			out_DeltaRot = *(Rotator*)&params[16];
		}
		void ProcessViewRotationBasedOnSeat(int SeatIndex, float DeltaTime, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114514);
			byte params[32] = { NULL };
			*(int*)params = SeatIndex;
			*(float*)&params[4] = DeltaTime;
			*(Rotator*)&params[8] = out_ViewRotation;
			*(Rotator*)&params[20] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Rotator*)&params[8];
			out_DeltaRot = *(Rotator*)&params[20];
		}
		bool ShouldShowUseable(class PlayerController* PC, float Dist)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114519);
			byte params[12] = { NULL };
			*(class PlayerController**)params = PC;
			*(float*)&params[4] = Dist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void SetDriving(bool bNewDriving)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114523);
			byte params[4] = { NULL };
			*(bool*)params = bNewDriving;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayVehicleEvent(ScriptName EventTag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114525);
			byte params[8] = { NULL };
			*(ScriptName*)params = EventTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleEvent(ScriptName EventTag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114527);
			byte params[8] = { NULL };
			*(ScriptName*)params = EventTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayClientVehicleSound(ScriptName SoundTag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114529);
			byte params[8] = { NULL };
			*(ScriptName*)params = SoundTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MigrateVehicleSounds(class Pawn* P, bool bIsRiding)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114533);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			*(bool*)&params[4] = bIsRiding;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopVehicleSounds()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114538);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Vector GetCameraFocus(int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114553);
			byte params[16] = { NULL };
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[4];
		}
		ScriptString* GetSpectatorName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114563);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void PlayHorn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114639);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GoInvulnerable(float InvulnerableTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114640);
			byte params[4] = { NULL };
			*(float*)params = InvulnerableTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearInvulnerability()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114642);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
