#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.Double." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Double
	{
	public:
		ADD_VAR(::IntProperty, A, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, B, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
