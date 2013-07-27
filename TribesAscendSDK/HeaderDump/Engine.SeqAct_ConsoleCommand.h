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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_ConsoleCommand.VersionUpdated");
			byte params[8] = { NULL };
			*(int*)&params[0] = OldVersion;
			*(int*)&params[4] = NewVersion;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_ConsoleCommand.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_STRUCT
