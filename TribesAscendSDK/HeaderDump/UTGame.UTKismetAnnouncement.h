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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48265);
			byte params[25] = { NULL };
			*params = MessageIndex;
			*(class Object**)&params[4] = Objective;
			*(class PlayerController**)&params[8] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UDKPlayerController::ObjectiveAnnouncementInfo*)&params[12];
		}
		byte AnnouncementLevel(byte MessageIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48274);
			byte params[2] = { NULL };
			*params = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[1];
		}
	};
}
