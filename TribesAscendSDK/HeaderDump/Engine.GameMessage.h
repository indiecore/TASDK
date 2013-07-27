#pragma once
#include "Core.Object.h"
#include "Engine.LocalMessage.h"
#include "Engine.PlayerReplicationInfo.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class GameMessage : public LocalMessage
	{
	public:
		ADD_STRUCT(ScriptString*, MaxedOutMessage, 152)
		ADD_STRUCT(ScriptString*, SpecEnteredMessage, 344)
		ADD_STRUCT(ScriptString*, NewSpecMessage, 332)
		ADD_STRUCT(ScriptString*, KickWarning, 320)
		ADD_STRUCT(ScriptString*, NewPlayerMessage, 308)
		ADD_STRUCT(ScriptString*, BecameSpectator, 296)
		ADD_STRUCT(ScriptString*, CantBePlayer, 284)
		ADD_STRUCT(ScriptString*, CantBeSpectator, 272)
		ADD_STRUCT(ScriptString*, MustHaveStats, 260)
		ADD_STRUCT(ScriptString*, VotePassed, 248)
		ADD_STRUCT(ScriptString*, VoteStarted, 236)
		ADD_STRUCT(ScriptString*, NoNameChange, 224)
		ADD_STRUCT(ScriptString*, NewTeamMessageTrailer, 212)
		ADD_STRUCT(ScriptString*, NewTeamMessage, 200)
		ADD_STRUCT(ScriptString*, GlobalNameChange, 188)
		ADD_STRUCT(ScriptString*, OvertimeMessage, 176)
		ADD_STRUCT(ScriptString*, ArbitrationMessage, 164)
		ADD_STRUCT(ScriptString*, EnteredMessage, 140)
		ADD_STRUCT(ScriptString*, FailedSpawnMessage, 128)
		ADD_STRUCT(ScriptString*, FailedPlaceMessage, 116)
		ADD_STRUCT(ScriptString*, FailedTeamMessage, 104)
		ADD_STRUCT(ScriptString*, LeftMessage, 92)
		ADD_STRUCT(ScriptString*, SwitchLevelMessage, 80)
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17462);
			byte params[32] = { NULL };
			*(int*)params = Switch;
			*(bool*)&params[4] = bPRI1HUD;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
	};
}
#undef ADD_STRUCT
