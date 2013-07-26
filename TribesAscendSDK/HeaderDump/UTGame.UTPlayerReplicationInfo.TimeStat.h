#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTPlayerReplicationInfo.TimeStat." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TimeStat
	{
	public:
		ADD_VAR(::FloatProperty, CurrentStart, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TotalTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, StatName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
