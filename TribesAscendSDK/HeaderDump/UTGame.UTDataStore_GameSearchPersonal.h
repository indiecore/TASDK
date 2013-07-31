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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46900);
			byte params[8] = { NULL };
			*(bool*)params = bRestrictCheckToSelf;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool OverrideQuerySubmission(byte ControllerId, class OnlineGameSearch* Search)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46940);
			byte params[9] = { NULL };
			*params = ControllerId;
			*(class OnlineGameSearch**)&params[4] = Search;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		ScriptString* GetPlayerName(int ControllerId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46951);
			byte params[16] = { NULL };
			*(int*)params = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		bool GetPlayerNetId(OnlineSubsystem::UniqueNetId& out_PlayerId, int ControllerId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46956);
			byte params[16] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = out_PlayerId;
			*(int*)&params[8] = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_PlayerId = *(OnlineSubsystem::UniqueNetId*)params;
			return *(bool*)&params[12];
		}
		int FindServerIndexByString(int ControllerId, ScriptString* IdToFind)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46962);
			byte params[20] = { NULL };
			*(int*)params = ControllerId;
			*(ScriptString**)&params[4] = IdToFind;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[16];
		}
		int FindServerIndexById(int ControllerId, OnlineSubsystem::UniqueNetId& IdToFind)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46968);
			byte params[16] = { NULL };
			*(int*)params = ControllerId;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = IdToFind;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			IdToFind = *(OnlineSubsystem::UniqueNetId*)&params[4];
			return *(int*)&params[12];
		}
		bool AddServer(int ControllerId, OnlineSubsystem::UniqueNetId IdToAdd)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46972);
			byte params[16] = { NULL };
			*(int*)params = ControllerId;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = IdToAdd;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool RemoveServer(int ControllerId, OnlineSubsystem::UniqueNetId IdToRemove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46980);
			byte params[16] = { NULL };
			*(int*)params = ControllerId;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = IdToRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void GetServerIdList(ScriptArray<OnlineSubsystem::UniqueNetId>& out_ServerList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46987);
			byte params[12] = { NULL };
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)params = out_ServerList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ServerList = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)params;
		}
		void GetServerStringList(ScriptArray<ScriptString*>& out_ServerList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46992);
			byte params[12] = { NULL };
			*(ScriptArray<ScriptString*>*)params = out_ServerList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ServerList = *(ScriptArray<ScriptString*>*)params;
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
