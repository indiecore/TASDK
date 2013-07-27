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
		class ServerInfo
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
		class RentalItem
		{
		public:
			ADD_STRUCT(ScriptString*, RentalName, 12)
			ADD_STRUCT(int, Price, 0)
			ADD_STRUCT(int, LootId, 4)
			ADD_STRUCT(int, SortOrder, 8)
		};
		class ProfileConfig
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
		class ServerConfig
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetStatus");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		bool SetPropNumber(int PropId, int val, int PropType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.SetPropNumber");
			byte params[16] = { NULL };
			*(int*)&params[0] = PropId;
			*(int*)&params[4] = val;
			*(int*)&params[8] = PropType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool GetNextMapId(bool bStart, int& MapId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetNextMapId");
			byte params[12] = { NULL };
			*(bool*)&params[0] = bStart;
			*(int*)&params[4] = MapId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MapId = *(int*)&params[4];
			return *(bool*)&params[8];
		}
		ScriptString* GetMapName(int MapId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetMapName");
			byte params[16] = { NULL };
			*(int*)&params[0] = MapId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* GetProfileName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetProfileName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		ScriptString* GetProfileDesc()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetProfileDesc");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		ScriptString* GetServerGameTypeName(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetServerGameTypeName");
			byte params[16] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		int GetProfileGameType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetProfileGameType");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		ScriptString* GetServerRotationName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetServerRotationName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		bool IsGameTypeFiltered(int Id)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.IsGameTypeFiltered");
			byte params[8] = { NULL };
			*(int*)&params[0] = Id;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AmServerOwner()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.AmServerOwner");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		int GetPropNumber(int PropId, int PropType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetPropNumber");
			byte params[12] = { NULL };
			*(int*)&params[0] = PropId;
			*(int*)&params[4] = PropType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		ScriptString* GetServerTimeFormat()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetServerTimeFormat");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		int GetQueueCaseId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetQueueCaseId");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		bool GetServerOnline(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetServerOnline");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptString* GetServerName(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetServerName");
			byte params[16] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		bool AddCustomServer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.AddCustomServer");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		int GetProfileRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetProfileRotation");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		bool GetServerExpired()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetServerExpired");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		int GetServerTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetServerTime");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		bool CustomStart()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.CustomStart");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool CustomStop()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.CustomStop");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool CustomShutdown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.CustomShutdown");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool CustomNextMap(int MapId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.CustomNextMap");
			byte params[8] = { NULL };
			*(int*)&params[0] = MapId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CustomKick(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.CustomKick");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool CustomBan(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.CustomBan");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool AddCustomServerTime(int LootId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.AddCustomServerTime");
			byte params[8] = { NULL };
			*(int*)&params[0] = LootId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool GetPropMin(int PropId, int PropType, int& val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetPropMin");
			byte params[16] = { NULL };
			*(int*)&params[0] = PropId;
			*(int*)&params[4] = PropType;
			*(int*)&params[8] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			val = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		bool GetPropMax(int PropId, int PropType, int& val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetPropMax");
			byte params[16] = { NULL };
			*(int*)&params[0] = PropId;
			*(int*)&params[4] = PropType;
			*(int*)&params[8] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			val = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		ScriptString* GetAdminPassword()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetAdminPassword");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		ScriptString* GetPublicPassword()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetPublicPassword");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		bool CustomSetName(ScriptString* QueueName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.CustomSetName");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = QueueName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool SetPropString(int PropId, ScriptString* val, int PropType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.SetPropString");
			byte params[24] = { NULL };
			*(int*)&params[0] = PropId;
			*(ScriptString**)&params[4] = val;
			*(int*)&params[16] = PropType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		int GetProfileRegion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetProfileRegion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		bool CustomLogin(ScriptString* Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.CustomLogin");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		int FavoriteSortB(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.FavoriteSortB");
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)&params[0] = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int PasswordSortB(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.PasswordSortB");
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)&params[0] = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int SlotsSortB(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.SlotsSortB");
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)&params[0] = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int RangeSortB(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.RangeSortB");
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)&params[0] = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int RulesSortB(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.RulesSortB");
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)&params[0] = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int TypeSortB(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.TypeSortB");
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)&params[0] = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int PingSortB(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.PingSortB");
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)&params[0] = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int NameSortB(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.NameSortB");
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)&params[0] = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int MapSortB(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.MapSortB");
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)&params[0] = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int FavoriteSortA(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.FavoriteSortA");
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)&params[0] = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int PasswordSortA(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.PasswordSortA");
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)&params[0] = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int SlotsSortA(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.SlotsSortA");
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)&params[0] = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int RangeSortA(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.RangeSortA");
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)&params[0] = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int RulesSortA(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.RulesSortA");
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)&params[0] = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int TypeSortA(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.TypeSortA");
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)&params[0] = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int PingSortA(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.PingSortA");
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)&params[0] = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int NameSortA(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.NameSortA");
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)&params[0] = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		int MapSortA(TrQueueManager::ServerInfo A, TrQueueManager::ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.MapSortA");
			byte params[164] = { NULL };
			*(TrQueueManager::ServerInfo*)&params[0] = A;
			*(TrQueueManager::ServerInfo*)&params[80] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[160];
		}
		void ForceGoHome()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.ForceGoHome");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OpenLocal(ScriptString* URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.OpenLocal");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetCustomServers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetCustomServers");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RequestCustomServers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.RequestCustomServers");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RefreshRentedServers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.RefreshRentedServers");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetPropString(int PropId, int PropType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetPropString");
			byte params[20] = { NULL };
			*(int*)&params[0] = PropId;
			*(int*)&params[4] = PropType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		bool SetLocalName(ScriptString* val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.SetLocalName");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool MatchQueueJoin(int Queue, ScriptString* Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.MatchQueueJoin");
			byte params[20] = { NULL };
			*(int*)&params[0] = Queue;
			*(ScriptString**)&params[4] = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LeaveMatchmaking(bool bForced)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.LeaveMatchmaking");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bForced;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void JoinQueue(int nQueueId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.JoinQueue");
			byte params[4] = { NULL };
			*(int*)&params[0] = nQueueId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPlayerQueued()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.SetPlayerQueued");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void JoinFriend(ScriptString* PlayerName, ScriptString* Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.JoinFriend");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			*(ScriptString**)&params[12] = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ExitGameInProgress(bool bForceDrop, bool bKicked)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.ExitGameInProgress");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bForceDrop;
			*(bool*)&params[4] = bKicked;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerInfoLoaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.ServerInfoLoaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void JoinCustomServer(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.JoinCustomServer");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void JoinProtectedServer(ScriptString* Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.JoinProtectedServer");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FavoriteServer(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.FavoriteServer");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PasswordServer(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.PasswordServer");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActiveServer(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.SetActiveServer");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerPage(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.ServerPage");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSort(ScriptString* SortName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.ServerSort");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = SortName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SortOn(ScriptString* SortName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.SortOn");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = SortName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetSlots()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetSlots");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetGameCaseId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetGameCaseId");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void AddServerConfig(int MatchQueueId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.AddServerConfig");
			byte params[4] = { NULL };
			*(int*)&params[0] = MatchQueueId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddProfileConfig(int Index, TrQueueManager::ProfileConfig Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.AddProfileConfig");
			byte params[64] = { NULL };
			*(int*)&params[0] = Index;
			*(TrQueueManager::ProfileConfig*)&params[4] = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.ResetRotation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetDefaultMapId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetDefaultMapId");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void MarkFavorite(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.MarkFavorite");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FilterGameType(int Id, bool bFilter)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.FilterGameType");
			byte params[8] = { NULL };
			*(int*)&params[0] = Id;
			*(bool*)&params[4] = bFilter;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
