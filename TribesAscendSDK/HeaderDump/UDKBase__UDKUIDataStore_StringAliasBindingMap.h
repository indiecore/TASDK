#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKUIDataStore_StringAliasBindingMap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKUIDataStore_StringAliasBindingMap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataStore_StringAliasBindingMap : public UIDataStore_StringAliasMap
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'CommandToBindNames'!
		ADD_VAR(::IntProperty, FakePlatform, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
