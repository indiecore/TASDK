#pragma once
#include "Engine__ReplicationInfo.h"
#include "Engine__TeamInfo.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKTeamOwnedInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKTeamOwnedInfo : public ReplicationInfo
	{
	public:
		ADD_OBJECT(TeamInfo, Team)
		// Here lies the not-yet-implemented method 'GetTeamNum'
	};
}
#undef ADD_OBJECT
