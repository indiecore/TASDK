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
	class FailedConnect : public LocalMessage
	{
	public:
		ADD_STRUCT(ScriptString*, FailMessage, 80)
		int GetFailSwitch(ScriptString* FailString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FailedConnect.GetFailSwitch");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = FailString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FailedConnect.GetString");
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
