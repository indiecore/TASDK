#pragma once
#include "TribesGame.TrDevice_Pack.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_Blink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDevice_Blink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDevice_Blink : public TrDevice_Pack
	{
	public:
		ADD_VAR(::FloatProperty, m_fMinZImpulse, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPowerPoolCost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSpeedCapThresholdStart, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSpeedCapPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSpeedCapThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastActivationTimestamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCooldownTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vBlinkImpulse, 0xFFFFFFFF)
		Vector GetBlinkImpulse()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Blink.GetBlinkImpulse");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		void ToggleActivate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Blink.ToggleActivate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnBlink(float PercentEffectiveness)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Blink.OnBlink");
			byte* params = (byte*)malloc(4);
			*(float*)params = PercentEffectiveness;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
