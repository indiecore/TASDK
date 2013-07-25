#pragma once
#include "Engine__PlayerController.h"
#include "UTGame__UTLocalMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#include "UTGame__UTAnnouncer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCTFHUDMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrCTFHUDMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrCTFHUDMessage : public UTLocalMessage
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'YellowColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'RedColor'!
		ADD_VAR(::StrProperty, YouHaveFlagReminderString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BothFlagsString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EnemyHasFlagString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouHaveFlagString, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'ClientReceive'
		// Here lies the not-yet-implemented method 'GetColor'
		// Here lies the not-yet-implemented method 'GetString'
		// Here lies the not-yet-implemented method 'AddAnnouncement'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
