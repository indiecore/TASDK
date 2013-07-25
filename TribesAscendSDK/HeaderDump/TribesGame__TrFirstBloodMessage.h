#pragma once
#include "UTGame__UTLocalMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrFirstBloodMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrFirstBloodMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, FirstBlood, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetString'
	};
}
#undef ADD_VAR
