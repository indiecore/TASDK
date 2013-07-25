#pragma once
#include "Engine__SequenceEvent.h"
#include "Engine__Actor.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqEvent_Touch." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_Touch : public SequenceEvent
	{
	public:
		ADD_VAR(::BoolProperty, bAllowDeadPawns, 0x4)
		ADD_VAR(::BoolProperty, bUseInstigator, 0x2)
		ADD_VAR(::BoolProperty, bForceOverlapping, 0x1)
		// Here lies the not-yet-implemented method 'CheckTouchActivate'
		// Here lies the not-yet-implemented method 'CheckUnTouchActivate'
		// Here lies the not-yet-implemented method 'Toggled'
		// Here lies the not-yet-implemented method 'NotifyTouchingPawnDied'
		// Here lies the not-yet-implemented method 'GetObjClassVersion'
	};
}
#undef ADD_VAR
