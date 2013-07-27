#pragma once
#include "Engine.SequenceEvent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_Console : public SequenceEvent
	{
	public:
		ADD_STRUCT(ScriptString*, EventDesc, 264)
		ADD_STRUCT(ScriptName, ConsoleEventName, 256)
	};
}
#undef ADD_STRUCT
