#pragma once
#include "Engine.Settings.h"
#include "Engine.OnlineSubsystem.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class OnlineGameSearch : public Settings
	{
	public:
		enum EOnlineGameSearchComparisonType : byte
		{
			OGSCT_Equals = 0,
			OGSCT_NotEquals = 1,
			OGSCT_GreaterThan = 2,
			OGSCT_GreaterThanEquals = 3,
			OGSCT_LessThan = 4,
			OGSCT_LessThanEquals = 5,
			OGSCT_MAX = 6,
		};
		enum EOnlineGameSearchEntryType : byte
		{
			OGSET_Property = 0,
			OGSET_LocalizedSetting = 1,
			OGSET_ObjectProperty = 2,
			OGSET_MAX = 3,
		};
		enum EOnlineGameSearchSortType : byte
		{
			OGSSO_Ascending = 0,
			OGSSO_Descending = 1,
			OGSSO_MAX = 2,
		};
		struct OverrideSkill
		{
		public:
			ADD_STRUCT(int, LeaderboardId, 0)
			ADD_STRUCT(ScriptArray<OnlineSubsystem::UniqueNetId>, Players, 4)
			ADD_STRUCT(ScriptArray<Object::Double>, Mus, 16)
			ADD_STRUCT(ScriptArray<Object::Double>, Sigmas, 28)
		};
		struct NamedObjectProperty
		{
		public:
			ADD_STRUCT(ScriptName, ObjectPropertyName, 0)
			ADD_STRUCT(ScriptString*, ObjectPropertyValue, 8)
		};
		struct OnlineGameSearchResult
		{
		public:
			ADD_OBJECT(OnlineGameSettings, GameSettings, 0)
			ADD_STRUCT(Object::Pointer, PlatformData, 4)
		};
		struct OnlineGameSearchSortClause
		{
		public:
			ADD_STRUCT(int, EntryId, 0)
			ADD_STRUCT(ScriptName, ObjectPropertyName, 4)
			ADD_STRUCT(OnlineGameSearch::EOnlineGameSearchEntryType, EntryType, 12)
			ADD_STRUCT(OnlineGameSearch::EOnlineGameSearchSortType, SortType, 13)
		};
		struct OnlineGameSearchParameter
		{
		public:
			ADD_STRUCT(int, EntryId, 0)
			ADD_STRUCT(ScriptName, ObjectPropertyName, 4)
			ADD_STRUCT(OnlineGameSearch::EOnlineGameSearchEntryType, EntryType, 12)
			ADD_STRUCT(OnlineGameSearch::EOnlineGameSearchComparisonType, ComparisonType, 13)
		};
		struct OnlineGameSearchORClause
		{
		public:
			ADD_STRUCT(ScriptArray<OnlineGameSearch::OnlineGameSearchParameter>, OrParams, 0)
		};
		struct OnlineGameSearchQuery
		{
		public:
			ADD_STRUCT(ScriptArray<OnlineGameSearch::OnlineGameSearchORClause>, OrClauses, 0)
			ADD_STRUCT(ScriptArray<OnlineGameSearch::OnlineGameSearchSortClause>, SortClauses, 12)
		};
		ADD_STRUCT(OnlineGameSearch::OverrideSkill, ManualSkillOverride, 144)
		ADD_STRUCT(int, MaxSearchResults, 108)
		ADD_STRUCT(Settings::LocalizedStringSetting, Query, 112)
		ADD_BOOL(bIsLanQuery, 124, 0x1)
		ADD_BOOL(bUsesArbitration, 124, 0x2)
		ADD_BOOL(bIsSearchInProgress, 124, 0x4)
		ADD_OBJECT(ScriptClass, GameSettingsClass, 128)
		ADD_STRUCT(ScriptArray<OnlineGameSearch::OnlineGameSearchResult>, Results, 132)
		ADD_STRUCT(ScriptArray<OnlineGameSearch::NamedObjectProperty>, NamedProperties, 184)
		ADD_STRUCT(OnlineGameSearch::OnlineGameSearchQuery, FilterQuery, 196)
		ADD_STRUCT(ScriptString*, AdditionalSearchCriteria, 220)
		ADD_STRUCT(int, PingBucketSize, 232)
		void SortSearchResults()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6865);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSkillOverride(int LeaderboardId, ScriptArray<OnlineSubsystem::UniqueNetId>& Players)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6866);
			byte params[16] = { NULL };
			*(int*)params = LeaderboardId;
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[4] = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
