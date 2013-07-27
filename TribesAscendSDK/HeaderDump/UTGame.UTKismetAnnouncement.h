#pragma once
#include "UTGame.UTObjectiveSpecificMessage.h"
#include "UDKBase.UDKPlayerController.h"
#include "Core.Object.h"
#include "Engine.PlayerController.h"
namespace UnrealScript
{
	class UTKismetAnnouncement : public UTObjectiveSpecificMessage
	{
	public:
		UDKPlayerController::ObjectiveAnnouncementInfo GetObjectiveAnnouncement(byte MessageIndex, class Object* Objective, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTKismetAnnouncement.GetObjectiveAnnouncement");
			byte params[25] = { NULL };
			params[0] = MessageIndex;
			*(class Object**)&params[4] = Objective;
			*(class PlayerController**)&params[8] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UDKPlayerController::ObjectiveAnnouncementInfo*)&params[12];
		}
		byte AnnouncementLevel(byte MessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTKismetAnnouncement.AnnouncementLevel");
			byte params[2] = { NULL };
			params[0] = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[1];
		}
	};
}
