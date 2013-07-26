#pragma once
#include "Core.Object.Color.h"
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " InterpCurveEdSetup.CurveEdEntry." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty InterpCurveEdSetup.CurveEdEntry." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty InterpCurveEdSetup.CurveEdEntry." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CurveEdEntry
	{
	public:
		ADD_VAR(::FloatProperty, ClampHigh, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClampLow, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bClamp, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bFloatingPointColorCurve, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bColorCurve, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bHideCurve, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CurveName, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, CurveColor, 0xFFFFFFFF)
		ADD_OBJECT(Object, CurveObject)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
