#pragma once
#include "Core.Object.h"
#include "UTGame.UTWeaponKillMessage.h"
#include "Engine.PlayerReplicationInfo.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTVictimMessage : public UTWeaponKillMessage
	{
	public:
		ADD_STRUCT(ScriptString*, TelefragString, 184)
		ADD_STRUCT(ScriptString*, ViperKamikazeString, 172)
		ADD_STRUCT(ScriptString*, ScorpionKamikazeString, 160)
		ADD_STRUCT(ScriptString*, SpiderMineString, 148)
		ADD_STRUCT(ScriptString*, RunOverString, 136)
		ADD_STRUCT(ScriptString*, OrbSuicideString, 124)
		ADD_STRUCT(ScriptString*, KilledByTrailer, 112)
		ADD_STRUCT(ScriptString*, YouWereKilledBy, 100)
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVictimMessage.GetString");
			byte params[32] = { NULL };
			*(int*)&params[0] = Switch;
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
