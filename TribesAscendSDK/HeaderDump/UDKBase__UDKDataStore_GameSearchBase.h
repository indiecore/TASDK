#pragma once
#include "Engine__UIDataStore_OnlineGameSearch.h"
#include "UDKBase__UDKUIDataProvider_ServerDetails.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKDataStore_GameSearchBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKDataStore_GameSearchBase : public UIDataStore_OnlineGameSearch
	{
	public:
		ADD_OBJECT(UDKUIDataProvider_ServerDetails, ServerDetailsProvider)
		// Here lies the not-yet-implemented method 'GetEnabledMutators'
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'SubmitGameSearch'
		// Here lies the not-yet-implemented method 'OnSearchComplete'
		// Here lies the not-yet-implemented method 'HasOutstandingQueries'
		// Here lies the not-yet-implemented method 'HasExistingSearchResults'
	};
}
#undef ADD_OBJECT
