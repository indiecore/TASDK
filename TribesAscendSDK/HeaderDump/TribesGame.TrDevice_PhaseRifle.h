#pragma once
#include "TribesGame.TrDevice.h"
#include "Engine.Actor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrDevice_PhaseRifle : public TrDevice
	{
	public:
		ADD_STRUCT(float, m_MaxEnergyConsumed, 2152)
		ADD_STRUCT(float, m_DamagePerEnergy, 2148)
		void InstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_PhaseRifle.InstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float ModifyInstantHitDamage(byte FiringMode, Actor::ImpactInfo Impact, float Damage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_PhaseRifle.ModifyInstantHitDamage");
			byte params[89] = { NULL };
			params[0] = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(float*)&params[84] = Damage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[88];
		}
	};
}
#undef ADD_STRUCT
