#pragma once
#include "TribesGame.TrDevice_Pack.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrDevice_Blink : public TrDevice_Pack
	{
	public:
		ADD_STRUCT(float, m_fMinZImpulse, 2180)
		ADD_STRUCT(float, m_fPowerPoolCost, 2184)
		ADD_STRUCT(float, m_fSpeedCapThresholdStart, 2200)
		ADD_STRUCT(float, m_fSpeedCapPct, 2204)
		ADD_STRUCT(float, m_fSpeedCapThreshold, 2196)
		ADD_STRUCT(float, m_fLastActivationTimestamp, 2192)
		ADD_STRUCT(float, m_fCooldownTime, 2188)
		ADD_STRUCT(Object::Vector, m_vBlinkImpulse, 2168)
		Object::Vector GetBlinkImpulse()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Blink.GetBlinkImpulse");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		void ToggleActivate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Blink.ToggleActivate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnBlink(float PercentEffectiveness)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Blink.OnBlink");
			byte params[4] = { NULL };
			*(float*)&params[0] = PercentEffectiveness;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
