#pragma once
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__SoundCue.h"
#include "Engine__Info.h"
#include "UTGame__UTPlayerController.h"
#include "UTGame__UTQueuedAnnouncement.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTAnnouncer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTAnnouncer." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTAnnouncer : public Info
	{
	public:
		ADD_VAR(::StrProperty, UTVoiceSoundCueSoundCue, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, UTVoiceSoundCue)
		ADD_VAR(::StrProperty, CustomAnnouncerSoundCue, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, AnnouncerSoundCue)
		ADD_OBJECT(UTPlayerController, PlayerOwner)
		ADD_OBJECT(UTQueuedAnnouncement, Queue)
		ADD_VAR(::IntProperty, PlayingAnnouncementIndex, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, PlayingAnnouncementClass)
		ADD_VAR(::ByteProperty, AnnouncerLevel, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'PlayNextAnnouncement'
		// Here lies the not-yet-implemented method 'PlayAnnouncementNow'
		// Here lies the not-yet-implemented method 'AnnouncementFinished'
		// Here lies the not-yet-implemented method 'PlayAnnouncement'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
