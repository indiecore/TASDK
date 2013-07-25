#pragma once
#include "UTGame__UTQueuedAnnouncement.h"
#include "Engine__PlayerController.h"
#include "UTGame__UTLocalMessage.h"
#include "UTGame__UTAnnouncer.h"
#include "Engine__SoundNodeWave.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTMultiKillMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTMultiKillMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTMultiKillMessage : public UTLocalMessage
	{
	public:
		ADD_OBJECT(SoundNodeWave, KillSound)
		ADD_VAR(::StrProperty, KillString, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetString'
		// Here lies the not-yet-implemented method 'ClientReceive'
		// Here lies the not-yet-implemented method 'AnnouncementSound'
		// Here lies the not-yet-implemented method 'GetFontSize'
		// Here lies the not-yet-implemented method 'ShouldBeRemoved'
		// Here lies the not-yet-implemented method 'AddAnnouncement'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
