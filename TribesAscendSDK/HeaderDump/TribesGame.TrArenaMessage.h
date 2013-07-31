#pragma once
#include "UTGame.UTLocalMessage.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Core.Object.h"
#include "Engine.PlayerController.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrArenaMessage : public UTLocalMessage
	{
	public:
		ADD_STRUCT(ScriptString*, WeLostTheRound, 196)
		ADD_STRUCT(ScriptString*, WeWonTheRound, 184)
		ADD_STRUCT(ScriptString*, CannotSwitchTeam, 172)
		ADD_STRUCT(ScriptString*, NoRespawnsRemain, 160)
		ADD_STRUCT(ScriptString*, Fight, 148)
		ADD_STRUCT(ScriptString*, YouAreLastManStanding, 136)
		ADD_STRUCT(ScriptString*, TeamRespawnsDepleted, 124)
		ADD_STRUCT(ScriptString*, FiveTeamRespawnsRemain, 112)
		ADD_STRUCT(ScriptString*, TenTeamRespawnsRemain, 100)
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66564);
			byte params[32] = { NULL };
			*(int*)params = Switch;
			*(bool*)&params[4] = bPRI1HUD;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		void ClientReceive(class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66571);
			byte params[20] = { NULL };
			*(class PlayerController**)params = P;
			*(int*)&params[4] = Switch;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
