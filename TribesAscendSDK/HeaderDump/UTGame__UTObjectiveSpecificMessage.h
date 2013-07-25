#pragma once
#include "Engine__PlayerController.h"
#include "UTGame__UTLocalMessage.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Core__Object.h"
#include "Engine__SoundNodeWave.h"
namespace UnrealScript
{
	class UTObjectiveSpecificMessage : public UTLocalMessage
	{
	public:
		
// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPlayerController.ObjectiveAnnouncementInfo'!
void* GetObjectiveAnnouncement(byte MessageIndex, class Object* Objective, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTObjectiveSpecificMessage.GetObjectiveAnnouncement");
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
		class SoundNodeWave* AnnouncementSound(int MessageIndex, class Object* OptionalObject, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTObjectiveSpecificMessage.AnnouncementSound");
			byte* params = (byte*)malloc(16);
			*(int*)params = MessageIndex;
			*(class Object**)(params + 4) = OptionalObject;
			*(class PlayerController**)(params + 8) = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SoundNodeWave**)(params + 12);
			free(params);
			return returnVal;
		}
		void ClientReceive(class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTObjectiveSpecificMessage.ClientReceive");
			byte* params = (byte*)malloc(20);
			*(class PlayerController**)params = P;
			*(int*)(params + 4) = Switch;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 12) = RelatedPRI;
			*(class Object**)(params + 16) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTObjectiveSpecificMessage.GetString");
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
		void SetHUDDisplay(class PlayerController* P, int Switch, ScriptArray<wchar_t> Text, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTObjectiveSpecificMessage.SetHUDDisplay");
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
