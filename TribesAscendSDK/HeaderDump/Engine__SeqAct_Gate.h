#pragma once
#include "Engine__SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_Gate." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_Gate : public SequenceAction
	{
	public:
		ADD_VAR(::IntProperty, CurrentCloseCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AutoCloseCount, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOpen, 0x1)
	};
}
#undef ADD_VAR
