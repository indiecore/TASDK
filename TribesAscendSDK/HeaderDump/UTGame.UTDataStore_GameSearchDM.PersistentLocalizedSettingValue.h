#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTDataStore_GameSearchDM.PersistentLocalizedSettingValue." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PersistentLocalizedSettingValue
	{
	public:
		ADD_VAR(::IntProperty, ValueId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SettingId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
