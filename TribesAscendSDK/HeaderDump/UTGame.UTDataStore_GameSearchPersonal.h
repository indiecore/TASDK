#pragma once
#include "UDKBase.UDKDataStore_GameSearchBase.h"
#include "UTGame.UTDataStore_GameSearchDM.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "Engine.OnlineGameSearch.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTDataStore_GameSearchPersonal." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTDataStore_GameSearchPersonal." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTDataStore_GameSearchPersonal : public UDKDataStore_GameSearchBase
	{
	public:
		ADD_OBJECT(UTDataStore_GameSearchDM, PrimaryGameSearchDataStore)
		ADD_VAR(::StrProperty, ServerUniqueId, 0xFFFFFFFF)
		bool HasOutstandingQueries(bool bRestrictCheckToSelf)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.HasOutstandingQueries");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bRestrictCheckToSelf;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool OverrideQuerySubmission(byte ControllerId, class OnlineGameSearch* Search)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.OverrideQuerySubmission");
			byte* params = (byte*)malloc(9);
			*params = ControllerId;
			*(class OnlineGameSearch**)(params + 4) = Search;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetPlayerName(int ControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.GetPlayerName");
			byte* params = (byte*)malloc(16);
			*(int*)params = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		bool GetPlayerNetId(UniqueNetId& out_PlayerId, int ControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.GetPlayerNetId");
			byte* params = (byte*)malloc(16);
			*(UniqueNetId*)params = out_PlayerId;
			*(int*)(params + 8) = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_PlayerId = *(UniqueNetId*)params;
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		int FindServerIndexByString(int ControllerId, ScriptArray<wchar_t> IdToFind)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.FindServerIndexByString");
			byte* params = (byte*)malloc(20);
			*(int*)params = ControllerId;
			*(ScriptArray<wchar_t>*)(params + 4) = IdToFind;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 16);
			free(params);
			return returnVal;
		}
		int FindServerIndexById(int ControllerId, UniqueNetId& IdToFind)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.FindServerIndexById");
			byte* params = (byte*)malloc(16);
			*(int*)params = ControllerId;
			*(UniqueNetId*)(params + 4) = IdToFind;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			IdToFind = *(UniqueNetId*)(params + 4);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		bool AddServer(int ControllerId, UniqueNetId IdToAdd)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.AddServer");
			byte* params = (byte*)malloc(16);
			*(int*)params = ControllerId;
			*(UniqueNetId*)(params + 4) = IdToAdd;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool RemoveServer(int ControllerId, UniqueNetId IdToRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.RemoveServer");
			byte* params = (byte*)malloc(16);
			*(int*)params = ControllerId;
			*(UniqueNetId*)(params + 4) = IdToRemove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void GetServerIdList(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_ServerList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.GetServerIdList");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = out_ServerList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ServerList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void GetServerStringList(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_ServerList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchPersonal.GetServerStringList");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = out_ServerList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ServerList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
