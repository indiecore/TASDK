#pragma once
#include "Core.Object.h"
#include "Engine.LocalMessage.h"
#include "UTGame.UTQueuedAnnouncement.h"
#include "Engine.SoundNodeWave.h"
#include "Engine.PlayerController.h"
#include "Engine.HUD.h"
#include "UTGame.UTAnnouncer.h"
#include "Engine.PlayerReplicationInfo.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTLocalMessage : public LocalMessage
	{
	public:
		ADD_STRUCT(float, AnnouncementVolume, 92)
		ADD_BOOL(bShowPortrait, 88, 0x1)
		ADD_STRUCT(float, AnnouncementDelay, 96)
		ADD_STRUCT(int, AnnouncementPriority, 84)
		ADD_STRUCT(int, MessageArea, 80)
		class SoundNodeWave* AnnouncementSound(int MessageIndex, class Object* OptionalObject, class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40596);
			byte params[16] = { NULL };
			*(int*)params = MessageIndex;
			*(class Object**)&params[4] = OptionalObject;
			*(class PlayerController**)&params[8] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundNodeWave**)&params[12];
		}
		byte AnnouncementLevel(byte MessageIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40609);
			byte params[2] = { NULL };
			*params = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[1];
		}
		bool AddAnnouncement(class UTAnnouncer* Announcer, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40612);
			byte params[20] = { NULL };
			*(class UTAnnouncer**)params = Announcer;
			*(int*)&params[4] = MessageIndex;
			*(class PlayerReplicationInfo**)&params[8] = PRI;
			*(class Object**)&params[12] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool ShouldBeRemoved(class UTQueuedAnnouncement* MyAnnouncement, ScriptClass* NewAnnouncementClass, int NewMessageIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43797);
			byte params[16] = { NULL };
			*(class UTQueuedAnnouncement**)params = MyAnnouncement;
			*(ScriptClass**)&params[4] = NewAnnouncementClass;
			*(int*)&params[8] = NewMessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		float GetPos(int Switch, class HUD* myHUD)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43810);
			byte params[12] = { NULL };
			*(int*)params = Switch;
			*(class HUD**)&params[4] = myHUD;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		bool KilledByVictoryMessage(int AnnouncementIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43815);
			byte params[8] = { NULL };
			*(int*)params = AnnouncementIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
