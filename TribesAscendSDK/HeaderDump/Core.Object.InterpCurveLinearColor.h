#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.InterpCurveLinearColor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpCurveLinearColor
	{
	public:
		ADD_VAR(::ByteProperty, InterpMethod, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
