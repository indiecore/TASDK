#pragma once
#include "Engine__SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_SetMatInstScalarParam." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_SetMatInstScalarParam." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_SetMatInstScalarParam : public SequenceAction
	{
	public:
		ADD_VAR(::FloatProperty, ScalarValue, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ParamName, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, MatInst)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
