#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTDataStore_GameSearchDM.GameSearchSettingsStorage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameSearchSettingsStorage
	{
	public:
		ADD_VAR(::NameProperty, GameSearchName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
