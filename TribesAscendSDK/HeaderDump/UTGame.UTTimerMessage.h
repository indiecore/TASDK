#pragma once
#include "UTGame.UTLocalMessage.h"
#include "Engine.PlayerReplicationInfo.h"
#include "UDKBase.UDKPlayerController.h"
#include "Engine.PlayerController.h"
#include "Core.Object.h"
#include "Engine.SoundNodeWave.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTTimerMessage : public UTLocalMessage
	{
	public:
		ADD_STRUCT(ScriptArray<UDKPlayerController::ObjectiveAnnouncementInfo>, Announcements, 100)
		void ClientReceive(class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimerMessage.ClientReceive");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimerMessage.GetString");
			byte params[32] = { NULL };
			*(int*)&params[0] = Switch;
			*(bool*)&params[4] = bPRI1HUD;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		class SoundNodeWave* AnnouncementSound(int MessageIndex, class Object* OptionalObject, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimerMessage.AnnouncementSound");
			byte params[16] = { NULL };
			*(int*)&params[0] = MessageIndex;
			*(class Object**)&params[4] = OptionalObject;
			*(class PlayerController**)&params[8] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundNodeWave**)&params[12];
		}
		int GetFontSize(int Switch, class PlayerReplicationInfo* RelatedPRI1, class PlayerReplicationInfo* RelatedPRI2, class PlayerReplicationInfo* LocalPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimerMessage.GetFontSize");
			byte params[20] = { NULL };
			*(int*)&params[0] = Switch;
			*(class PlayerReplicationInfo**)&params[4] = RelatedPRI1;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI2;
			*(class PlayerReplicationInfo**)&params[12] = LocalPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[16];
		}
	};
}
#undef ADD_STRUCT
