#pragma once
#include "Core.DistributionFloat.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DistributionFloatConstant." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DistributionFloatConstant : public DistributionFloat
	{
	public:
		ADD_VAR(::FloatProperty, Constant, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
