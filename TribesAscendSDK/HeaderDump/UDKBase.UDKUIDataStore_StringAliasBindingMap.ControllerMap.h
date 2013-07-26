#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKUIDataStore_StringAliasBindingMap.ControllerMap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ControllerMap
	{
	public:
		ADD_VAR(::StrProperty, PS3Mapping, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, XBoxMapping, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, KeyName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
