#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlineStatsRead." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineStatsRead : public OnlineStats
	{
	public:
		ADD_VAR(::IntProperty, TitleId, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ViewName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TotalRowsInView, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SortColumnId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ViewId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
