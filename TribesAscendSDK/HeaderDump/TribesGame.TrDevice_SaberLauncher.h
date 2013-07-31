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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86024);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86032);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResumeTargeting()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86033);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SuspendTargeting()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86034);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86037);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool TargetInsideReticle(class Actor* Target, bool initialAcquire)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86038);
			byte params[12] = { NULL };
			*(class Actor**)params = Target;
			*(bool*)&params[4] = initialAcquire;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsActorInLOS(class Actor* A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86042);
			byte params[8] = { NULL };
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ValidateTrackingTarget(class Actor* Target, bool initialAcquire)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86047);
			byte params[12] = { NULL };
			*(class Actor**)params = Target;
			*(bool*)&params[4] = initialAcquire;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void SetTargetActorMissileLockState(class Actor* Target, TrObject::EMissileLock lockValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86054);
			byte params[5] = { NULL };
			*(class Actor**)params = Target;
			*(TrObject::EMissileLock*)&params[4] = lockValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetNewTrackingTarget(class Actor* Target)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86058);
			byte params[4] = { NULL };
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TargetLockAcquired()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86060);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86061);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86064);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PerformTargeting()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86065);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchAwayFromWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86078);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchToWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86079);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HolderEnteredVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86080);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HolderExitedVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86081);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86082);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Projectile**)params;
		}
		void ServerTryNewPossibleTarget()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86085);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86086);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86088);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class TrSeekingMissileManager* GetSeekingMissileManager()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86091);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrSeekingMissileManager**)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
