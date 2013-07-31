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
		ADD_STRUCT(Vector, m_vDeathCamStartOffset, 1508)
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
		ADD_STRUCT(Vector, m_PlacementOrientationVector, 1392)
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71758);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float CalcMeshOffset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71759);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		bool IsInLOS(class Actor* TouchedActor, Vector StartLocation, Vector EndLocation, bool CheckBlockedByBlockers, bool CheckBlockedByActors)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71761);
			byte params[40] = { NULL };
			*(class Actor**)params = TouchedActor;
			*(Vector*)&params[4] = StartLocation;
			*(Vector*)&params[16] = EndLocation;
			*(bool*)&params[28] = CheckBlockedByBlockers;
			*(bool*)&params[32] = CheckBlockedByActors;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[36];
		}
		void ApplyServerSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71768);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71771);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71773);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPRIReplicated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71775);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71777);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71779);
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
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71793);
			byte params[68] = { NULL };
			*(int*)params = DamageAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPawnDetectedByCollisionProxy(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71822);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPawnExitedCollisionProxy(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71824);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnVehicleDetectedByCollisionProxy(class TrVehicle* V)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71826);
			byte params[4] = { NULL };
			*(class TrVehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnVehicleExitedCollisionProxy(class TrVehicle* V)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71828);
			byte params[4] = { NULL };
			*(class TrVehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPowerStatusChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71830);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInstigatorController(class TrPlayerController* InstigatorController)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71831);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = InstigatorController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71838);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetDamageRadius()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71841);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void FinalizeDeployment()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71848);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DeployComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71850);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsFiring()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71851);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void UpdateHealthMaterial()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71860);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnHealthChanged(bool wasDamage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71864);
			byte params[4] = { NULL };
			*(bool*)params = wasDamage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Vector GetWeaponStartTraceLocation(class Weapon* CurrentWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71866);
			byte params[16] = { NULL };
			*(class Weapon**)params = CurrentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[4];
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71869);
			byte params[8] = { NULL };
			*(class Projectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void IncrementFlashCount(class Weapon* W, byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71873);
			byte params[5] = { NULL };
			*(class Weapon**)params = W;
			params[4] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayFireEffects(class Weapon* InWeapon, bool bViaReplication, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71877);
			byte params[20] = { NULL };
			*(class Weapon**)params = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			*(Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PulseBackupGenerators()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71881);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71883);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ReceivesPowerFromGenerator()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71889);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool GetPossessiveInstigatorName(ScriptString*& PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71893);
			byte params[16] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PlayerName = *(ScriptString**)params;
			return *(bool*)&params[12];
		}
		bool CalcOtherWatchingCam(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV, class TrPlayerController* WatcherController)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71896);
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
		void OnUpgradePerformed(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71914);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
	const float TrDeployable::DEPLOYABLE_STARTING_HEALTH_PCT = 0.10f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
