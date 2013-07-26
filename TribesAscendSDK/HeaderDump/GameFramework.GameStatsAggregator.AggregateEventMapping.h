#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameStatsAggregator.AggregateEventMapping." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AggregateEventMapping
	{
	public:
		ADD_VAR(::IntProperty, TargetAggregateID, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AggregateID, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EventID, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
