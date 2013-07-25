#pragma once
#include "Engine__SequenceCondition.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqCond_CompareBool." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqCond_CompareBool : public SequenceCondition
	{
	public:
		ADD_VAR(::BoolProperty, bResult, 0x1)
	};
}
#undef ADD_VAR
