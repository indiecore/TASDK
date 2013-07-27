#pragma once
#include "TribesGame.TrDevice.h"
#include "Engine.Actor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrDevice_SniperRifle : public TrDevice
	{
	public:
		ADD_STRUCT(float, m_fDivCoeff, 2164)
		ADD_STRUCT(float, m_fMultCoeff, 2160)
		ADD_STRUCT(float, r_fAimChargeTime, 2156)
		ADD_STRUCT(float, m_fAimChargeDeltaTime, 2152)
		ADD_STRUCT(float, m_fMaxAimedDamage, 2148)
		void OnSwitchToWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86161);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchAwayFromWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86162);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InstantFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86163);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float ModifyInstantHitDamage(byte FiringMode, Actor::ImpactInfo Impact, float Damage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86164);
			byte params[89] = { NULL };
			*params = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(float*)&params[84] = Damage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[88];
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86171);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float CalcHUDAimChargePercent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86174);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86176);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayScopeRechargeSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86181);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopScopeRechargeSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86182);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
