#pragma once
#include "UTGame.UTLocalMessage.h"
#include "Engine.PlayerReplicationInfo.h"
#include "UDKBase.UDKPlayerController.h"
#include "Core.Object.h"
#include "Engine.PlayerController.h"
#include "Engine.SoundNodeWave.h"
namespace UnrealScript
{
	class UTObjectiveSpecificMessage : public UTLocalMessage
	{
	public:
		UDKPlayerController::ObjectiveAnnouncementInfo GetObjectiveAnnouncement(byte MessageIndex, class Object* Objective, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTObjectiveSpecificMessage.GetObjectiveAnnouncement");
			byte params[25] = { NULL };
			params[0] = MessageIndex;
			*(class Object**)&params[4] = Objective;
			*(class PlayerController**)&params[8] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UDKPlayerController::ObjectiveAnnouncementInfo*)&params[12];
		}
		class SoundNodeWave* AnnouncementSound(int MessageIndex, class Object* OptionalObject, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTObjectiveSpecificMessage.AnnouncementSound");
			byte params[16] = { NULL };
			*(int*)&params[0] = MessageIndex;
			*(class Object**)&params[4] = OptionalObject;
			*(class PlayerController**)&params[8] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundNodeWave**)&params[12];
		}
		void ClientReceive(class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTObjectiveSpecificMessage.ClientReceive");
			byte params[20] = { NULL };
			*(class PlayerController**)&params[0] = P;
			*(int*)&params[4] = Switch;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTObjectiveSpecificMessage.GetString");
			byte params[32] = { NULL };
			*(int*)&params[0] = Switch;
			*(bool*)&params[4] = bPRI1HUD;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		void SetHUDDisplay(class PlayerController* P, int Switch, ScriptString* Text, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTObjectiveSpecificMessage.SetHUDDisplay");
			byte params[32] = { NULL };
			*(class PlayerController**)&params[0] = P;
			*(int*)&params[4] = Switch;
			*(ScriptString**)&params[8] = Text;
			*(class PlayerReplicationInfo**)&params[20] = RelatedPRI;
			*(class PlayerReplicationInfo**)&params[24] = RelatedPRI;
			*(class Object**)&params[28] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
