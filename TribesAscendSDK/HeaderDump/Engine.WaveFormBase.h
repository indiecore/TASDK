#pragma once
#include "Core.Object.h"
#include "Engine.ForceFeedbackWaveform.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class WaveFormBase : public Object
	{
	public:
		ADD_OBJECT(ForceFeedbackWaveform, TheWaveForm, 60)
	};
}
#undef ADD_OBJECT
