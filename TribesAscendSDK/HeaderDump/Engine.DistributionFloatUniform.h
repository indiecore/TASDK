#pragma once
#include "Core.DistributionFloat.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DistributionFloatUniform." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DistributionFloatUniform : public DistributionFloat
	{
	public:
		ADD_VAR(::FloatProperty, Max, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Min, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
