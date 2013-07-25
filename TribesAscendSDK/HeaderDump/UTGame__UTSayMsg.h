#pragma once
#include "UTGame__UTLocalMessage.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTSayMsg." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTSayMsg : public UTLocalMessage
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'BlueTeamColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'RedTeamColor'!
		// Here lies the not-yet-implemented method 'GetConsoleColor'
	};
}
#undef ADD_STRUCT
