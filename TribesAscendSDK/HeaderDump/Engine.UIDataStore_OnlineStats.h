#pragma once
#include "Engine.UIDataStore_Remote.h"
#include "Engine.OnlineStatsRead.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UIDataStore_OnlineStats : public UIDataStore_Remote
	{
	public:
		enum EStatsFetchType : byte
		{
			SFT_Player = 0,
			SFT_CenteredOnPlayer = 1,
			SFT_Friends = 2,
			SFT_TopRankings = 3,
			SFT_MAX = 4,
		};
		class RankMetaData
		{
		public:
			ADD_STRUCT(ScriptString*, RankColumnName, 8)
			ADD_STRUCT(ScriptName, RankName, 0)
		};
		class PlayerNickMetaData
		{
		public:
			ADD_STRUCT(ScriptString*, PlayerNickColumnName, 8)
			ADD_STRUCT(ScriptName, PlayerNickName, 0)
		};
		ADD_STRUCT(ScriptArray<ScriptClass*>, StatsReadClasses, 128)
		ADD_STRUCT(ScriptArray<class OnlineStatsRead*>, StatsReadObjects, 196)
		ADD_STRUCT(UIDataStore_OnlineStats::EStatsFetchType, CurrentReadType, 212)
		ADD_OBJECT(OnlineStatsRead, StatsRead, 208)
		ADD_STRUCT(ScriptName, TotalRowsName, 188)
		ADD_STRUCT(UIDataStore_OnlineStats::RankMetaData, RankNameMetaData, 168)
		ADD_STRUCT(UIDataStore_OnlineStats::PlayerNickMetaData, PlayerNickData, 148)
		ADD_STRUCT(ScriptName, StatsReadName, 140)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementCellProvider, 124)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementProvider, 120)
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
			byte params[5] = { NULL };
			params[0] = ControllerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShowGamercard(byte ConrollerIndex, int ListIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineStats.ShowGamercard");
			byte params[9] = { NULL };
			params[0] = ConrollerIndex;
			*(int*)&params[4] = ListIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void OnReadComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineStats.OnReadComplete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SortResultsByRank()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineStats.SortResultsByRank");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
