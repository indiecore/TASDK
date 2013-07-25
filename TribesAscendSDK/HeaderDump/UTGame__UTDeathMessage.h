#pragma once
#include "Engine__PlayerController.h"
#include "UTGame__UTLocalMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTDeathMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTDeathMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::BoolProperty, bNoConsoleDeathMessages, 0x1)
		ADD_VAR(::StrProperty, SomeoneString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, KilledString, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetConsoleColor'
		// Here lies the not-yet-implemented method 'GetString'
		// Here lies the not-yet-implemented method 'ClientReceive'
	};
}
#undef ADD_VAR
