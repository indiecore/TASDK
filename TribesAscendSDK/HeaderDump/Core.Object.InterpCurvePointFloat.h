#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.InterpCurvePointFloat." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpCurvePointFloat
	{
	public:
		ADD_VAR(::FloatProperty, InVal, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OutVal, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ArriveTangent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LeaveTangent, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, InterpMode, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
