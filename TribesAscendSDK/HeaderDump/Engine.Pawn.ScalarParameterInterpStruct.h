#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Pawn.ScalarParameterInterpStruct." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ScalarParameterInterpStruct
	{
	public:
		ADD_VAR(::FloatProperty, WarmupTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InterpTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ParameterValue, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ParameterName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
