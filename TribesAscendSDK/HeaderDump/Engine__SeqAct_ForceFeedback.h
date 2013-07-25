#pragma once
#include "Engine__SequenceAction.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_ForceFeedback." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_ForceFeedback : public SequenceAction
	{
	public:
		ADD_OBJECT(ForceFeedbackWaveform, FFWaveform)
	};
}
#undef ADD_OBJECT
