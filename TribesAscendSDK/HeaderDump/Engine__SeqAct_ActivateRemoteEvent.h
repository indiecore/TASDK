#pragma once
#include "Engine__SequenceAction.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_ActivateRemoteEvent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_ActivateRemoteEvent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_ActivateRemoteEvent : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bStatusIsOk, 0x1)
		ADD_VAR(::NameProperty, EventName, 0xFFFFFFFF)
		ADD_OBJECT(Actor, Instigator)
		// Here lies the not-yet-implemented method 'GetObjClassVersion'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
