#pragma once
#include "Engine.SequenceCondition.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqCond_IsLoggedIn : public SequenceCondition
	{
	public:
		ADD_STRUCT(int, NumNeededLoggedIn, 208)
		bool CheckLogins()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26031);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_STRUCT
