#pragma once
#include "Engine.OnlineSubsystem.h"
#include "UDKBase.UDKDataStore_GameSearchBase.h"
#include "UTGame.UTDataStore_GameSearchDM.h"
#include "Engine.OnlineGameSearch.h"
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
	class UTDataStore_GameSearchPersonal : public UDKDataStore_GameSearchBase
	{
	public:
		static const auto MAX_PERSONALSERVERS = 15;
		ADD_OBJECT(UTDataStore_GameSearchDM, PrimaryGameSearchDataStore, 172)
		ADD_STRUCT(ScriptString*, ServerUniqueId, 176)
		bool HasOutstandingQueries(bool bRestrictCheckToSelf)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.HasOutstandingQueries");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bRestrictCheckToSelf;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool OverrideQuerySubmission(byte ControllerId, class OnlineGameSearch* Search)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.OverrideQuerySubmission");
			byte params[9] = { NULL };
			params[0] = ControllerId;
			*(class OnlineGameSearch**)&params[4] = Search;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		ScriptString* GetPlayerName(int ControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.GetPlayerName");
			byte params[16] = { NULL };
			*(int*)&params[0] = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		bool GetPlayerNetId(OnlineSubsystem::UniqueNetId& out_PlayerId, int ControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.GetPlayerNetId");
			byte params[16] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = out_PlayerId;
			*(int*)&params[8] = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_PlayerId = *(OnlineSubsystem::UniqueNetId*)&params[0];
			return *(bool*)&params[12];
		}
		int FindServerIndexByString(int ControllerId, ScriptString* IdToFind)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.FindServerIndexByString");
			byte params[20] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(ScriptString**)&params[4] = IdToFind;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[16];
		}
		int FindServerIndexById(int ControllerId, OnlineSubsystem::UniqueNetId& IdToFind)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.FindServerIndexById");
			byte params[16] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = IdToFind;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			IdToFind = *(OnlineSubsystem::UniqueNetId*)&params[4];
			return *(int*)&params[12];
		}
		bool AddServer(int ControllerId, OnlineSubsystem::UniqueNetId IdToAdd)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.AddServer");
			byte params[16] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = IdToAdd;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool RemoveServer(int ControllerId, OnlineSubsystem::UniqueNetId IdToRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.RemoveServer");
			byte params[16] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = IdToRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void GetServerIdList(ScriptArray<OnlineSubsystem::UniqueNetId>& out_ServerList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.GetServerIdList");
			byte params[12] = { NULL };
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[0] = out_ServerList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ServerList = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[0];
		}
		void GetServerStringList(ScriptArray<ScriptString*>& out_ServerList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.GetServerStringList");
			byte params[12] = { NULL };
			*(ScriptArray<ScriptString*>*)&params[0] = out_ServerList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ServerList = *(ScriptArray<ScriptString*>*)&params[0];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
