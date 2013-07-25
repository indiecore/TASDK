#pragma once
#include "Engine__SequenceEvent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqEvent_Console." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_Console : public SequenceEvent
	{
	public:
		ADD_VAR(::StrProperty, EventDesc, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ConsoleEventName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
