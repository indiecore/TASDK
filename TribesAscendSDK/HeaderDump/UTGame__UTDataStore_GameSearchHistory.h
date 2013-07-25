#pragma once
#include "UTGame__UTDataStore_GameSearchPersonal.h"
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
	};
}
#undef ADD_OBJECT
