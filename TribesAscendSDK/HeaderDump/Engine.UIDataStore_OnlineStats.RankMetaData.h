#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIDataStore_OnlineStats.RankMetaData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RankMetaData
	{
	public:
		ADD_VAR(::StrProperty, RankColumnName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, RankName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
