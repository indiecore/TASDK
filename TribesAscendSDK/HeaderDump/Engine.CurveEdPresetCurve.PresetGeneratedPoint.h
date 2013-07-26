#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " CurveEdPresetCurve.PresetGeneratedPoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PresetGeneratedPoint
	{
	public:
		ADD_VAR(::ByteProperty, IntepMode, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TangentOut, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TangentIn, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, TangentsValid, 0x1)
		ADD_VAR(::FloatProperty, KeyOut, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, KeyIn, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
