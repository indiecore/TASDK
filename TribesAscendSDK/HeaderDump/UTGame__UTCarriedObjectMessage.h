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
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTCarriedObjectMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCarriedObjectMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCarriedObjectMessage : public UTLocalMessage
	{
	public:
		ADD_OBJECT(SoundNodeWave, TakenSounds)
		ADD_OBJECT(SoundNodeWave, DroppedSounds)
		ADD_OBJECT(SoundNodeWave, ReturnSounds)
		ADD_VAR(::StrProperty, KilledRed, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, KilledBlue, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HasRed, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HasBlue, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DroppedRed, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DroppedBlue, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CaptureRed, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CaptureBlue, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ReturnedRed, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ReturnedBlue, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ReturnRed, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ReturnBlue, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'ClientReceive'
		// Here lies the not-yet-implemented method 'AnnouncementSound'
		// Here lies the not-yet-implemented method 'AnnouncementLevel'
		// Here lies the not-yet-implemented method 'GetString'
		// Here lies the not-yet-implemented method 'ShouldBeRemoved'
		// Here lies the not-yet-implemented method 'ShouldRemoveFlagAnnouncement'
		// Here lies the not-yet-implemented method 'AddAnnouncement'
		// Here lies the not-yet-implemented method 'PartiallyDuplicates'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
