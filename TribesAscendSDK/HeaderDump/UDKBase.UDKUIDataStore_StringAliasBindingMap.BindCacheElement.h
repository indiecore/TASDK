#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKUIDataStore_StringAliasBindingMap.BindCacheElement." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class BindCacheElement
	{
	public:
		ADD_VAR(::IntProperty, FieldIndex, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MappingString, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, KeyName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
