#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.ForceFeedbackWaveform.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ForceFeedbackManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ForceFeedbackManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ForceFeedbackManager : public Object
	{
	public:
		ADD_VAR(::FloatProperty, ScaleAllWaveformsBy, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAllowsForceFeedback, 0x1)
		ADD_OBJECT(Actor, WaveformInstigator)
		ADD_VAR(::FloatProperty, ElapsedTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrentSample, 0xFFFFFFFF)
		ADD_OBJECT(ForceFeedbackWaveform, FFWaveform)
		ADD_VAR(::BoolProperty, bIsPaused, 0x2)
		void PlayForceFeedbackWaveform(class ForceFeedbackWaveform* WaveForm, class Actor* WaveInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFeedbackManager.PlayForceFeedbackWaveform");
			byte* params = (byte*)malloc(8);
			*(class ForceFeedbackWaveform**)params = WaveForm;
			*(class Actor**)(params + 4) = WaveInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopForceFeedbackWaveform(class ForceFeedbackWaveform* WaveForm)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFeedbackManager.StopForceFeedbackWaveform");
			byte* params = (byte*)malloc(4);
			*(class ForceFeedbackWaveform**)params = WaveForm;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PauseWaveform(bool bPause)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFeedbackManager.PauseWaveform");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bPause;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
