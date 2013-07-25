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
		class SoundNodeWave* AnnouncementSound(int MessageIndex, class Object* OptionalObject, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTLocalMessage.AnnouncementSound");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTLocalMessage.AnnouncementLevel");
			byte* params = (byte*)malloc(2);
			*params = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		bool AddAnnouncement(class UTAnnouncer* Announcer, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTLocalMessage.AddAnnouncement");
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
		bool ShouldBeRemoved(class UTQueuedAnnouncement* MyAnnouncement, ScriptClass* NewAnnouncementClass, int NewMessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTLocalMessage.ShouldBeRemoved");
			byte* params = (byte*)malloc(16);
			*(class UTQueuedAnnouncement**)params = MyAnnouncement;
			*(ScriptClass**)(params + 4) = NewAnnouncementClass;
			*(int*)(params + 8) = NewMessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		float GetPos(int Switch, class HUD* myHUD)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTLocalMessage.GetPos");
			byte* params = (byte*)malloc(12);
			*(int*)params = Switch;
			*(class HUD**)(params + 4) = myHUD;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		bool KilledByVictoryMessage(int AnnouncementIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTLocalMessage.KilledByVictoryMessage");
			byte* params = (byte*)malloc(8);
			*(int*)params = AnnouncementIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
