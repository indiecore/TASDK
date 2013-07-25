#pragma once
#include "UDKBase__UDKDataStore_GameSearchBase.h"
#include "UTGame__UTDataStore_GameSearchHistory.h"
#include "Engine__LocalPlayer.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTDataStore_GameSearchDM." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTDataStore_GameSearchDM : public UDKDataStore_GameSearchBase
	{
	public:
		ADD_OBJECT(UTDataStore_GameSearchHistory, HistoryGameSearchDataStore)
		ADD_OBJECT(ScriptClass, HistoryGameSearchDataStoreClass)
		// Here lies the not-yet-implemented method 'Registered'
		// Here lies the not-yet-implemented method 'SubmitGameSearch'
		// Here lies the not-yet-implemented method 'HasOutstandingQueries'
		// Here lies the not-yet-implemented method 'FindStoredSearchIndex'
		// Here lies the not-yet-implemented method 'FindStoredSettingValueIndex'
		// Here lies the not-yet-implemented method 'LoadGameSearchParameters'
		// Here lies the not-yet-implemented method 'SaveGameSearchParameters'
	};
}
#undef ADD_OBJECT
