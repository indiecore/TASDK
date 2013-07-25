#pragma once
#include "Core__Object.h"
#include "Engine__Actor.h"
#include "Engine__ForceFeedbackWaveform.h"
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
		// Here lies the not-yet-implemented method 'PlayForceFeedbackWaveform'
		// Here lies the not-yet-implemented method 'StopForceFeedbackWaveform'
		// Here lies the not-yet-implemented method 'PauseWaveform'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
