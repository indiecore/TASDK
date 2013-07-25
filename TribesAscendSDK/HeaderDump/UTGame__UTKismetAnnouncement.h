#pragma once
#include "Core__Object.h"
#include "UTGame__UTObjectiveSpecificMessage.h"
#include "Engine__PlayerController.h"
namespace UnrealScript
{
	class UTKismetAnnouncement : public UTObjectiveSpecificMessage
	{
	public:
		
// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPlayerController.ObjectiveAnnouncementInfo'!
void* GetObjectiveAnnouncement(byte MessageIndex, class Object* Objective, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTKismetAnnouncement.GetObjectiveAnnouncement");
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
		byte AnnouncementLevel(byte MessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTKismetAnnouncement.AnnouncementLevel");
			byte* params = (byte*)malloc(2);
			*params = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
	};
}
