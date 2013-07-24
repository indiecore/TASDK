#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_CastToInt." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_CastToInt : public SeqAct_SetSequenceVariable
	{
	public:
		ADD_VAR(::IntProperty, IntResult, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Value, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bTruncate, 0x1)
	};
}
#undef ADD_VAR
