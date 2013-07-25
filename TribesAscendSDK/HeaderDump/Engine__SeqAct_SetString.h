#pragma once
#include "Engine__SeqAct_SetSequenceVariable.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_SetString." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_SetString : public SeqAct_SetSequenceVariable
	{
	public:
		ADD_VAR(::StrProperty, Value, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Target, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
