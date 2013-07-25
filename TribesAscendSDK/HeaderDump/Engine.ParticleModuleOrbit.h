#pragma once
#include "Engine.ParticleModuleOrbitBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleOrbit." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleOrbit." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleOrbit : public ParticleModuleOrbitBase
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Engine.ParticleModuleOrbit.OrbitOptions' for the property named 'RotationRateOptions'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'RotationRateAmount'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.ParticleModuleOrbit.OrbitOptions' for the property named 'RotationOptions'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'RotationAmount'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.ParticleModuleOrbit.OrbitOptions' for the property named 'OffsetOptions'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'OffsetAmount'!
		ADD_VAR(::ByteProperty, ChainMode, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
