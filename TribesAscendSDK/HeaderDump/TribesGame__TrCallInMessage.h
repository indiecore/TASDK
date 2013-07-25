#pragma once
#include "UTGame__UTLocalMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCallInMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrCallInMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, PlayerCalledInTacticalStrike, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PlayerCalledInOrbitalStrike, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PlayerCalledInSupportInventory, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetString'
	};
}
#undef ADD_VAR
