#pragma once
#include "UTGame.UTLocalMessage.h"
#include "Core.Object.h"
#include "Engine.PlayerReplicationInfo.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTSayMsg : public UTLocalMessage
	{
	public:
		ADD_STRUCT(Object::Color, BlueTeamColor, 104)
		ADD_STRUCT(Object::Color, RedTeamColor, 100)
		Object::Color GetConsoleColor(class PlayerReplicationInfo* RelatedPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSayMsg.GetConsoleColor");
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = RelatedPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Color*)&params[4];
		}
	};
}
#undef ADD_STRUCT
