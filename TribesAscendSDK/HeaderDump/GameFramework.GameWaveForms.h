#pragma once
#include "Core.Object.h"
#include "Engine.ForceFeedbackWaveform.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GameWaveForms : public Object
	{
	public:
		ADD_OBJECT(ForceFeedbackWaveform, CameraShakeBigShort, 68)
		ADD_OBJECT(ForceFeedbackWaveform, CameraShakeBigLong, 72)
		ADD_OBJECT(ForceFeedbackWaveform, CameraShakeMediumShort, 60)
		ADD_OBJECT(ForceFeedbackWaveform, CameraShakeMediumLong, 64)
	};
}
#undef ADD_OBJECT
