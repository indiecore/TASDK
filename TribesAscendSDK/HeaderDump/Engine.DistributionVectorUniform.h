#pragma once
#include "Core.Object.Vector.h"
#include "Core.DistributionVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DistributionVectorUniform." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DistributionVectorUniform." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DistributionVectorUniform : public DistributionVector
	{
	public:
		ADD_VAR(::ByteProperty, MirrorFlags, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LockedAxes, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUseExtremes, 0x2)
		ADD_VAR(::BoolProperty, bLockAxes, 0x1)
		ADD_STRUCT(::VectorProperty, Min, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Max, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
