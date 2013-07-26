#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxTrMenuMoviePlayer.QueueUIData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class QueueUIData
	{
	public:
		ADD_VAR(::IntProperty, LevelMax, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LevelMin, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SortOrder, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, contentIndex, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RibbonText, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ribbonType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShowRibbon, 0x2)
		ADD_VAR(::BoolProperty, bAvailable, 0x1)
		ADD_VAR(::StrProperty, Subtitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Title, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, queueId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
