#pragma once
#include "Engine.DOFEffect.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DOFAndBloomEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DOFAndBloomEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DOFAndBloomEffect : public DOFEffect
	{
	public:
		ADD_VAR(::BoolProperty, bEnableDepthOfFieldHQ, 0x4)
		ADD_VAR(::BoolProperty, bEnableReferenceDOF, 0x2)
		ADD_VAR(::BoolProperty, bEnableSeparateBloom, 0x1)
		ADD_VAR(::FloatProperty, BlurBloomKernelSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SceneMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BloomScreenBlendThreshold, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'BloomTint'!
		ADD_VAR(::FloatProperty, BloomThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BloomScale, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
