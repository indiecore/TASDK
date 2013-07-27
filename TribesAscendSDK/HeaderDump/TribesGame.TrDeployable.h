#pragma once
#include "TribesGame.TrGameObjective.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Controller.h"
#include "Engine.PlayerReplicationInfo.h"
#include "TribesGame.TrPowerGenerator.h"
#include "Engine.AnimNodeScalePlayRate.h"
#include "Engine.PlayerController.h"
#include "Engine.SoundCue.h"
#include "Engine.Weapon.h"
#include "Engine.Pawn.h"
#include "TribesGame.TrSubDevice.h"
#include "TribesGame.TrTurretPawn.h"
#include "TribesGame.TrDeployableCollisionProxy.h"
#include "TribesGame.TrPawn.h"
#include "TribesGame.TrVehicle.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.Projectile.h"
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
	class TrDeployable : public TrGameObjective
	{
	public:
		static const float DEPLOYABLE_STARTING_HEALTH_PCT;
		ADD_OBJECT(Controller, m_Controller, 1408)
		ADD_STRUCT(ScriptArray<float>, m_fRelevancyCheckHeights, 1480)
		ADD_STRUCT(int, m_nIconStackId, 1520)
		ADD_STRUCT(Object::Vector, m_vDeathCamStartOffset, 1508)
		ADD_OBJECT(PlayerReplicationInfo, r_OwnerPRI, 1504)
		ADD_STRUCT(float, m_fAnimInterpSpeed, 1496)
		ADD_OBJECT(AnimNodeScalePlayRate, m_AnimNodeScale, 1492)
		ADD_OBJECT(Actor, m_LastViewer, 1476)
		ADD_OBJECT(PlayerController, m_LastRealViewer, 1472)
		ADD_STRUCT(float, m_fNetRelevancyTime, 1468)
		ADD_OBJECT(SoundCue, m_DeploySound, 1464)
		ADD_OBJECT(TrPowerGenerator, m_MyMainGenerator, 1460)
		ADD_OBJECT(Pawn, r_TargetPawn, 1456)
		ADD_STRUCT(byte, r_FlashCount, 1452)
		ADD_OBJECT(TrSubDevice, m_Weapon, 1448)
		ADD_OBJECT(TrTurretPawn, m_WeaponHolder, 1444)
		ADD_OBJECT(ScriptClass, m_DeviceClass, 1440)
		ADD_STRUCT(float, m_fAlwaysRelevantDistanceSquared, 1436)
		ADD_STRUCT(float, r_fNewDetectionRadius, 1432)
		ADD_STRUCT(float, m_fDamageRadius, 1428)
		ADD_OBJECT(TrDeployableCollisionProxy, m_CollisionProxy, 1424)
		ADD_STRUCT(float, m_fOverriddenTargetComponentHeight, 1420)
		ADD_STRUCT(float, m_TargetCollisionTraceDistance, 1416)
		ADD_STRUCT(float, m_fFiringArcCheckValue, 1404)
		ADD_STRUCT(Object::Vector, m_PlacementOrientationVector, 1392)
		ADD_STRUCT(int, m_nFiringArcDegrees, 1388)
		ADD_BOOL(m_bBlocksFriendlies, 1384, 0x80)
		ADD_BOOL(m_bCanBeSpottedByVGS, 1384, 0x40)
		ADD_BOOL(m_bIsXRay, 1384, 0x20)
		ADD_BOOL(m_bCachedRelevant, 1384, 0x10)
		ADD_BOOL(m_bOverrideTargetComponentHeight, 1384, 0x8)
		ADD_BOOL(m_bUsesArmoredMultiplier, 1384, 0x4)
		ADD_BOOL(m_bRequireLOS, 1384, 0x2)
		ADD_BOOL(m_bIsDeployed, 1384, 0x1)
		ADD_STRUCT(float, m_fTimeToDeploySecs, 1380)
		ADD_STRUCT(float, m_fRemoteActivationTime, 1376)
		ADD_STRUCT(float, m_fBuildupTime, 1372)
		ADD_OBJECT(TrPawn, m_TouchedPlayer, 1368)
		ADD_STRUCT(float, m_TimeCreated, 1364)
		ADD_STRUCT(int, m_nMaxDeployablesOut, 1360)
		void AdjustMeshToGround()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.AdjustMeshToGround");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float CalcMeshOffset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.CalcMeshOffset");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		bool IsInLOS(class Actor* TouchedActor, Object::Vector StartLocation, Object::Vector EndLocation, bool CheckBlockedByBlockers, bool CheckBlockedByActors)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.IsInLOS");
			byte params[40] = { NULL };
			*(class Actor**)&params[0] = TouchedActor;
			*(Object::Vector*)&params[4] = StartLocation;
			*(Object::Vector*)&params[16] = EndLocation;
			*(bool*)&params[28] = CheckBlockedByBlockers;
			*(bool*)&params[32] = CheckBlockedByActors;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[36];
		}
		void ApplyServerSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.ApplyServerSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.PostInitAnimTree");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPRIReplicated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.OnPRIReplicated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Object::Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.TakeRadiusDamage");
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
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Object::Vector HitLocation, Object::Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.TakeDamage");
			byte params[68] = { NULL };
			*(int*)&params[0] = DamageAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPawnDetectedByCollisionProxy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.OnPawnDetectedByCollisionProxy");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPawnExitedCollisionProxy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.OnPawnExitedCollisionProxy");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnVehicleDetectedByCollisionProxy(class TrVehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.OnVehicleDetectedByCollisionProxy");
			byte params[4] = { NULL };
			*(class TrVehicle**)&params[0] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnVehicleExitedCollisionProxy(class TrVehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.OnVehicleExitedCollisionProxy");
			byte params[4] = { NULL };
			*(class TrVehicle**)&params[0] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPowerStatusChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.OnPowerStatusChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInstigatorController(class TrPlayerController* InstigatorController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.SetInstigatorController");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = InstigatorController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetDamageRadius()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.GetDamageRadius");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void FinalizeDeployment()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.FinalizeDeployment");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DeployComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.DeployComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsFiring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.IsFiring");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void UpdateHealthMaterial()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.UpdateHealthMaterial");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnHealthChanged(bool wasDamage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.OnHealthChanged");
			byte params[4] = { NULL };
			*(bool*)&params[0] = wasDamage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector GetWeaponStartTraceLocation(class Weapon* CurrentWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.GetWeaponStartTraceLocation");
			byte params[16] = { NULL };
			*(class Weapon**)&params[0] = CurrentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[4];
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.StopsProjectile");
			byte params[8] = { NULL };
			*(class Projectile**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void IncrementFlashCount(class Weapon* W, byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.IncrementFlashCount");
			byte params[5] = { NULL };
			*(class Weapon**)&params[0] = W;
			params[4] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayFireEffects(class Weapon* InWeapon, bool bViaReplication, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.PlayFireEffects");
			byte params[20] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			*(Object::Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PulseBackupGenerators()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.PulseBackupGenerators");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ReceivesPowerFromGenerator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.ReceivesPowerFromGenerator");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool GetPossessiveInstigatorName(ScriptString*& PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.GetPossessiveInstigatorName");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PlayerName = *(ScriptString**)&params[0];
			return *(bool*)&params[12];
		}
		bool CalcOtherWatchingCam(float fDeltaTime, Object::Vector& out_CamLoc, Object::Rotator& out_CamRot, float& out_FOV, class TrPlayerController* WatcherController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.CalcOtherWatchingCam");
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
		void OnUpgradePerformed(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable.OnUpgradePerformed");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
	const float TrDeployable::DEPLOYABLE_STARTING_HEALTH_PCT = 0.10f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
