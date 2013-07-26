#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameEngine.URL." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class URL
	{
	public:
		ADD_VAR(::StrProperty, Protocol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Host, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Port, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Map, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Portal, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Valid, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
