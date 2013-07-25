#pragma once
#include "Engine__PlayerReplicationInfo.h"
#include "Core__Object.h"
#include "UTGame__UTObjectiveSpecificMessage.h"
#include "UTGame__UTQueuedAnnouncement.h"
#include "Engine__PlayerController.h"
namespace UnrealScript
{
	class UTObjectiveAnnouncement : public UTObjectiveSpecificMessage
	{
	public:
		
// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPlayerController.ObjectiveAnnouncementInfo'!
void* GetObjectiveAnnouncement(byte MessageIndex, class Object* Objective, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTObjectiveAnnouncement.GetObjectiveAnnouncement");
			byte* params = (byte*)malloc(25);
			*params = MessageIndex;
			*(class Object**)(params + 4) = Objective;
			*(class PlayerController**)(params + 8) = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPlayerController.ObjectiveAnnouncementInfo'!
void**)(params + 12);
			free(params);
			return returnVal;
		}
		bool ShouldBeRemoved(class UTQueuedAnnouncement* MyAnnouncement, ScriptClass* NewAnnouncementClass, int NewMessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTObjectiveAnnouncement.ShouldBeRemoved");
			byte* params = (byte*)malloc(16);
			*(class UTQueuedAnnouncement**)params = MyAnnouncement;
			*(ScriptClass**)(params + 4) = NewAnnouncementClass;
			*(int*)(params + 8) = NewMessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void SetHUDDisplay(class PlayerController* P, int Switch, ScriptArray<wchar_t> Text, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTObjectiveAnnouncement.SetHUDDisplay");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = P;
			*(int*)(params + 4) = Switch;
			*(ScriptArray<wchar_t>*)(params + 8) = Text;
			*(class PlayerReplicationInfo**)(params + 20) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 24) = RelatedPRI;
			*(class Object**)(params + 28) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
