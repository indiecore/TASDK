#pragma once
#include "Engine.ReplicationInfo.h"
#include "Engine.TeamInfo.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UDKTeamOwnedInfo : public ReplicationInfo
	{
	public:
		ADD_OBJECT(TeamInfo, Team, 476)
		byte GetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKTeamOwnedInfo.GetTeamNum");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[0];
		}
	};
}
#undef ADD_OBJECT
