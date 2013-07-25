#pragma once
#include "Engine.SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_Switch." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_Switch : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bAutoDisableLinks, 0x2)
		ADD_VAR(::BoolProperty, bLooping, 0x1)
		ADD_VAR(::IntProperty, IncrementAmount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LinkCount, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
