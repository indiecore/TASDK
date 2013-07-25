#pragma once
#include "Engine__SequenceEvent.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqEvent_Mover." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_Mover : public SequenceEvent
	{
	public:
		ADD_VAR(::FloatProperty, StayOpenTime, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'RegisterEvent'
		// Here lies the not-yet-implemented method 'NotifyEncroachingOn'
		// Here lies the not-yet-implemented method 'NotifyAttached'
		// Here lies the not-yet-implemented method 'NotifyDetached'
		// Here lies the not-yet-implemented method 'NotifyFinishedOpen'
	};
}
#undef ADD_VAR
