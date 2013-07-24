#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ApexClothingAsset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ApexClothingAsset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ApexClothingAsset." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ApexClothingAsset : public ApexAsset
	{
	public:
		ADD_VAR(::FloatProperty, LodWeightsBenefitsBias, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LodWeightsBias, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LodWeightsDistanceWeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LodWeightsMaxDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ContinuousDistanceThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ContinuousRotationThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDistanceBlendTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, UVChannelForTangentUpdate, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRecomputeNormals, 0x8)
		ADD_VAR(::BoolProperty, bSlowStart, 0x4)
		ADD_VAR(::BoolProperty, bFallbackSkinning, 0x2)
		ADD_VAR(::BoolProperty, bUseHardwareCloth, 0x1)
		ADD_OBJECT(ApexGenericAsset, ApexClothingLibrary)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'MApexAsset'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
