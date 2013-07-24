#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKUIDataStore_StringAliasMap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataStore_StringAliasMap : public UIDataStore_StringAliasMap
	{
	public:
		ADD_VAR(::IntProperty, FakePlatform, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
