#pragma once
#include "Core__DistributionVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DistributionVectorUniformCurve." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DistributionVectorUniformCurve." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DistributionVectorUniformCurve : public DistributionVector
	{
	public:
		ADD_VAR(::ByteProperty, MirrorFlags, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LockedAxes, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUseExtremes, 0x4)
		ADD_VAR(::BoolProperty, bLockAxes2, 0x2)
		ADD_VAR(::BoolProperty, bLockAxes1, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveTwoVectors' for the property named 'ConstantCurve'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
