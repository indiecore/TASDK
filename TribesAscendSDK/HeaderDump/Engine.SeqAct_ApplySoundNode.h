#pragma once
#include "Engine.SoundCue.h"
#include "Engine.SequenceAction.h"
#include "Engine.SoundNode.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_ApplySoundNode : public SequenceAction
	{
	public:
		ADD_OBJECT(SoundNode, ApplyNode, 236)
		ADD_OBJECT(SoundCue, PlaySound, 232)
	};
}
#undef ADD_OBJECT
