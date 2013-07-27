#pragma once
#include "Engine.OnlineStats.h"
#include "Engine.OnlineSubsystem.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class OnlineStatsRead : public OnlineStats
	{
	public:
		struct ColumnMetaData
		{
		public:
			ADD_STRUCT(ScriptString*, ColumnName, 12)
			ADD_STRUCT(ScriptName, Name, 4)
			ADD_STRUCT(int, Id, 0)
		};
		struct OnlineStatsColumn
		{
		public:
			ADD_STRUCT(Settings::SettingsData, StatValue, 4)
			ADD_STRUCT(int, ColumnNo, 0)
		};
		struct OnlineStatsRow
		{
		public:
			ADD_STRUCT(ScriptArray<OnlineStatsRead::OnlineStatsColumn>, Columns, 32)
			ADD_STRUCT(ScriptString*, NickName, 20)
			ADD_STRUCT(Settings::SettingsData, Rank, 8)
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, PlayerID, 0)
		};
		ADD_STRUCT(ScriptArray<int>, ColumnIds, 80)
		ADD_STRUCT(ScriptArray<OnlineStatsRead::OnlineStatsRow>, Rows, 96)
		ADD_STRUCT(ScriptArray<OnlineStatsRead::ColumnMetaData>, ColumnMappings, 108)
		ADD_STRUCT(int, TitleId, 132)
		ADD_STRUCT(ScriptString*, ViewName, 120)
		ADD_STRUCT(int, TotalRowsInView, 92)
		ADD_STRUCT(int, SortColumnId, 76)
		ADD_STRUCT(int, ViewId, 72)
		void OnReadComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22839);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetIntStatValueForPlayer(OnlineSubsystem::UniqueNetId PlayerID, int StatColumnNo, int& StatValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22840);
			byte params[20] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerID;
			*(int*)&params[8] = StatColumnNo;
			*(int*)&params[12] = StatValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			StatValue = *(int*)&params[12];
			return *(bool*)&params[16];
		}
		bool SetIntStatValueForPlayer(OnlineSubsystem::UniqueNetId PlayerID, int StatColumnNo, int StatValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22845);
			byte params[20] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerID;
			*(int*)&params[8] = StatColumnNo;
			*(int*)&params[12] = StatValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool GetFloatStatValueForPlayer(OnlineSubsystem::UniqueNetId PlayerID, int StatColumnNo, float& StatValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22850);
			byte params[20] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerID;
			*(int*)&params[8] = StatColumnNo;
			*(float*)&params[12] = StatValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			StatValue = *(float*)&params[12];
			return *(bool*)&params[16];
		}
		bool SetFloatStatValueForPlayer(OnlineSubsystem::UniqueNetId PlayerID, int StatColumnNo, float StatValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22855);
			byte params[20] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerID;
			*(int*)&params[8] = StatColumnNo;
			*(float*)&params[12] = StatValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AddPlayer(ScriptString* PlayerName, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22860);
			byte params[20] = { NULL };
			*(ScriptString**)params = PlayerName;
			*(OnlineSubsystem::UniqueNetId*)&params[12] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetRankForPlayer(OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22863);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
	};
}
#undef ADD_STRUCT
