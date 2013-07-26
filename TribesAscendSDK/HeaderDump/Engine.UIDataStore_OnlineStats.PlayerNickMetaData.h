#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIDataStore_OnlineStats.PlayerNickMetaData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PlayerNickMetaData
	{
	public:
		ADD_VAR(::StrProperty, PlayerNickColumnName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, PlayerNickName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
