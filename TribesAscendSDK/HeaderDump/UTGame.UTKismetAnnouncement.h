#pragma once
#include "UTGame.UTObjectiveSpecificMessage.h"
#include "UDKBase.UDKPlayerController.ObjectiveAnnouncementInfo.h"
#include "Core.Object.h"
#include "Engine.PlayerController.h"
namespace UnrealScript
{
	class UTKismetAnnouncement : public UTObjectiveSpecificMessage
	{
	public:
		ObjectiveAnnouncementInfo GetObjectiveAnnouncement(byte MessageIndex, class Object* Objective, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTKismetAnnouncement.GetObjectiveAnnouncement");
			byte* params = (byte*)malloc(25);
			*params = MessageIndex;
			*(class Object**)(params + 4) = Objective;
			*(class PlayerController**)(params + 8) = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ObjectiveAnnouncementInfo*)(params + 12);
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
