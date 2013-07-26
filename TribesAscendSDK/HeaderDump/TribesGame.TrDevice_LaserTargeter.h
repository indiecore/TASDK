#pragma once
#include "Engine.Actor.h"
#include "TribesGame.TrDevice_ConstantFire.h"
#include "TribesGame.TrCallIn.h"
#include "Core.Object.Vector.h"
#include "Core.Object.Rotator.h"
#include "Engine.SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_LaserTargeter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDevice_LaserTargeter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_LaserTargeter." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_LaserTargeter : public TrDevice_ConstantFire
	{
	public:
		ADD_VAR(::ByteProperty, r_ActiveCallin, 0xFFFFFFFF)
		ADD_OBJECT(TrCallIn, r_CallIns)
		ADD_STRUCT(::VectorProperty, m_LastTargetPos, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, m_LastOwnerRot, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, m_CallInConfirmation)
		ADD_VAR(::ByteProperty, m_PrevActiveCallin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCallInEndTime, 0xFFFFFFFF)
		float CalcHUDAimChargePercent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.CalcHUDAimChargePercent");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		bool IsValidCallIn(byte CallInIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.IsValidCallIn");
			byte* params = (byte*)malloc(5);
			*params = CallInIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsValidTargetLocation(Vector CurrentTarget, Vector PreviousTarget, class Actor* HitTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.IsValidTargetLocation");
			byte* params = (byte*)malloc(32);
			*(Vector*)params = CurrentTarget;
			*(Vector*)(params + 12) = PreviousTarget;
			*(class Actor**)(params + 24) = HitTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateCallins()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.UpdateCallins");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanFireCallIn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.CanFireCallIn");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetActiveCallIn(byte CallInIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.SetActiveCallIn");
			byte* params = (byte*)malloc(1);
			*params = CallInIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnEndConstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.OnEndConstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnStartConstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.OnStartConstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetLaserStartAndEnd(Vector& StartLocation, Vector& EndLocation, Vector& EndLocationNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.GetLaserStartAndEnd");
			byte* params = (byte*)malloc(40);
			*(Vector*)params = StartLocation;
			*(Vector*)(params + 12) = EndLocation;
			*(Vector*)(params + 24) = EndLocationNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			StartLocation = *(Vector*)params;
			EndLocation = *(Vector*)(params + 12);
			EndLocationNormal = *(Vector*)(params + 24);
			auto returnVal = *(bool*)(params + 36);
			free(params);
			return returnVal;
		}
		void KillLaserEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.KillLaserEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnLaserEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.SpawnLaserEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateLaserEffect(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.UpdateLaserEffect");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CallInConfirmed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.CallInConfirmed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerPerformCallIn(Vector EndLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.ServerPerformCallIn");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = EndLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateTarget(bool hasHitSomething, Vector End, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.UpdateTarget");
			byte* params = (byte*)malloc(20);
			*(bool*)params = hasHitSomething;
			*(Vector*)(params + 4) = End;
			*(float*)(params + 16) = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Actor* GetTraceOwner()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.GetTraceOwner");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)params;
			free(params);
			return returnVal;
		}
		int GetAmmoCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.GetAmmoCount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void UpdateCreditMaterial()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.UpdateCreditMaterial");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayWeaponEquip()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.PlayWeaponEquip");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateCallInMaterial()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.UpdateCallInMaterial");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateWeaponMICs()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LaserTargeter.UpdateWeaponMICs");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
