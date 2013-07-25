#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LightmassLevelSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LightmassLevelSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LightmassLevelSettings : public Object
	{
	public:
		ADD_VAR(::FloatProperty, MaxOcclusionDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FullyOccludedSamplesFraction, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OcclusionExponent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, IndirectIlluminationOcclusionFraction, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DirectIlluminationOcclusionFraction, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bVisualizeAmbientOcclusion, 0x2)
		ADD_VAR(::BoolProperty, bUseAmbientOcclusion, 0x1)
		ADD_VAR(::FloatProperty, SpecularBoost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DiffuseBoost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EmissiveBoost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EnvironmentIntensity, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'EnvironmentColor'!
		ADD_VAR(::IntProperty, NumIndirectLightingBounces, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
