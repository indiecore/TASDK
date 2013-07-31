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
		struct RankMetaData
		{
		public:
			ADD_STRUCT(ScriptString*, RankColumnName, 8)
			ADD_STRUCT(ScriptName, RankName, 0)
		};
		struct PlayerNickMetaData
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28847);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetStatsReadInfo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28849);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool RefreshStats(byte ControllerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28850);
			byte params[5] = { NULL };
			*params = ControllerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShowGamercard(byte ConrollerIndex, int ListIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28856);
			byte params[9] = { NULL };
			*params = ConrollerIndex;
			*(int*)&params[4] = ListIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void OnReadComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28863);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SortResultsByRank()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28865);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
