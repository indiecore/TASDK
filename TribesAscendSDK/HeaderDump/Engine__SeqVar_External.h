#pragma once
#include "Engine__SequenceVariable.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqVar_External." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqVar_External." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqVar_External : public SequenceVariable
	{
	public:
		ADD_VAR(::StrProperty, VariableLabel, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, ExpectedType)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
