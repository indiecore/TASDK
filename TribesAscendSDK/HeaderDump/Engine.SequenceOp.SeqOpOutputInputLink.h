#pragma once
#include "Engine.SequenceOp.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SequenceOp.SeqOpOutputInputLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty SequenceOp.SeqOpOutputInputLink." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqOpOutputInputLink
	{
	public:
		ADD_VAR(::IntProperty, InputLinkIdx, 0xFFFFFFFF)
		ADD_OBJECT(SequenceOp, LinkedOp)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
