#pragma once
#include "Engine.SequenceOp.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Sequence.ActivateOp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Sequence.ActivateOp." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ActivateOp
	{
	public:
		ADD_VAR(::FloatProperty, RemainingDelay, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, InputIdx, 0xFFFFFFFF)
		ADD_OBJECT(SequenceOp, Op)
		ADD_OBJECT(SequenceOp, ActivatorOp)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
