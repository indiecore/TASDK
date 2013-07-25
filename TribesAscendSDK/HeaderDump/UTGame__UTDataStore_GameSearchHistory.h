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
		// Here lies the not-yet-implemented method 'HasOutstandingQueries'
		// Here lies the not-yet-implemented method 'Registered'
	};
}
#undef ADD_OBJECT
