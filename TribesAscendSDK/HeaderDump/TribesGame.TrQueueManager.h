#pragma once
#include "PlatformCommon.TgPlayerProfile.h"
#include "Core.Object.h"
#include "TribesGame.GFxTrMenuMoviePlayer.h"
#include "OnlineSubsystemMcts.OnlineGameInterfaceMcts.h"
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
	class TrQueueManager : public Object
	{
	public:
		struct ServerInfo
		{
		public:
			ADD_STRUCT(int, PlayerCount, 20)
			ADD_STRUCT(int, PlayerMax, 16)
			ADD_STRUCT(ScriptString*, MapName, 56)
			ADD_STRUCT(ScriptString*, ServerName, 32)
			ADD_BOOL(bFavorite, 24, 0x2)
			ADD_STRUCT(int, queueId, 4)
			ADD_STRUCT(int, Ping, 0)
			ADD_BOOL(bPrivate, 24, 0x1)
			ADD_STRUCT(ScriptString*, Ruleset, 68)
			ADD_STRUCT(int, MinLevel, 8)
			ADD_STRUCT(int, MaxLevel, 12)
			ADD_STRUCT(ScriptString*, ServerDesc, 44)
			ADD_STRUCT(int, GameType, 28)
		};
		struct RentalItem
		{
		public:
			ADD_STRUCT(ScriptString*, RentalName, 12)
			ADD_STRUCT(int, Price, 0)
			ADD_STRUCT(int, LootId, 4)
			ADD_STRUCT(int, SortOrder, 8)
		};
		struct ProfileConfig
		{
		public:
			ADD_STRUCT(ScriptString*, PasswordPublic, 48)
			ADD_STRUCT(ScriptString*, PasswordAdmin, 36)
			ADD_STRUCT(ScriptString*, ProfileDesc, 24)
			ADD_STRUCT(ScriptString*, ProfileName, 12)
			ADD_STRUCT(int, QueueCaseId, 8)
			ADD_STRUCT(int, GameCaseId, 4)
			ADD_STRUCT(int, Slots, 0)
		};
		struct ServerConfig
		{
		public:
			ADD_STRUCT(ScriptArray<TrQueueManager::ProfileConfig>, Profiles, 28)
			ADD_STRUCT(ScriptString*, ServerName, 16)
			ADD_BOOL(bCanExpire, 12, 0x8)
			ADD_BOOL(bActive, 12, 0x4)
			ADD_BOOL(bOwner, 12, 0x2)
			ADD_BOOL(bOpen, 12, 0x1)
			ADD_STRUCT(int, MinutesRented, 8)
			ADD_STRUCT(int, MatchQueueId, 4)
			ADD_STRUCT(int, ActiveConfig, 0)
		};
		ADD_BOOL(bQueued, 128, 0x1)
		ADD_BOOL(bJoiningCustom, 128, 0x4)
		ADD_STRUCT(ScriptArray<int>, RegionFilter, 116)
		ADD_STRUCT(ScriptString*, QueueFriend, 132)
		ADD_BOOL(bFilterOwner, 128, 0x8)
		ADD_STRUCT(ScriptArray<TrQueueManager::ServerInfo>, ServerInfoList, 152)
		ADD_STRUCT(int, GameTypeId, 96)
		ADD_STRUCT(ScriptArray<TrQueueManager::ServerConfig>, RentedServers, 164)
		ADD_STRUCT(int, ServerIndex, 104)
		ADD_STRUCT(int, MapSlots, 64)
		ADD_STRUCT(ScriptArray<TrQueueManager::RentalItem>, RentalItems, 176)
		ADD_BOOL(bNeedPassword, 128, 0x2)
		ADD_STRUCT(ScriptArray<TgPlayerProfile::PropertyPair>, FilteredGameTypes, 188)
		ADD_OBJECT(GFxTrMenuMoviePlayer, TrOuter, 148)
		ADD_OBJECT(OnlineGameInterfaceMcts, OnlineGameMcts, 144)
		ADD_BOOL(bFavoriteSort, 128, 0x1000)
		ADD_BOOL(bPasswordSort, 128, 0x800)
		ADD_BOOL(bSlotsSort, 128, 0x400)
		ADD_BOOL(bRangeSort, 128, 0x200)
		ADD_BOOL(bRulesSort, 128, 0x100)
		ADD_BOOL(bTypeSort, 128, 0x80)
		ADD_BOOL(bPingSort, 128, 0x40)
		ADD_BOOL(bNameSort, 128, 0x20)
		ADD_BOOL(bMapSort, 128, 0x10)
		ADD_STRUCT(int, PasswordQueue, 112)
		ADD_STRUCT(int, PasswordIndex, 108)
		ADD_STRUCT(int, ProfileIndex, 100)
		ADD_STRUCT(int, queueId, 60)
		ScriptString* GetStatus()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54699);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		bool SetPropNumber(int PropId, int val, int PropType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58002);
			byte params[16] = { NULL };
			*(int*)params = PropId;
			*(int*)&params[4] = val;
			*(int*)&params[8] = PropType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool GetNextMapId(bool bStart, int& MapId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58012);
			byte params[12] = { NULL };
			*(bool*)params = bStart;
			*(int*)&params[4] = MapId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MapId = *(int*)&params[4];
			return *(bool*)&params[8];
		}
		ScriptString* GetMapName(int MapId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58021);
			byte params[16] = { NULL };
			*(int*)params = MapId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* GetProfileName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58031);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		ScriptString* GetProfileDesc()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58033);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		ScriptString* GetServerGameTypeName(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58560);
			byte params[16] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		int GetProfileGameType()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59097);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		ScriptString* GetServerRotationName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59103);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		bool IsGameTypeFiltered(int Id)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59174);
			byte params[8] = { NULL };
			*(int*)params = Id;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AmServerOwner()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59650);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		int GetPropNumber(int PropId, int PropType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59655);
			byte params[12] = { NULL };
			*(int*)params = PropId;
			*(int*)&params[4] = PropType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		ScriptString* GetServerTimeFormat()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59661);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		int GetQueueCaseId()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59690);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool GetServerOnline(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59697);
			byte params[8] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptString* GetServerName(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59699);
			byte params[16] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		bool AddCustomServer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59711);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		int GetProfileRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60518);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool GetServerExpired()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60547);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		int GetServerTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60551);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool CustomStart()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60569);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CustomStop()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60571);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CustomShutdown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60573);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CustomNextMap(int MapId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60575);
			byte params[8] = { NULL };
			*(int*)params = MapId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CustomKick(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60577);
			byte params[16] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool CustomBan(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60579);
			byte params[16] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool AddCustomServerTime(int LootId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60615);
			byte params[8] = { NULL };
			*(int*)params = LootId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool GetPropMin(int PropId, int PropType, int& val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60746);
			byte params[16] = { NULL };
			*(int*)params = PropId;
			*(int*)&params[4] = PropType;
			*(int*)&params[8] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			val = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		bool GetPropMax(int PropId, int PropType, int& val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60748);
			byte params[16] = { NULL };
			*(int*)params = PropId;
			*(int*)&params[4] = PropType;
			*(int*)&params[8] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			val = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		ScriptString* GetAdminPassword()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60942);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		ScriptString* GetPublicPassword()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60945);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		bool CustomSetName(ScriptString* QueueName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60951);
			byte params[16] = { NULL };
			*(ScriptString**)params = QueueName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool SetPropString(int PropId, ScriptString* val, int PropType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60953);
			byte params[24] = { NULL };
			*(int*)params = PropId;
			*(ScriptString**)&params[4] = val;
			*(int*)&params[16] = PropType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		int GetProfileRegion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60961);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool CustomLogin(ScriptString* Password)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100339);
			byte params[16] = { NULL };
			*(ScriptString**)params = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		int FavoriteSortB(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109504);
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)params = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int PasswordSortB(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109506);
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)params = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int SlotsSortB(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109508);
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)params = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int RangeSortB(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109510);
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)params = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int RulesSortB(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109512);
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)params = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int TypeSortB(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109514);
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)params = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int PingSortB(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109516);
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)params = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int NameSortB(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109518);
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)params = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int MapSortB(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109520);
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)params = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int FavoriteSortA(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109522);
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)params = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int PasswordSortA(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109524);
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)params = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int SlotsSortA(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109526);
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)params = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int RangeSortA(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109528);
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)params = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int RulesSortA(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109530);
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)params = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int TypeSortA(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109532);
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)params = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int PingSortA(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109534);
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)params = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int NameSortA(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109536);
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)params = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int MapSortA(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109538);
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)params = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		void ForceGoHome()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109574);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OpenLocal(ScriptString* URL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109575);
			byte params[12] = { NULL };
			*(ScriptString**)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetCustomServers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109577);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RequestCustomServers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109578);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RefreshRentedServers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109579);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetPropString(int PropId, int PropType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109585);
			byte params[20] = { NULL };
			*(int*)params = PropId;
			*(int*)&params[4] = PropType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		bool SetLocalName(ScriptString* val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109595);
			byte params[16] = { NULL };
			*(ScriptString**)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool MatchQueueJoin(int Queue, ScriptString* Password)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109610);
			byte params[20] = { NULL };
			*(int*)params = Queue;
			*(ScriptString**)&params[4] = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109614);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LeaveMatchmaking(bool bForced)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109616);
			byte params[4] = { NULL };
			*(bool*)params = bForced;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void JoinQueue(int nQueueId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109618);
			byte params[4] = { NULL };
			*(int*)params = nQueueId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPlayerQueued()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109620);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void JoinFriend(ScriptString* PlayerName, ScriptString* Password)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109621);
			byte params[24] = { NULL };
			*(ScriptString**)params = PlayerName;
			*(ScriptString**)&params[12] = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ExitGameInProgress(bool bForceDrop, bool bKicked)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109624);
			byte params[8] = { NULL };
			*(bool*)params = bForceDrop;
			*(bool*)&params[4] = bKicked;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerInfoLoaded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109628);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void JoinCustomServer(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109629);
			byte params[4] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void JoinProtectedServer(ScriptString* Password)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109631);
			byte params[12] = { NULL };
			*(ScriptString**)params = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FavoriteServer(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109633);
			byte params[4] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PasswordServer(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109635);
			byte params[4] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActiveServer(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109637);
			byte params[4] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerPage(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109639);
			byte params[4] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSort(ScriptString* SortName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109641);
			byte params[12] = { NULL };
			*(ScriptString**)params = SortName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SortOn(ScriptString* SortName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109643);
			byte params[12] = { NULL };
			*(ScriptString**)params = SortName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetSlots()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109699);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetGameCaseId()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109701);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void AddServerConfig(int MatchQueueId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109713);
			byte params[4] = { NULL };
			*(int*)params = MatchQueueId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddProfileConfig(int Index, TrQueueManager::ProfileConfig Data)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109716);
			byte params[64] = { NULL };
			*(int*)params = Index;
			*(TrQueueManager::ProfileConfig*)&params[4] = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109719);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetDefaultMapId()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109721);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void MarkFavorite(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109723);
			byte params[4] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FilterGameType(int Id, bool bFilter)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109725);
			byte params[8] = { NULL };
			*(int*)params = Id;
			*(bool*)&params[4] = bFilter;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
