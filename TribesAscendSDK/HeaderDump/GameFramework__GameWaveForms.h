#pragma once
#include "Core__Object.h"
#include "Engine__ForceFeedbackWaveform.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameWaveForms." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameWaveForms : public Object
	{
	public:
		ADD_OBJECT(ForceFeedbackWaveform, CameraShakeBigShort)
		ADD_OBJECT(ForceFeedbackWaveform, CameraShakeBigLong)
		ADD_OBJECT(ForceFeedbackWaveform, CameraShakeMediumShort)
		ADD_OBJECT(ForceFeedbackWaveform, CameraShakeMediumLong)
	};
}
#undef ADD_OBJECT
