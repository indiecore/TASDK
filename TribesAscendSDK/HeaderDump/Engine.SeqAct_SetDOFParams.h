#pragma once
#include "Engine.SeqAct_Latent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_SetDOFParams." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SeqAct_SetDOFParams." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_SetDOFParams : public SeqAct_Latent
	{
	public:
		ADD_STRUCT(::VectorProperty, OldFocusPosition, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldFocusDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldFocusInnerRadius, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'OldModulateBlurColor'!
		ADD_VAR(::FloatProperty, OldMaxFarBlurAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldMinBlurAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldMaxNearBlurAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldBlurKernelSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldFalloffExponent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InterpolateElapsed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InterpolateSeconds, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FocusPosition, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FocusDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FocusInnerRadius, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'ModulateBlurColor'!
		ADD_VAR(::FloatProperty, MaxFarBlurAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinBlurAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxNearBlurAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlurKernelSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FalloffExponent, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
