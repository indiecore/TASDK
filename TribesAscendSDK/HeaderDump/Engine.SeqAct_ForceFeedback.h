#pragma once
#include "Engine.SequenceAction.h"
#include "Engine.ForceFeedbackWaveform.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_ForceFeedback : public SequenceAction
	{
	public:
		ADD_OBJECT(ForceFeedbackWaveform, FFWaveform, 232)
		ADD_OBJECT(ScriptClass, PredefinedWaveForm, 236)
	};
}
#undef ADD_OBJECT
