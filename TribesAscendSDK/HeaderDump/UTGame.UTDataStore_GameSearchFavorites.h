#pragma once
#include "UTGame.UTDataStore_GameSearchPersonal.h"
#include "UTGame.UTDataStore_GameSearchHistory.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTDataStore_GameSearchFavorites." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTDataStore_GameSearchFavorites : public UTDataStore_GameSearchPersonal
	{
	public:
		ADD_OBJECT(UTDataStore_GameSearchHistory, HistoryGameSearchDataStore)
		bool HasOutstandingQueries(bool bRestrictCheckToSelf)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchFavorites.HasOutstandingQueries");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bRestrictCheckToSelf;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_OBJECT
