#pragma once
#include "Core.Object.h"
#include "TribesGame.GFxTrMenuMoviePlayer.h"
#include "OnlineSubsystemMcts.OnlineGameInterfaceMcts.h"
#include "TribesGame.TrQueueManager.ServerInfo.h"
#include "TribesGame.TrQueueManager.ProfileConfig.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrQueueManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrQueueManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrQueueManager : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bQueued, 0x1)
		ADD_VAR(::BoolProperty, bJoiningCustom, 0x4)
		ADD_VAR(::StrProperty, QueueFriend, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFilterOwner, 0x8)
		ADD_VAR(::IntProperty, GameTypeId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ServerIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MapSlots, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNeedPassword, 0x2)
		ADD_OBJECT(GFxTrMenuMoviePlayer, TrOuter)
		ADD_OBJECT(OnlineGameInterfaceMcts, OnlineGameMcts)
		ADD_VAR(::BoolProperty, bFavoriteSort, 0x1000)
		ADD_VAR(::BoolProperty, bPasswordSort, 0x800)
		ADD_VAR(::BoolProperty, bSlotsSort, 0x400)
		ADD_VAR(::BoolProperty, bRangeSort, 0x200)
		ADD_VAR(::BoolProperty, bRulesSort, 0x100)
		ADD_VAR(::BoolProperty, bTypeSort, 0x80)
		ADD_VAR(::BoolProperty, bPingSort, 0x40)
		ADD_VAR(::BoolProperty, bNameSort, 0x20)
		ADD_VAR(::BoolProperty, bMapSort, 0x10)
		ADD_VAR(::IntProperty, PasswordQueue, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PasswordIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ProfileIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, queueId, 0xFFFFFFFF)
		ScriptArray<wchar_t> GetStatus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetStatus");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool SetPropNumber(int PropId, int val, int PropType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.SetPropNumber");
			byte* params = (byte*)malloc(16);
			*(int*)params = PropId;
			*(int*)(params + 4) = val;
			*(int*)(params + 8) = PropType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetNextMapId(bool bStart, int& MapId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetNextMapId");
			byte* params = (byte*)malloc(12);
			*(bool*)params = bStart;
			*(int*)(params + 4) = MapId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			MapId = *(int*)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetMapName(int MapId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetMapName");
			byte* params = (byte*)malloc(16);
			*(int*)params = MapId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetProfileName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetProfileName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetProfileDesc()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetProfileDesc");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetServerGameTypeName(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetServerGameTypeName");
			byte* params = (byte*)malloc(16);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetProfileGameType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetProfileGameType");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetServerRotationName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetServerRotationName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool IsGameTypeFiltered(int Id)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.IsGameTypeFiltered");
			byte* params = (byte*)malloc(8);
			*(int*)params = Id;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool AmServerOwner()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.AmServerOwner");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		int GetPropNumber(int PropId, int PropType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetPropNumber");
			byte* params = (byte*)malloc(12);
			*(int*)params = PropId;
			*(int*)(params + 4) = PropType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetServerTimeFormat()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetServerTimeFormat");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		int GetQueueCaseId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetQueueCaseId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool GetServerOnline(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetServerOnline");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetServerName(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetServerName");
			byte* params = (byte*)malloc(16);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		bool AddCustomServer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.AddCustomServer");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		int GetProfileRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetProfileRotation");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool GetServerExpired()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetServerExpired");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		int GetServerTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetServerTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool CustomStart()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.CustomStart");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CustomStop()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.CustomStop");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CustomShutdown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.CustomShutdown");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CustomNextMap(int MapId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.CustomNextMap");
			byte* params = (byte*)malloc(8);
			*(int*)params = MapId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CustomKick(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.CustomKick");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool CustomBan(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.CustomBan");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool AddCustomServerTime(int LootId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.AddCustomServerTime");
			byte* params = (byte*)malloc(8);
			*(int*)params = LootId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool GetPropMin(int PropId, int PropType, int& val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetPropMin");
			byte* params = (byte*)malloc(16);
			*(int*)params = PropId;
			*(int*)(params + 4) = PropType;
			*(int*)(params + 8) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			val = *(int*)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetPropMax(int PropId, int PropType, int& val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetPropMax");
			byte* params = (byte*)malloc(16);
			*(int*)params = PropId;
			*(int*)(params + 4) = PropType;
			*(int*)(params + 8) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			val = *(int*)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetAdminPassword()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetAdminPassword");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetPublicPassword()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetPublicPassword");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool CustomSetName(ScriptArray<wchar_t> QueueName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.CustomSetName");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = QueueName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool SetPropString(int PropId, ScriptArray<wchar_t> val, int PropType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.SetPropString");
			byte* params = (byte*)malloc(24);
			*(int*)params = PropId;
			*(ScriptArray<wchar_t>*)(params + 4) = val;
			*(int*)(params + 16) = PropType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		int GetProfileRegion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetProfileRegion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool CustomLogin(ScriptArray<wchar_t> Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.CustomLogin");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Password;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		int FavoriteSortB(ServerInfo A, ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.FavoriteSortB");
			byte* params = (byte*)malloc(164);
			*(ServerInfo*)params = A;
			*(ServerInfo*)(params + 80) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 160);
			free(params);
			return returnVal;
		}
		int PasswordSortB(ServerInfo A, ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.PasswordSortB");
			byte* params = (byte*)malloc(164);
			*(ServerInfo*)params = A;
			*(ServerInfo*)(params + 80) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 160);
			free(params);
			return returnVal;
		}
		int SlotsSortB(ServerInfo A, ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.SlotsSortB");
			byte* params = (byte*)malloc(164);
			*(ServerInfo*)params = A;
			*(ServerInfo*)(params + 80) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 160);
			free(params);
			return returnVal;
		}
		int RangeSortB(ServerInfo A, ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.RangeSortB");
			byte* params = (byte*)malloc(164);
			*(ServerInfo*)params = A;
			*(ServerInfo*)(params + 80) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 160);
			free(params);
			return returnVal;
		}
		int RulesSortB(ServerInfo A, ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.RulesSortB");
			byte* params = (byte*)malloc(164);
			*(ServerInfo*)params = A;
			*(ServerInfo*)(params + 80) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 160);
			free(params);
			return returnVal;
		}
		int TypeSortB(ServerInfo A, ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.TypeSortB");
			byte* params = (byte*)malloc(164);
			*(ServerInfo*)params = A;
			*(ServerInfo*)(params + 80) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 160);
			free(params);
			return returnVal;
		}
		int PingSortB(ServerInfo A, ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.PingSortB");
			byte* params = (byte*)malloc(164);
			*(ServerInfo*)params = A;
			*(ServerInfo*)(params + 80) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 160);
			free(params);
			return returnVal;
		}
		int NameSortB(ServerInfo A, ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.NameSortB");
			byte* params = (byte*)malloc(164);
			*(ServerInfo*)params = A;
			*(ServerInfo*)(params + 80) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 160);
			free(params);
			return returnVal;
		}
		int MapSortB(ServerInfo A, ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.MapSortB");
			byte* params = (byte*)malloc(164);
			*(ServerInfo*)params = A;
			*(ServerInfo*)(params + 80) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 160);
			free(params);
			return returnVal;
		}
		int FavoriteSortA(ServerInfo A, ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.FavoriteSortA");
			byte* params = (byte*)malloc(164);
			*(ServerInfo*)params = A;
			*(ServerInfo*)(params + 80) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 160);
			free(params);
			return returnVal;
		}
		int PasswordSortA(ServerInfo A, ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.PasswordSortA");
			byte* params = (byte*)malloc(164);
			*(ServerInfo*)params = A;
			*(ServerInfo*)(params + 80) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 160);
			free(params);
			return returnVal;
		}
		int SlotsSortA(ServerInfo A, ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.SlotsSortA");
			byte* params = (byte*)malloc(164);
			*(ServerInfo*)params = A;
			*(ServerInfo*)(params + 80) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 160);
			free(params);
			return returnVal;
		}
		int RangeSortA(ServerInfo A, ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.RangeSortA");
			byte* params = (byte*)malloc(164);
			*(ServerInfo*)params = A;
			*(ServerInfo*)(params + 80) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 160);
			free(params);
			return returnVal;
		}
		int RulesSortA(ServerInfo A, ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.RulesSortA");
			byte* params = (byte*)malloc(164);
			*(ServerInfo*)params = A;
			*(ServerInfo*)(params + 80) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 160);
			free(params);
			return returnVal;
		}
		int TypeSortA(ServerInfo A, ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.TypeSortA");
			byte* params = (byte*)malloc(164);
			*(ServerInfo*)params = A;
			*(ServerInfo*)(params + 80) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 160);
			free(params);
			return returnVal;
		}
		int PingSortA(ServerInfo A, ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.PingSortA");
			byte* params = (byte*)malloc(164);
			*(ServerInfo*)params = A;
			*(ServerInfo*)(params + 80) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 160);
			free(params);
			return returnVal;
		}
		int NameSortA(ServerInfo A, ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.NameSortA");
			byte* params = (byte*)malloc(164);
			*(ServerInfo*)params = A;
			*(ServerInfo*)(params + 80) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 160);
			free(params);
			return returnVal;
		}
		int MapSortA(ServerInfo A, ServerInfo B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.MapSortA");
			byte* params = (byte*)malloc(164);
			*(ServerInfo*)params = A;
			*(ServerInfo*)(params + 80) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 160);
			free(params);
			return returnVal;
		}
		void ForceGoHome()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.ForceGoHome");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OpenLocal(ScriptArray<wchar_t> URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.OpenLocal");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		ScriptArray<wchar_t> GetPropString(int PropId, int PropType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetPropString");
			byte* params = (byte*)malloc(20);
			*(int*)params = PropId;
			*(int*)(params + 4) = PropType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 8);
			free(params);
			return returnVal;
		}
		bool SetLocalName(ScriptArray<wchar_t> val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.SetLocalName");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool MatchQueueJoin(int Queue, ScriptArray<wchar_t> Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.MatchQueueJoin");
			byte* params = (byte*)malloc(20);
			*(int*)params = Queue;
			*(ScriptArray<wchar_t>*)(params + 4) = Password;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LeaveMatchmaking(bool bForced)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.LeaveMatchmaking");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bForced;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void JoinQueue(int nQueueId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.JoinQueue");
			byte* params = (byte*)malloc(4);
			*(int*)params = nQueueId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPlayerQueued()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.SetPlayerQueued");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void JoinFriend(ScriptArray<wchar_t> PlayerName, ScriptArray<wchar_t> Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.JoinFriend");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			*(ScriptArray<wchar_t>*)(params + 12) = Password;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ExitGameInProgress(bool bForceDrop, bool bKicked)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.ExitGameInProgress");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bForceDrop;
			*(bool*)(params + 4) = bKicked;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerInfoLoaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.ServerInfoLoaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void JoinCustomServer(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.JoinCustomServer");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void JoinProtectedServer(ScriptArray<wchar_t> Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.JoinProtectedServer");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Password;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FavoriteServer(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.FavoriteServer");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PasswordServer(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.PasswordServer");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetActiveServer(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.SetActiveServer");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerPage(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.ServerPage");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerSort(ScriptArray<wchar_t> SortName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.ServerSort");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = SortName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SortOn(ScriptArray<wchar_t> SortName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.SortOn");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = SortName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetSlots()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetSlots");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetGameCaseId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetGameCaseId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void AddServerConfig(int MatchQueueId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.AddServerConfig");
			byte* params = (byte*)malloc(4);
			*(int*)params = MatchQueueId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddProfileConfig(int Index, ProfileConfig Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.AddProfileConfig");
			byte* params = (byte*)malloc(64);
			*(int*)params = Index;
			*(ProfileConfig*)(params + 4) = Data;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.ResetRotation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetDefaultMapId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.GetDefaultMapId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void MarkFavorite(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.MarkFavorite");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FilterGameType(int Id, bool bFilter)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrQueueManager.FilterGameType");
			byte* params = (byte*)malloc(8);
			*(int*)params = Id;
			*(bool*)(params + 4) = bFilter;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
