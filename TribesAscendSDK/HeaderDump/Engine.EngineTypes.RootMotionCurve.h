#pragma once
#include "Core.Object.InterpCurveVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " EngineTypes.RootMotionCurve." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty EngineTypes.RootMotionCurve." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RootMotionCurve
	{
	public:
		ADD_VAR(::FloatProperty, MaxCurveTime, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<InterpCurveVector>, Curve, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
