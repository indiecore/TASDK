#pragma once
#include "Engine__DistributionVectorConstant.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DistributionVectorParameterBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DistributionVectorParameterBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DistributionVectorParameterBase : public DistributionVectorConstant
	{
	public:
		ADD_VAR(::ByteProperty, ParamModes, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, MaxOutput, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, MinOutput, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, MaxInput, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, MinInput, 0xFFFFFFFF
		ADD_VAR(::NameProperty, ParameterName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
