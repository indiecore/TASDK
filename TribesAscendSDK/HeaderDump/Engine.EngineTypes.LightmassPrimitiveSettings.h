#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " EngineTypes.LightmassPrimitiveSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LightmassPrimitiveSettings
	{
	public:
		ADD_VAR(::FloatProperty, FullyOccludedSamplesFraction, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpecularBoost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DiffuseBoost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EmissiveBoost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EmissiveLightExplicitInfluenceRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EmissiveLightFalloffExponent, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUseEmissiveForStaticLighting, 0x4)
		ADD_VAR(::BoolProperty, bShadowIndirectOnly, 0x2)
		ADD_VAR(::BoolProperty, bUseTwoSidedLighting, 0x1)
	};
}
#undef ADD_VAR
