#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTPlayerReplicationInfo.IntStat." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class IntStat
	{
	public:
		ADD_VAR(::IntProperty, StatValue, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, StatName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
