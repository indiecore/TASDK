#pragma once
#include "Engine__PlayerController.h"
#include "UTGame__UTLocalMessage.h"
#include "UTGame__UTAnnouncer.h"
#include "Engine__SoundNodeWave.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Core__Object.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTVictoryMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTVictoryMessage : public UTLocalMessage
	{
	public:
		ADD_OBJECT(SoundNodeWave, VictorySounds)
		// Here lies the not-yet-implemented method 'AnnouncementLevel'
		// Here lies the not-yet-implemented method 'AnnouncementSound'
		// Here lies the not-yet-implemented method 'ClientReceive'
		// Here lies the not-yet-implemented method 'AddAnnouncement'
	};
}
#undef ADD_OBJECT
