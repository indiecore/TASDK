#pragma once
#include "UDKBase__UDKDataStore_GameSearchBase.h"
#include "Engine__OnlineGameSearch.h"
#include "UTGame__UTDataStore_GameSearchDM.h"
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
		// Here lies the not-yet-implemented method 'HasOutstandingQueries'
		// Here lies the not-yet-implemented method 'OverrideQuerySubmission'
		// Here lies the not-yet-implemented method 'GetPlayerName'
		// Here lies the not-yet-implemented method 'GetPlayerNetId'
		// Here lies the not-yet-implemented method 'FindServerIndexByString'
		// Here lies the not-yet-implemented method 'FindServerIndexById'
		// Here lies the not-yet-implemented method 'AddServer'
		// Here lies the not-yet-implemented method 'RemoveServer'
		// Here lies the not-yet-implemented method 'GetServerIdList'
		// Here lies the not-yet-implemented method 'GetServerStringList'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
