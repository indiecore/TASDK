#pragma once
#include "Engine__PlayerController.h"
#include "UTGame__UTLocalMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
namespace UnrealScript
{
	class TrTDMScoreMessage : public UTLocalMessage
	{
	public:
		byte AnnouncementLevel(byte MessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTDMScoreMessage.AnnouncementLevel");
			byte* params = (byte*)malloc(2);
			*params = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		void ClientReceive(class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTDMScoreMessage.ClientReceive");
			byte* params = (byte*)malloc(20);
			*(class PlayerController**)params = P;
			*(int*)(params + 4) = Switch;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 12) = RelatedPRI;
			*(class Object**)(params + 16) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
