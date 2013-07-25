#pragma once
#include "Engine__PostProcessEffect.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DOFEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DOFEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DOFEffect : public PostProcessEffect
	{
	public:
		ADD_VAR(::FloatProperty, FalloffExponent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlurKernelSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxNearBlurAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinBlurAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxFarBlurAmount, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'ModulateBlurColor'!
		ADD_VAR(::ByteProperty, FocusType, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FocusInnerRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FocusDistance, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FocusPosition, 0xFFFFFFFF
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
