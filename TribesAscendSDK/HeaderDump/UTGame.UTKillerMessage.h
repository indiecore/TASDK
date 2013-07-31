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
	class UTKillerMessage : public UTWeaponKillMessage
	{
	public:
		ADD_STRUCT(ScriptString*, OtherKilledTrailer, 172)
		ADD_STRUCT(ScriptString*, OtherKilled, 160)
		ADD_STRUCT(ScriptString*, OtherKilledPrefix, 148)
		ADD_STRUCT(ScriptString*, YouTeamKilledTrailer, 136)
		ADD_STRUCT(ScriptString*, YouTeamKilled, 124)
		ADD_STRUCT(ScriptString*, YouKilledTrailer, 112)
		ADD_STRUCT(ScriptString*, YouKilled, 100)
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47037);
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
