#pragma once
#include "Engine.SeqAct_SetSequenceVariable.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_SetString : public SeqAct_SetSequenceVariable
	{
	public:
		ADD_STRUCT(ScriptString*, Value, 244)
		ADD_STRUCT(ScriptString*, Target, 232)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25933);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_STRUCT
