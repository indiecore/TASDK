#pragma once
#include "UTGame.UTLocalMessage.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrWarningMessage : public UTLocalMessage
	{
	public:
		ADD_STRUCT(ScriptString*, RequiresPowerToFire, 184)
		ADD_STRUCT(ScriptString*, RequiresCreditsToFire, 172)
		ADD_STRUCT(ScriptString*, SuicidePenalty, 160)
		ADD_STRUCT(ScriptString*, MissileIntercepted, 148)
		ADD_STRUCT(ScriptString*, MissileTargetingYou, 136)
		ADD_STRUCT(ScriptString*, MissileLockedOnToYou, 124)
		ADD_STRUCT(ScriptString*, SaberLauncherNeedsTargetToFire, 112)
		ADD_STRUCT(ScriptString*, FumbledFlag, 100)
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrWarningMessage.GetString");
			byte params[32] = { NULL };
			*(int*)&params[0] = Switch;
			*(bool*)&params[4] = bPRI1HUD;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
	};
}
#undef ADD_STRUCT
