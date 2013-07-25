#pragma once
#include "Engine__Actor.h"
#include "Engine__SequenceOp.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SequenceEvent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SequenceEvent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SequenceEvent : public SequenceOp
	{
	public:
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		ADD_VAR(::IntProperty, MaxTriggerCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TriggerCount, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPlayerOnly, 0x2)
		ADD_VAR(::IntProperty, MaxWidth, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Priority, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bClientSideOnly, 0x8)
		ADD_VAR(::BoolProperty, bRegistered, 0x4)
		ADD_VAR(::FloatProperty, ReTriggerDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ActivationTime, 0xFFFFFFFF)
		ADD_OBJECT(Actor, Instigator)
		ADD_OBJECT(Actor, Originator)
		// Here lies the not-yet-implemented method 'CheckActivate'
		// Here lies the not-yet-implemented method 'RegisterEvent'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'Toggled'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
