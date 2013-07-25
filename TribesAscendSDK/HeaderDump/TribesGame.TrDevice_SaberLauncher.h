#pragma once
#include "TribesGame.TrSeekingMissileManager.h"
#include "TribesGame.TrDevice.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.Actor.h"
#include "Engine.Projectile.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_SaberLauncher." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_SaberLauncher." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_SaberLauncher : public TrDevice
	{
	public:
		ADD_VAR(::BoolProperty, r_bTargetLocked, 0x1)
		ADD_OBJECT(TrPlayerController, m_TargetController)
		ADD_VAR(::ByteProperty, r_nFired, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLockingTargetTimestamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTimeBeforeVictimKnowsMissileIsTargeting, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fGroundCheckDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPotentialTargetLockOnDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fReticuleLockOnDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLockRetainSeconds, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRestoreAimHelpRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMinCosineAcquireTarget, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAcquireTargetMaxAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRetainTargetMaxAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMinCosineRetainTarget, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bDebugMode, 0x4)
		ADD_VAR(::BoolProperty, m_bRestoreAimingHelp, 0x2)
		ADD_OBJECT(Actor, m_Target)
		ADD_VAR(::FloatProperty, m_fPreLockTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTargetSightTime, 0xFFFFFFFF)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(12);
			*(class Actor**)params = Target;
			*(bool*)(params + 4) = initialAcquire;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool IsActorInLOS(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.IsActorInLOS");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ValidateTrackingTarget(class Actor* Target, bool initialAcquire)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.ValidateTrackingTarget");
			byte* params = (byte*)malloc(12);
			*(class Actor**)params = Target;
			*(bool*)(params + 4) = initialAcquire;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void SetTargetActorMissileLockState(class Actor* Target, byte lockValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.SetTargetActorMissileLockState");
			byte* params = (byte*)malloc(5);
			*(class Actor**)params = Target;
			*(params + 4) = lockValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetNewTrackingTarget(class Actor* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.SetNewTrackingTarget");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TargetLockAcquired()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.TargetLockAcquired");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Projectile**)params;
			free(params);
			return returnVal;
		}
		void ServerTryNewPossibleTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.ServerTryNewPossibleTarget");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.BeginFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.StartFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class TrSeekingMissileManager* GetSeekingMissileManager()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SaberLauncher.GetSeekingMissileManager");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrSeekingMissileManager**)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
