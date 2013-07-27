#pragma once
#include "Engine.SequenceAction.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_ConsoleCommand : public SequenceAction
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptString*>, Commands, 244)
		ADD_STRUCT(ScriptString*, Command, 232)
		void VersionUpdated(int OldVersion, int NewVersion)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25645);
			byte params[8] = { NULL };
			*(int*)params = OldVersion;
			*(int*)&params[4] = NewVersion;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25648);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_STRUCT
