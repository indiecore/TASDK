#pragma once
#include "Engine.SequenceCondition.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqCond_Increment." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqCond_Increment : public SequenceCondition
	{
	public:
		ADD_VAR(::IntProperty, ValueB, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ValueA, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IncrementAmount, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
