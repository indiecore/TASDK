#pragma once
#include "Engine.SequenceAction.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTSeqAct_ChangeTeam : public SequenceAction
	{
	public:
		ADD_STRUCT(byte, NewTeamNum, 232)
		void Activated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49075);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
