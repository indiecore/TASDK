#pragma once
#include "UTGame__UTDataStore_GameSearchPersonal.h"
#include "UTGame__UTDataStore_GameSearchFavorites.h"
#include "Engine__LocalPlayer.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTDataStore_GameSearchHistory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTDataStore_GameSearchHistory : public UTDataStore_GameSearchPersonal
	{
	public:
		ADD_OBJECT(UTDataStore_GameSearchFavorites, FavoritesGameSearchDataStore)
		ADD_OBJECT(ScriptClass, FavoritesGameSearchDataStoreClass)
		bool HasOutstandingQueries(bool bRestrictCheckToSelf)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchHistory.HasOutstandingQueries");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bRestrictCheckToSelf;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void Registered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchHistory.Registered");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_OBJECT
