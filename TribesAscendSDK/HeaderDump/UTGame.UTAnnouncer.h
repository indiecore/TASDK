#pragma once
#include "Engine.Info.h"
#include "Engine.SoundCue.h"
#include "UTGame.UTQueuedAnnouncement.h"
#include "UTGame.UTPlayerController.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTAnnouncer : public Info
	{
	public:
		ADD_STRUCT(ScriptString*, UTVoiceSoundCueSoundCue, 516)
		ADD_OBJECT(SoundCue, UTVoiceSoundCue, 512)
		ADD_STRUCT(ScriptString*, CustomAnnouncerSoundCue, 500)
		ADD_OBJECT(SoundCue, AnnouncerSoundCue, 496)
		ADD_OBJECT(UTPlayerController, PlayerOwner, 492)
		ADD_OBJECT(UTQueuedAnnouncement, Queue, 488)
		ADD_STRUCT(int, PlayingAnnouncementIndex, 484)
		ADD_OBJECT(ScriptClass, PlayingAnnouncementClass, 480)
		ADD_STRUCT(byte, AnnouncerLevel, 476)
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40579);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40582);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayNextAnnouncement()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40583);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayAnnouncementNow(ScriptClass* InMessageClass, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40589);
			byte params[16] = { NULL };
			*(ScriptClass**)params = InMessageClass;
			*(int*)&params[4] = MessageIndex;
			*(class PlayerReplicationInfo**)&params[8] = PRI;
			*(class Object**)&params[12] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AnnouncementFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40602);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = AC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayAnnouncement(ScriptClass* InMessageClass, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40604);
			byte params[16] = { NULL };
			*(ScriptClass**)params = InMessageClass;
			*(int*)&params[4] = MessageIndex;
			*(class PlayerReplicationInfo**)&params[8] = PRI;
			*(class Object**)&params[12] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
