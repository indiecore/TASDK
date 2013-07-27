#pragma once
#include "UTGame.UTObjectiveSpecificMessage.h"
#include "Engine.PlayerReplicationInfo.h"
#include "UDKBase.UDKPlayerController.h"
#include "Core.Object.h"
#include "Engine.PlayerController.h"
#include "UTGame.UTQueuedAnnouncement.h"
namespace UnrealScript
{
	class UTObjectiveAnnouncement : public UTObjectiveSpecificMessage
	{
	public:
		UDKPlayerController::ObjectiveAnnouncementInfo GetObjectiveAnnouncement(byte MessageIndex, class Object* Objective, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTObjectiveAnnouncement.GetObjectiveAnnouncement");
			byte params[25] = { NULL };
			params[0] = MessageIndex;
			*(class Object**)&params[4] = Objective;
			*(class PlayerController**)&params[8] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UDKPlayerController::ObjectiveAnnouncementInfo*)&params[12];
		}
		bool ShouldBeRemoved(class UTQueuedAnnouncement* MyAnnouncement, ScriptClass* NewAnnouncementClass, int NewMessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTObjectiveAnnouncement.ShouldBeRemoved");
			byte params[16] = { NULL };
			*(class UTQueuedAnnouncement**)&params[0] = MyAnnouncement;
			*(ScriptClass**)&params[4] = NewAnnouncementClass;
			*(int*)&params[8] = NewMessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void SetHUDDisplay(class PlayerController* P, int Switch, ScriptString* Text, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTObjectiveAnnouncement.SetHUDDisplay");
			byte params[32] = { NULL };
			*(class PlayerController**)&params[0] = P;
			*(int*)&params[4] = Switch;
			*(ScriptString**)&params[8] = Text;
			*(class PlayerReplicationInfo**)&params[20] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[24] = RelatedPRI_2;
			*(class Object**)&params[28] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
