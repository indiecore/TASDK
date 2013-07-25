#pragma once
#include "Engine__PrimitiveComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SplineComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SplineComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SplineComponent : public PrimitiveComponent
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveFloat' for the property named 'SplineReparamTable'!
		ADD_VAR(::BoolProperty, bSplineDisabled, 0x1)
		ADD_VAR(::FloatProperty, SplineArrowSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SplineDrawRes, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'SplineColor'!
		ADD_VAR(::FloatProperty, SplineCurviness, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveVector' for the property named 'SplineInfo'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
