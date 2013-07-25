#pragma once
#include "UTGame__UTLocalMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTLockWarningMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTLockWarningMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTLockWarningMessage : public UTLocalMessage
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'YellowColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'RedColor'!
		ADD_VAR(::StrProperty, RadarLockString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MissileLockOnString, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'AnnouncementLevel'
		// Here lies the not-yet-implemented method 'GetString'
		// Here lies the not-yet-implemented method 'GetColor'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
