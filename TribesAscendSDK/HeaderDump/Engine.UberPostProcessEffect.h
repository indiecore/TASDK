#pragma once
#include "Engine.DOFBloomMotionBlurEffect.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UberPostProcessEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UberPostProcessEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UberPostProcessEffect : public DOFBloomMotionBlurEffect
	{
	public:
		ADD_VAR(::FloatProperty, SceneHDRTonemapperScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BloomSizeScaleLarge, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BloomSizeScaleMedium, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BloomSizeScaleSmall, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BloomWeightLarge, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BloomWeightMedium, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BloomWeightSmall, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SceneImageGrainScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableHDRTonemapper, 0x2)
		ADD_VAR(::BoolProperty, bEnableImageGrain, 0x1)
		ADD_VAR(::FloatProperty, MotionBlurSoftEdgeKernelSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TonemapperScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TonemapperToeFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TonemapperRange, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, TonemapperType, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, SceneShadows, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, SceneColorize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SceneDesaturation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, SceneMidTones, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, SceneHighLights, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
