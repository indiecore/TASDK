#pragma once
#include "UTGame.UTDataStore_GameSearchPersonal.h"
#include "UTGame.UTDataStore_GameSearchFavorites.h"
#include "Engine.LocalPlayer.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTDataStore_GameSearchHistory : public UTDataStore_GameSearchPersonal
	{
	public:
		ADD_OBJECT(UTDataStore_GameSearchFavorites, FavoritesGameSearchDataStore, 360)
		ADD_OBJECT(ScriptClass, FavoritesGameSearchDataStoreClass, 356)
		bool HasOutstandingQueries(bool bRestrictCheckToSelf)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchHistory.HasOutstandingQueries");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bRestrictCheckToSelf;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void Registered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchHistory.Registered");
			byte params[4] = { NULL };
			*(class LocalPlayer**)&params[0] = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
