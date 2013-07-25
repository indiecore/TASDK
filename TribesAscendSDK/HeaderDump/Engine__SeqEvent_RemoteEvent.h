#pragma once
#include "Engine__SequenceEvent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqEvent_RemoteEvent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_RemoteEvent : public SequenceEvent
	{
	public:
		ADD_VAR(::BoolProperty, bStatusIsOk, 0x1)
		ADD_VAR(::NameProperty, EventName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
