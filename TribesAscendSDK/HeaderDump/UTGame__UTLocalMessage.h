#pragma once
#include "Engine__LocalMessage.h"
#include "UTGame__UTAnnouncer.h"
#include "Engine__SoundNodeWave.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Core__Object.h"
#include "UTGame__UTQueuedAnnouncement.h"
#include "Engine__PlayerController.h"
#include "Engine__HUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTLocalMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTLocalMessage : public LocalMessage
	{
	public:
		ADD_VAR(::FloatProperty, AnnouncementVolume, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShowPortrait, 0x1)
		ADD_VAR(::FloatProperty, AnnouncementDelay, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AnnouncementPriority, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MessageArea, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'AnnouncementSound'
		// Here lies the not-yet-implemented method 'AnnouncementLevel'
		// Here lies the not-yet-implemented method 'AddAnnouncement'
		// Here lies the not-yet-implemented method 'ShouldBeRemoved'
		// Here lies the not-yet-implemented method 'GetPos'
		// Here lies the not-yet-implemented method 'KilledByVictoryMessage'
	};
}
#undef ADD_VAR
