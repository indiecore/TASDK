#pragma once
#include "TribesGame.TrSeekingMissileManager.h"
#include "TribesGame.TrDevice.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.Actor.h"
#include "TribesGame.TrObject.h"
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
	class TrDevice_SaberLauncher : public TrDevice
	{
	public:
		ADD_BOOL(r_bTargetLocked, 2160, 0x1)
		ADD_OBJECT(TrPlayerController, m_TargetController, 2212)
		ADD_STRUCT(byte, r_nFired, 2208)
		ADD_STRUCT(float, m_fLockingTargetTimestamp, 2204)
		ADD_STRUCT(float, m_fTimeBeforeVictimKnowsMissileIsTargeting, 2200)
		ADD_STRUCT(float, m_fGroundCheckDistance, 2196)
		ADD_STRUCT(float, m_fPotentialTargetLockOnDist, 2192)
		ADD_STRUCT(float, m_fReticuleLockOnDist, 2188)
		ADD_STRUCT(float, m_fLockRetainSeconds, 2184)
		ADD_STRUCT(float, m_fRestoreAimHelpRadius, 2180)
		ADD_STRUCT(float, m_fMinCosineAcquireTarget, 2176)
		ADD_STRUCT(float, m_fAcquireTargetMaxAngle, 2172)
		ADD_STRUCT(float, m_fRetainTargetMaxAngle, 2168)
		ADD_STRUCT(float, m_fMinCosineRetainTarget, 2164)
		ADD_BOOL(m_bDebugMode, 2160, 0x4)
		ADD_BOOL(m_bRestoreAimingHelp, 2160, 0x2)
		ADD_OBJECT(Actor, m_Target, 2156)
		ADD_STRUCT(float, m_fPreLockTime, 2152)
		ADD_STRUCT(float, m_fTargetSightTime, 2148)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResumeTargeting()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.ResumeTargeting");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SuspendTargeting()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.SuspendTargeting");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool TargetInsideReticle(class Actor* Target, bool initialAcquire)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.TargetInsideReticle");
			byte params[12] = { NULL };
			*(class Actor**)&params[0] = Target;
			*(bool*)&params[4] = initialAcquire;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsActorInLOS(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.IsActorInLOS");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ValidateTrackingTarget(class Actor* Target, bool initialAcquire)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.ValidateTrackingTarget");
			byte params[12] = { NULL };
			*(class Actor**)&params[0] = Target;
			*(bool*)&params[4] = initialAcquire;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void SetTargetActorMissileLockState(class Actor* Target, TrObject::EMissileLock lockValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.SetTargetActorMissileLockState");
			byte params[5] = { NULL };
			*(class Actor**)&params[0] = Target;
			*(TrObject::EMissileLock*)&params[4] = lockValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetNewTrackingTarget(class Actor* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.SetNewTrackingTarget");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TargetLockAcquired()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.TargetLockAcquired");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.FireAmmunition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PerformTargeting()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.PerformTargeting");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchAwayFromWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.OnSwitchAwayFromWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchToWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.OnSwitchToWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HolderEnteredVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.HolderEnteredVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HolderExitedVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.HolderExitedVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.ProjectileFire");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Projectile**)&params[0];
		}
		void ServerTryNewPossibleTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.ServerTryNewPossibleTarget");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.BeginFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.StartFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class TrSeekingMissileManager* GetSeekingMissileManager()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.GetSeekingMissileManager");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrSeekingMissileManager**)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
