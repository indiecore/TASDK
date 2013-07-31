#pragma once
#include "Engine.SequenceAction.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_AssignController : public SequenceAction
	{
	public:
		ADD_OBJECT(ScriptClass, ControllerClass, 232)
	};
}
#undef ADD_OBJECT
