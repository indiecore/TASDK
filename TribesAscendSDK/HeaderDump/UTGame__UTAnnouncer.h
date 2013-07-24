#pragma once
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
		ADD_VAR(::ByteProperty, AnnouncerLevel, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
