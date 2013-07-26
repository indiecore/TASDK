#pragma once
#include "Engine.Actor.h"
#include "Engine.SequenceEvent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Sequence.QueuedActivationInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Sequence.QueuedActivationInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class QueuedActivationInfo
	{
	public:
		ADD_VAR(::BoolProperty, bPushTop, 0x1)
		ADD_OBJECT(Actor, InInstigator)
		ADD_OBJECT(Actor, InOriginator)
		ADD_OBJECT(SequenceEvent, ActivatedEvent)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
