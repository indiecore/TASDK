#pragma once
#include "Engine.Info.h"
#include "Engine.SoundCue.h"
#include "UTGame.UTQueuedAnnouncement.h"
#include "UTGame.UTPlayerController.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Core.Object.h"
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
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAnnouncer.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAnnouncer.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayNextAnnouncement()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAnnouncer.PlayNextAnnouncement");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayAnnouncementNow(ScriptClass* InMessageClass, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAnnouncer.PlayAnnouncementNow");
			byte* params = (byte*)malloc(16);
			*(ScriptClass**)params = InMessageClass;
			*(int*)(params + 4) = MessageIndex;
			*(class PlayerReplicationInfo**)(params + 8) = PRI;
			*(class Object**)(params + 12) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AnnouncementFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAnnouncer.AnnouncementFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = AC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayAnnouncement(ScriptClass* InMessageClass, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAnnouncer.PlayAnnouncement");
			byte* params = (byte*)malloc(16);
			*(ScriptClass**)params = InMessageClass;
			*(int*)(params + 4) = MessageIndex;
			*(class PlayerReplicationInfo**)(params + 8) = PRI;
			*(class Object**)(params + 12) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
