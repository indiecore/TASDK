#pragma once
#include "TribesGame.TrDevice.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_SniperRifle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDevice_SniperRifle : public TrDevice
	{
	public:
		ADD_VAR(::FloatProperty, m_fDivCoeff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMultCoeff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fAimChargeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAimChargeDeltaTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxAimedDamage, 0xFFFFFFFF)
		void OnSwitchToWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SniperRifle.OnSwitchToWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchAwayFromWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SniperRifle.OnSwitchAwayFromWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SniperRifle.InstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float ModifyInstantHitDamage(byte FiringMode, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* Impact, float Damage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SniperRifle.ModifyInstantHitDamage");
			byte* params = (byte*)malloc(89);
			*params = FiringMode;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 4) = Impact;
			*(float*)(params + 84) = Damage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 88);
			free(params);
			return returnVal;
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SniperRifle.StartFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float CalcHUDAimChargePercent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SniperRifle.CalcHUDAimChargePercent");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SniperRifle.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayScopeRechargeSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SniperRifle.PlayScopeRechargeSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopScopeRechargeSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SniperRifle.StopScopeRechargeSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
