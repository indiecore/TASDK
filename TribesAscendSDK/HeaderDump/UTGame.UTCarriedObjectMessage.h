#pragma once
#include "UTGame.UTLocalMessage.h"
#include "UTGame.UTQueuedAnnouncement.h"
#include "Engine.SoundNodeWave.h"
#include "Engine.PlayerController.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Core.Object.h"
#include "UTGame.UTAnnouncer.h"
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
		void ClientReceive(class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObjectMessage.ClientReceive");
			byte* params = (byte*)malloc(20);
			*(class PlayerController**)params = P;
			*(int*)(params + 4) = Switch;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 12) = RelatedPRI;
			*(class Object**)(params + 16) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class SoundNodeWave* AnnouncementSound(int MessageIndex, class Object* OptionalObject, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObjectMessage.AnnouncementSound");
			byte* params = (byte*)malloc(16);
			*(int*)params = MessageIndex;
			*(class Object**)(params + 4) = OptionalObject;
			*(class PlayerController**)(params + 8) = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SoundNodeWave**)(params + 12);
			free(params);
			return returnVal;
		}
		byte AnnouncementLevel(byte MessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObjectMessage.AnnouncementLevel");
			byte* params = (byte*)malloc(2);
			*params = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObjectMessage.GetString");
			byte* params = (byte*)malloc(32);
			*(int*)params = Switch;
			*(bool*)(params + 4) = bPRI1HUD;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 12) = RelatedPRI;
			*(class Object**)(params + 16) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 20);
			free(params);
			return returnVal;
		}
		bool ShouldBeRemoved(class UTQueuedAnnouncement* MyAnnouncement, ScriptClass* NewAnnouncementClass, int NewMessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObjectMessage.ShouldBeRemoved");
			byte* params = (byte*)malloc(16);
			*(class UTQueuedAnnouncement**)params = MyAnnouncement;
			*(ScriptClass**)(params + 4) = NewAnnouncementClass;
			*(int*)(params + 8) = NewMessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool ShouldRemoveFlagAnnouncement(int MyMessageIndex, ScriptClass* NewAnnouncementClass, int NewMessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObjectMessage.ShouldRemoveFlagAnnouncement");
			byte* params = (byte*)malloc(16);
			*(int*)params = MyMessageIndex;
			*(ScriptClass**)(params + 4) = NewAnnouncementClass;
			*(int*)(params + 8) = NewMessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool AddAnnouncement(class UTAnnouncer* Announcer, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObjectMessage.AddAnnouncement");
			byte* params = (byte*)malloc(20);
			*(class UTAnnouncer**)params = Announcer;
			*(int*)(params + 4) = MessageIndex;
			*(class PlayerReplicationInfo**)(params + 8) = PRI;
			*(class Object**)(params + 12) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool PartiallyDuplicates(int Switch1, int Switch2, class Object* OptionalObject1, class Object* OptionalObject2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObjectMessage.PartiallyDuplicates");
			byte* params = (byte*)malloc(20);
			*(int*)params = Switch1;
			*(int*)(params + 4) = Switch2;
			*(class Object**)(params + 8) = OptionalObject1;
			*(class Object**)(params + 12) = OptionalObject2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
