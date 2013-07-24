#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_CustomMatch." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_CustomMatch : public GFxTrPage
	{
	public:
		ADD_VAR(::IntProperty, SERVERS_PER_PAGE, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, QueueJoinName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PopupNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ServerIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForJoinPopup, 0x10)
		ADD_VAR(::BoolProperty, bFilterPopup, 0x8)
		ADD_VAR(::BoolProperty, bRefresh, 0x4)
		ADD_VAR(::BoolProperty, bFilterEmpty, 0x2)
		ADD_VAR(::BoolProperty, bFilterFull, 0x1)
		ADD_VAR(::StrProperty, ServerNameFilter, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MapNameFilter, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FilterServerNameNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FilterOwnerNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FilterFullNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FilterEmptyNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FilterMapNameNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FilterRegionNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RefreshNum, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
