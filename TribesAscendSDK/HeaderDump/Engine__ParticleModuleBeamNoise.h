#pragma once
#include "Engine__ParticleModuleBeamBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleBeamNoise." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleBeamNoise." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleBeamNoise : public ParticleModuleBeamBase
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'NoiseScale'!
		ADD_VAR(::FloatProperty, FrequencyDistance, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NoiseTessellation, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'NoiseTangentStrength'!
		ADD_VAR(::FloatProperty, NoiseTension, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NoiseLockTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NoiseLockRadius, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'NoiseSpeed'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'NoiseRangeScale'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'NoiseRange'!
		ADD_VAR(::IntProperty, Frequency_LowRange, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Frequency, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bApplyNoiseScale, 0x80)
		ADD_VAR(::BoolProperty, bTargetNoise, 0x40)
		ADD_VAR(::BoolProperty, bUseNoiseTangents, 0x20)
		ADD_VAR(::BoolProperty, bOscillate, 0x10)
		ADD_VAR(::BoolProperty, bNoiseLock, 0x8)
		ADD_VAR(::BoolProperty, bSmooth, 0x4)
		ADD_VAR(::BoolProperty, bNRScaleEmitterTime, 0x2)
		ADD_VAR(::BoolProperty, bLowFreq_Enabled, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
