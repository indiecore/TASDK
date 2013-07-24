#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DistributionFloatParameterBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DistributionFloatParameterBase : public DistributionFloatConstant
	{
	public:
		ADD_VAR(::ByteProperty, ParamMode, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ParameterName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxOutput, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinOutput, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxInput, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinInput, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
