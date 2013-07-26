#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIDataStore_StringAliasMap.UIMenuInputMap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIMenuInputMap
	{
	public:
		ADD_VAR(::StrProperty, MappedText, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, Set, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, FieldName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
