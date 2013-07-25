#pragma once
#include "UTGame__UTVehicle.h"
#include "TribesGame__TrStatsInterface.h"
#include "Engine__Projectile.h"
#include "TribesGame__TrPlayerController.h"
#include "TribesGame__TrPawn.h"
#include "TribesGame__TrHUD.h"
#include "TribesGame__TrVehicleStation.h"
#include "Engine__MaterialInstanceConstant.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#include "Engine__PlayerController.h"
#include "Engine__Canvas.h"
#include "Engine__Actor.h"
#include "UTGame__UTPawn.h"
#include "UDKBase__UDKCarriedObject.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#include "Engine__PlayerReplicationInfo.h"
#include "UTGame__UTVehicleWeapon.h"
#include "Engine__ParticleSystem.h"
#include "TribesGame__TrProj_Tracer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrVehicle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrVehicle : public UTVehicle
	{
	public:
		ADD_VAR(::FloatProperty, m_fCurrentPowerPool, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fMaxPowerPool, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_sName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nIconIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bClientPhysDirty, 0x100)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.RigidBodyState' for the property named 'm_ClientRBState'!
		ADD_VAR(::BoolProperty, m_bServerCorrectionForce, 0x200)
		ADD_VAR(::BoolProperty, m_bImprovedLagSupport, 0x4)
		ADD_VAR(::ByteProperty, m_VehicleType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bUsesArmoredMultiplier, 0x80)
		ADD_VAR(::StrProperty, m_sWeapon1Name, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_sWeapon2Name, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxPawnLeaveSpeed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nDetectedByEnemyScannerCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nServerTickCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fClientPhysDeltaTime, 0xFFFFFFFF)
		ADD_OBJECT(TrStatsInterface, Stats)
		ADD_STRUCT(::VectorProperty, m_vDeathCamStartOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleHealthBarHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleHealthBarWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleHealthBarPlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleHealthBarPlacementX, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_MarkerMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_Passenger4HealthBarMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_Passenger3HealthBarMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_Passenger2HealthBarMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_Passenger1HealthBarMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_DriverHealthBarMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_HealthBarMIC)
		ADD_VAR(::FloatProperty, m_fRemainingSeekingTargetHUDZoomTime, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, m_rPotentialSeekingTargetHUDRotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRemainingPotentialSeekingTargetHUDZoomTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fContrailSpeed, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.MaterialImpactEffect' for the property named 'm_DefaultDustEffect'!
		ADD_VAR(::FloatProperty, ShowHeaderUntil, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBoostFadeOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBoostFadeInTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDivingMaxSpeedMultiplier, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nBaseMaxSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fWallDamageTickTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastWallDamageTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fWallMaxDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fWallMinDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fWallMinDamageSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fWallMaxDamageSpeed, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, WallCollisionDamageType)
		ADD_VAR(::FloatProperty, m_fVehicleDamageTickTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastVehicleDamageTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleMaxDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleMinDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleMinDamageSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleMaxDamageSpeed, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, VehicleCollisionDamageType)
		ADD_VAR(::FloatProperty, m_fPawnDamageTickTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPawnMaxDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPawnMinDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPawnMaxDamageSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPawnPushSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFlagPushSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_CrashDamageSeverity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPowerPoolTickRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPowerPoolRechargeRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fCurrentPowerPool, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBoostReactivatePct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBoostEnergyPerSec, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBoostMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTimeToReset, 0xFFFFFFFF)
		ADD_OBJECT(TrVehicleStation, m_OwnerStation)
		ADD_VAR(::ByteProperty, m_MissileLockStatus, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_MissileLock, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, r_bDetectedByEnemyScanner, 0x400)
		ADD_VAR(::BoolProperty, r_LevelFlightEnabled, 0x40)
		ADD_VAR(::BoolProperty, m_bLowPowerPool, 0x20)
		ADD_VAR(::BoolProperty, r_BoostersEnabled, 0x10)
		ADD_VAR(::BoolProperty, r_bIsInvulnerable, 0x8)
		ADD_VAR(::BoolProperty, m_bBoostRequiresThrust, 0x2)
		ADD_VAR(::BoolProperty, m_bPostSpawnLocked, 0x1)
		ADD_OBJECT(TrPawn, m_PawnToTeleport)
		ADD_OBJECT(Pawn, Passenger)
		bool IsEmpty()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.IsEmpty");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool RidingPawnLeave(int SeatIndex, bool bForceLeave)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.RidingPawnLeave");
			byte* params = (byte*)malloc(12);
			*(int*)params = SeatIndex;
			*(bool*)(params + 4) = bForceLeave;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		int GetSeatIndexForController(class Controller* ControllerToMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetSeatIndexForController");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = ControllerToMove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CalcOtherWatchingCam(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV, class TrPlayerController* WatcherController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.CalcOtherWatchingCam");
			byte* params = (byte*)malloc(40);
			*(float*)params = fDeltaTime;
			*(Vector*)(params + 4) = out_CamLoc;
			*(Rotator*)(params + 16) = out_CamRot;
			*(float*)(params + 28) = out_FOV;
			*(class TrPlayerController**)(params + 32) = WatcherController;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_CamLoc = *(Vector*)(params + 4);
			out_CamRot = *(Rotator*)(params + 16);
			out_FOV = *(float*)(params + 28);
			auto returnVal = *(bool*)(params + 36);
			free(params);
			return returnVal;
		}
		bool SetScannerDetect(bool detected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SetScannerDetect");
			byte* params = (byte*)malloc(8);
			*(bool*)params = detected;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.StopsProjectile");
			byte* params = (byte*)malloc(8);
			*(class Projectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void NativePostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.NativePostRenderFor");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ConsumePowerPool(float fAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ConsumePowerPool");
			byte* params = (byte*)malloc(4);
			*(float*)params = fAmount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetPowerPoolPercent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetPowerPoolPercent");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void RegainPowerPool(float fDeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.RegainPowerPool");
			byte* params = (byte*)malloc(4);
			*(float*)params = fDeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SyncClientCurrentPowerPool()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SyncClientCurrentPowerPool");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetDetectedByEnemyScanner(bool detected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SetDetectedByEnemyScanner");
			byte* params = (byte*)malloc(4);
			*(bool*)params = detected;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetDetectedByEnemyScanner()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetDetectedByEnemyScanner");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PancakeOther(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PancakeOther");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Controller* GetCollisionDamageInstigator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetCollisionDamageInstigator");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Controller**)params;
			free(params);
			return returnVal;
		}
		float GetDamageAmountForCollision(float Speed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetDamageAmountForCollision");
			byte* params = (byte*)malloc(8);
			*(float*)params = Speed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void RigidBodyCollision(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* HitComponent, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComponent, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.CollisionImpactData'!
void*& Collision, int ContactIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.RigidBodyCollision");
			byte* params = (byte*)malloc(48);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = HitComponent;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = OtherComponent;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.CollisionImpactData'!
void**)(params + 8) = Collision;
			*(int*)(params + 44) = ContactIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Collision = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.CollisionImpactData'!
void**)(params + 8);
			free(params);
		}
		void RanInto(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.RanInto");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SitDriver(class UTPawn* UTP, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SitDriver");
			byte* params = (byte*)malloc(8);
			*(class UTPawn**)params = UTP;
			*(int*)(params + 4) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DetachDriver(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.DetachDriver");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPawnToTeleport(class TrPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SetPawnToTeleport");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPostSpawnLocked(bool bLocked)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SetPostSpawnLocked");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bLocked;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendLockOnMessage(int Switch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SendLockOnMessage");
			byte* params = (byte*)malloc(4);
			*(int*)params = Switch;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.Died");
			byte* params = (byte*)malloc(24);
			*(class Controller**)params = Killer;
			*(ScriptClass**)(params + 4) = DamageType;
			*(Vector*)(params + 8) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		void KillControllerForTeamChange(class Controller* ControllerToKill)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.KillControllerForTeamChange");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = ControllerToKill;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeleportDriverToSeat()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.TeleportDriverToSeat");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanArmorDriveVehicle(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.CanArmorDriveVehicle");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CanArmorEnterVehicle(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.CanArmorEnterVehicle");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetFirstAvailableSeat(bool bSeatMustAllowFlag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetFirstAvailableSeat");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bSeatMustAllowFlag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool TryToDrive(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.TryToDrive");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void DriverLeft()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.DriverLeft");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PassengerLeave(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PassengerLeave");
			byte* params = (byte*)malloc(4);
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void HandleMomentum(Vector Momentum, Vector HitLocation, ScriptClass* DamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.HandleMomentum");
			byte* params = (byte*)malloc(56);
			*(Vector*)params = Momentum;
			*(Vector*)(params + 12) = HitLocation;
			*(ScriptClass**)(params + 24) = DamageType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 28) = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ToggleBoosters(bool bEnabled, bool ToggleTimer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ToggleBoosters");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bEnabled;
			*(bool*)(params + 4) = ToggleTimer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ConsumeBoostPowerPool()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ConsumeBoostPowerPool");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanActivateBoosters()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.CanActivateBoosters");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool ShouldRechargePowerPool()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ShouldRechargePowerPool");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ServerToggleLevelFlight(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ServerToggleLevelFlight");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BoostSoundFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.BoostSoundFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = AC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayBoosterEffects(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PlayBoosterEffects");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayMissileLockSounds()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PlayMissileLockSounds");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool Occupied()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.Occupied");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PostRenderFor");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool RenderDriverPassengerMarker(class Canvas* Canvas, bool friendly, class TrHUD* HUD, class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.RenderDriverPassengerMarker");
			byte* params = (byte*)malloc(20);
			*(class Canvas**)params = Canvas;
			*(bool*)(params + 4) = friendly;
			*(class TrHUD**)(params + 8) = HUD;
			*(class TrPlayerController**)(params + 12) = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void SetSeatStoragePawn(int SeatIndex, class Pawn* PawnToSit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SetSeatStoragePawn");
			byte* params = (byte*)malloc(8);
			*(int*)params = SeatIndex;
			*(class Pawn**)(params + 4) = PawnToSit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetSVehicleDebug(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& DebugInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetSVehicleDebug");
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
		void InitializeSeats()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.InitializeSeats");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool PassengerEnter(class Pawn* P, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PassengerEnter");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = P;
			*(int*)(params + 4) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void AttachDriver(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.AttachDriver");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AttachRidingPawn(class TrPawn* PawnToSit, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.AttachRidingPawn");
			byte* params = (byte*)malloc(8);
			*(class TrPawn**)params = PawnToSit;
			*(int*)(params + 4) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DetachRidingPawn(class TrPawn* PawnLeft)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.DetachRidingPawn");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = PawnLeft;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateSeatAnimations(class TrPawn* PawnToSit, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.UpdateSeatAnimations");
			byte* params = (byte*)malloc(8);
			*(class TrPawn**)params = PawnToSit;
			*(int*)(params + 4) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HoldGameObject(class UDKCarriedObject* GameObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.HoldGameObject");
			byte* params = (byte*)malloc(4);
			*(class UDKCarriedObject**)params = GameObj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HandleEnteringFlag(class UTPlayerReplicationInfo* EnteringPRI, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.HandleEnteringFlag");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerReplicationInfo**)params = EnteringPRI;
			*(int*)(params + 4) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool DriverEnter(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.DriverEnter");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class PlayerReplicationInfo* GetSeatPRI(int SeatNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetSeatPRI");
			byte* params = (byte*)malloc(8);
			*(int*)params = SeatNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PlayerReplicationInfo**)(params + 4);
			free(params);
			return returnVal;
		}
		void ServerChangeSeat(int RequestedSeat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ServerChangeSeat");
			byte* params = (byte*)malloc(4);
			*(int*)params = RequestedSeat;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SwitchSeat(int RequestedSeat, class Controller* ControllerRequestingSeatChange)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SwitchSeat");
			byte* params = (byte*)malloc(8);
			*(int*)params = RequestedSeat;
			*(class Controller**)(params + 4) = ControllerRequestingSeatChange;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ChangeSeat(class Controller* ControllerToMove, int RequestedSeat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ChangeSeat");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = ControllerToMove;
			*(int*)(params + 4) = RequestedSeat;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void SwitchWeapon(byte NewGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SwitchWeapon");
			byte* params = (byte*)malloc(1);
			*params = NewGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetSeatIndexForStoragePawn(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetSeatIndexForStoragePawn");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool PlaceExitingDriver(class Pawn* ExitingDriver)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PlaceExitingDriver");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = ExitingDriver;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool TryExitPos(class Pawn* ExitingDriver, Vector ExitPos, bool bMustFindGround)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.TryExitPos");
			byte* params = (byte*)malloc(24);
			*(class Pawn**)params = ExitingDriver;
			*(Vector*)(params + 4) = ExitPos;
			*(bool*)(params + 16) = bMustFindGround;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool SeatAvailable(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SeatAvailable");
			byte* params = (byte*)malloc(8);
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool AnySeatAvailable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.AnySeatAvailable");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		Rotator GetWeaponAim(class UTVehicleWeapon* VWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetWeaponAim");
			byte* params = (byte*)malloc(16);
			*(class UTVehicleWeapon**)params = VWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 4);
			free(params);
			return returnVal;
		}
		void WeaponRotationChanged(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.WeaponRotationChanged");
			byte* params = (byte*)malloc(4);
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool HealDamage(int Amount, class Controller* Healer, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.HealDamage");
			byte* params = (byte*)malloc(16);
			*(int*)params = Amount;
			*(class Controller**)(params + 4) = Healer;
			*(ScriptClass**)(params + 8) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void DoRepairs(int HealAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.DoRepairs");
			byte* params = (byte*)malloc(68);
			*(int*)params = HealAmount;
			*(class Controller**)(params + 4) = EventInstigator;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DriverRadiusDamage(float DamageAmount, float DamageRadius, class Controller* EventInstigator, ScriptClass* DamageType, float Momentum, Vector HitLocation, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.DriverRadiusDamage");
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
		void Suicide()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.Suicide");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.TakeRadiusDamage");
			byte* params = (byte*)malloc(44);
			*(class Controller**)params = InstigatedBy;
			*(float*)(params + 4) = BaseDamage;
			*(float*)(params + 8) = DamageRadius;
			*(ScriptClass**)(params + 12) = DamageType;
			*(float*)(params + 16) = Momentum;
			*(Vector*)(params + 20) = HurtOrigin;
			*(bool*)(params + 32) = bFullDamage;
			*(class Actor**)(params + 36) = DamageCauser;
			*(float*)(params + 40) = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.TakeDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = Damage;
			*(class Controller**)(params + 4) = EventInstigator;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void VehicleWeaponFireEffects(Vector HitLocation, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.VehicleWeaponFireEffects");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = HitLocation;
			*(int*)(params + 12) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void VehicleWeaponStoppedFiring(bool bViaReplication, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.VehicleWeaponStoppedFiring");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bViaReplication;
			*(int*)(params + 4) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ThirdPersonFireEffects(Vector HitLocation, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ThirdPersonFireEffects");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = HitLocation;
			*(int*)(params + 12) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpawnTracerBeam(Vector Start, Vector End, class ParticleSystem* TracerBeamTemplate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SpawnTracerBeam");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = Start;
			*(Vector*)(params + 12) = End;
			*(class ParticleSystem**)(params + 24) = TracerBeamTemplate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class TrProj_Tracer* SpawnTracerEffect(byte TracerType, Vector EffectLocation, Vector HitLocation, float HitDistance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SpawnTracerEffect");
			byte* params = (byte*)malloc(33);
			*params = TracerType;
			*(Vector*)(params + 4) = EffectLocation;
			*(Vector*)(params + 16) = HitLocation;
			*(float*)(params + 28) = HitDistance;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrProj_Tracer**)(params + 32);
			free(params);
			return returnVal;
		}
		void ProcessViewRotation(float DeltaTime, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ProcessViewRotation");
			byte* params = (byte*)malloc(28);
			*(float*)params = DeltaTime;
			*(Rotator*)(params + 4) = out_ViewRotation;
			*(Rotator*)(params + 16) = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ViewRotation = *(Rotator*)(params + 4);
			out_DeltaRot = *(Rotator*)(params + 16);
			free(params);
		}
		void ProcessViewRotationBasedOnSeat(int SeatIndex, float DeltaTime, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ProcessViewRotationBasedOnSeat");
			byte* params = (byte*)malloc(32);
			*(int*)params = SeatIndex;
			*(float*)(params + 4) = DeltaTime;
			*(Rotator*)(params + 8) = out_ViewRotation;
			*(Rotator*)(params + 20) = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ViewRotation = *(Rotator*)(params + 8);
			out_DeltaRot = *(Rotator*)(params + 20);
			free(params);
		}
		bool ShouldShowUseable(class PlayerController* PC, float Dist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ShouldShowUseable");
			byte* params = (byte*)malloc(12);
			*(class PlayerController**)params = PC;
			*(float*)(params + 4) = Dist;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void SetDriving(bool bNewDriving)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.SetDriving");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewDriving;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayVehicleEvent(ScriptName EventTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PlayVehicleEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = EventTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void VehicleEvent(ScriptName EventTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.VehicleEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = EventTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayClientVehicleSound(ScriptName SoundTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PlayClientVehicleSound");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = SoundTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MigrateVehicleSounds(class Pawn* P, bool bIsRiding)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.MigrateVehicleSounds");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			*(bool*)(params + 4) = bIsRiding;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopVehicleSounds()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.StopVehicleSounds");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Vector GetCameraFocus(int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetCameraFocus");
			byte* params = (byte*)malloc(16);
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetSpectatorName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GetSpectatorName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void PlayHorn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.PlayHorn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GoInvulnerable(float InvulnerableTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.GoInvulnerable");
			byte* params = (byte*)malloc(4);
			*(float*)params = InvulnerableTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearInvulnerability()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle.ClearInvulnerability");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
