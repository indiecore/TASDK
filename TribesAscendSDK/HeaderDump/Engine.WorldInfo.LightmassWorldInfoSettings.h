#pragma once
#include "Core.Object.Color.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " WorldInfo.LightmassWorldInfoSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty WorldInfo.LightmassWorldInfoSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LightmassWorldInfoSettings
	{
	public:
		ADD_VAR(::FloatProperty, StaticLightingLevelScale, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumIndirectLightingBounces, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, EnvironmentColor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EnvironmentIntensity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EmissiveBoost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DiffuseBoost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpecularBoost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, IndirectNormalInfluenceBoost, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUseNormalMapsForSimpleLightMaps, 0x1)
		ADD_VAR(::BoolProperty, bUseAmbientOcclusion, 0x2)
		ADD_VAR(::BoolProperty, bEnableImageReflectionShadowing, 0x4)
		ADD_VAR(::FloatProperty, DirectIlluminationOcclusionFraction, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, IndirectIlluminationOcclusionFraction, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OcclusionExponent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FullyOccludedSamplesFraction, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxOcclusionDistance, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bVisualizeMaterialDiffuse, 0x1)
		ADD_VAR(::BoolProperty, bVisualizeAmbientOcclusion, 0x2)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
