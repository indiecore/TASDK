#pragma once
#include "Engine__UIDataStore_Remote.h"
#include "Engine__OnlineStatsRead.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataStore_OnlineStats." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataStore_OnlineStats." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDataStore_OnlineStats." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDataStore_OnlineStats : public UIDataStore_Remote
	{
	public:
		ADD_VAR(::ByteProperty, CurrentReadType, 0xFFFFFFFF)
		ADD_OBJECT(OnlineStatsRead, StatsRead)
		ADD_VAR(::NameProperty, TotalRowsName, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIDataStore_OnlineStats.RankMetaData' for the property named 'RankNameMetaData'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIDataStore_OnlineStats.PlayerNickMetaData' for the property named 'PlayerNickData'!
		ADD_VAR(::NameProperty, StatsReadName, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementCellProvider'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementProvider'!
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'SetStatsReadInfo'
		// Here lies the not-yet-implemented method 'RefreshStats'
		// Here lies the not-yet-implemented method 'ShowGamercard'
		// Here lies the not-yet-implemented method 'OnReadComplete'
		// Here lies the not-yet-implemented method 'SortResultsByRank'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
