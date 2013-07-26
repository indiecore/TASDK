#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameplayEvents.GameplayEventsHeader." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameplayEventsHeader
	{
	public:
		ADD_VAR(::IntProperty, Flags, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FilterClass, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FileSize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TotalStreamSize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FooterOffset, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AggregateOffset, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StreamOffset, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatsWriterVersion, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EngineVersion, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
