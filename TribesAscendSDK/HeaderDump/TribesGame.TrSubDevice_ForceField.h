#pragma once
#include "TribesGame.TrSubDevice.h"
#include "Engine.Actor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrSubDevice_ForceField : public TrSubDevice
	{
	public:
		ADD_STRUCT(float, m_MinSpeed, 2160)
		ADD_STRUCT(float, m_MaxSpeed, 2156)
		ADD_STRUCT(float, m_MinDamage, 2152)
		ADD_STRUCT(float, m_MaxDamage, 2148)
		void InstantFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113041);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float ModifyInstantHitDamage(byte FiringMode, Actor::ImpactInfo Impact, float Damage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113042);
			byte params[89] = { NULL };
			*params = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(float*)&params[84] = Damage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[88];
		}
	};
}
#undef ADD_STRUCT
