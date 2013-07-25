#pragma once
#include "Engine.SeqAct_SetSequenceVariable.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_SetBool." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_SetBool : public SeqAct_SetSequenceVariable
	{
	public:
		ADD_VAR(::BoolProperty, DefaultValue, 0x1)
	};
}
#undef ADD_VAR
