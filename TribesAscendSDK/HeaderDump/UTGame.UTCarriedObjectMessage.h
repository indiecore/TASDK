#pragma once
#include "UTGame.UTLocalMessage.h"
#include "UTGame.UTQueuedAnnouncement.h"
#include "Engine.SoundNodeWave.h"
#include "Engine.PlayerController.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Core.Object.h"
#include "UTGame.UTAnnouncer.h"
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
	class UTCarriedObjectMessage : public UTLocalMessage
	{
	public:
		ADD_OBJECT(SoundNodeWave, TakenSounds, 260)
		ADD_OBJECT(SoundNodeWave, DroppedSounds, 252)
		ADD_OBJECT(SoundNodeWave, ReturnSounds, 244)
		ADD_STRUCT(ScriptString*, KilledRed, 232)
		ADD_STRUCT(ScriptString*, KilledBlue, 220)
		ADD_STRUCT(ScriptString*, HasRed, 208)
		ADD_STRUCT(ScriptString*, HasBlue, 196)
		ADD_STRUCT(ScriptString*, DroppedRed, 184)
		ADD_STRUCT(ScriptString*, DroppedBlue, 172)
		ADD_STRUCT(ScriptString*, CaptureRed, 160)
		ADD_STRUCT(ScriptString*, CaptureBlue, 148)
		ADD_STRUCT(ScriptString*, ReturnedRed, 136)
		ADD_STRUCT(ScriptString*, ReturnedBlue, 124)
		ADD_STRUCT(ScriptString*, ReturnRed, 112)
		ADD_STRUCT(ScriptString*, ReturnBlue, 100)
		void ClientReceive(class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObjectMessage.ClientReceive");
			byte params[20] = { NULL };
			*(class PlayerController**)&params[0] = P;
			*(int*)&params[4] = Switch;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class SoundNodeWave* AnnouncementSound(int MessageIndex, class Object* OptionalObject, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObjectMessage.AnnouncementSound");
			byte params[16] = { NULL };
			*(int*)&params[0] = MessageIndex;
			*(class Object**)&params[4] = OptionalObject;
			*(class PlayerController**)&params[8] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundNodeWave**)&params[12];
		}
		byte AnnouncementLevel(byte MessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObjectMessage.AnnouncementLevel");
			byte params[2] = { NULL };
			params[0] = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[1];
		}
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObjectMessage.GetString");
			byte params[32] = { NULL };
			*(int*)&params[0] = Switch;
			*(bool*)&params[4] = bPRI1HUD;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		bool ShouldBeRemoved(class UTQueuedAnnouncement* MyAnnouncement, ScriptClass* NewAnnouncementClass, int NewMessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObjectMessage.ShouldBeRemoved");
			byte params[16] = { NULL };
			*(class UTQueuedAnnouncement**)&params[0] = MyAnnouncement;
			*(ScriptClass**)&params[4] = NewAnnouncementClass;
			*(int*)&params[8] = NewMessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ShouldRemoveFlagAnnouncement(int MyMessageIndex, ScriptClass* NewAnnouncementClass, int NewMessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObjectMessage.ShouldRemoveFlagAnnouncement");
			byte params[16] = { NULL };
			*(int*)&params[0] = MyMessageIndex;
			*(ScriptClass**)&params[4] = NewAnnouncementClass;
			*(int*)&params[8] = NewMessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool AddAnnouncement(class UTAnnouncer* Announcer, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObjectMessage.AddAnnouncement");
			byte params[20] = { NULL };
			*(class UTAnnouncer**)&params[0] = Announcer;
			*(int*)&params[4] = MessageIndex;
			*(class PlayerReplicationInfo**)&params[8] = PRI;
			*(class Object**)&params[12] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool PartiallyDuplicates(int Switch1, int Switch2, class Object* OptionalObject1, class Object* OptionalObject2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObjectMessage.PartiallyDuplicates");
			byte params[20] = { NULL };
			*(int*)&params[0] = Switch1;
			*(int*)&params[4] = Switch2;
			*(class Object**)&params[8] = OptionalObject1;
			*(class Object**)&params[12] = OptionalObject2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
