#pragma once
#include "Engine.ParticleModuleLocationBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleLocationPrimitiveBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleLocationPrimitiveBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleLocationPrimitiveBase : public ParticleModuleLocationBase
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'StartLocation'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'VelocityScale'!
		ADD_VAR(::BoolProperty, Velocity, 0x80)
		ADD_VAR(::BoolProperty, SurfaceOnly, 0x40)
		ADD_VAR(::BoolProperty, Negative_Z, 0x20)
		ADD_VAR(::BoolProperty, Negative_Y, 0x10)
		ADD_VAR(::BoolProperty, Negative_X, 0x8)
		ADD_VAR(::BoolProperty, Positive_Z, 0x4)
		ADD_VAR(::BoolProperty, Positive_Y, 0x2)
		ADD_VAR(::BoolProperty, Positive_X, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
