#pragma once
#include "Core.Object.Quat.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.InterpCurvePointQuat." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Object.InterpCurvePointQuat." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpCurvePointQuat
	{
	public:
		ADD_VAR(::FloatProperty, InVal, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Quat>, OutVal, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Quat>, ArriveTangent, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Quat>, LeaveTangent, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, InterpMode, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
