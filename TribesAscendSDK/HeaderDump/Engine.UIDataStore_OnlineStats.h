#pragma once
#include "Engine.UIDataStore_Remote.h"
#include "Engine.OnlineStatsRead.h"
#include "Engine.UIDataStore_OnlineStats.RankMetaData.h"
#include "Engine.UIDataStore_OnlineStats.PlayerNickMetaData.h"
#include "Core.Object.Pointer.h"
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
		ADD_STRUCT(::NonArithmeticProperty<RankMetaData>, RankNameMetaData, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<PlayerNickMetaData>, PlayerNickData, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, StatsReadName, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_IUIListElementCellProvider, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_IUIListElementProvider, 0xFFFFFFFF)
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineStats.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetStatsReadInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineStats.SetStatsReadInfo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool RefreshStats(byte ControllerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineStats.RefreshStats");
			byte* params = (byte*)malloc(5);
			*params = ControllerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ShowGamercard(byte ConrollerIndex, int ListIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineStats.ShowGamercard");
			byte* params = (byte*)malloc(9);
			*params = ConrollerIndex;
			*(int*)(params + 4) = ListIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void OnReadComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineStats.OnReadComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SortResultsByRank()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineStats.SortResultsByRank");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
