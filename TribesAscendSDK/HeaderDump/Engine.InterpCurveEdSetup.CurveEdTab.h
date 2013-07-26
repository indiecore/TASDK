#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " InterpCurveEdSetup.CurveEdTab." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CurveEdTab
	{
	public:
		ADD_VAR(::FloatProperty, ViewEndOutput, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewStartOutput, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewEndInput, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewStartInput, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TabName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
