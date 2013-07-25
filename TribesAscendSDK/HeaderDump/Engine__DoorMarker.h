#pragma once
#include "Engine__Pawn.h"
#include "Engine__NavigationPoint.h"
#include "Engine__InterpActor.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DoorMarker." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.DoorMarker." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DoorMarker : public NavigationPoint
	{
	public:
		ADD_VAR(::BoolProperty, bTempDisabledCollision, 0x10)
		ADD_VAR(::BoolProperty, bDoorOpen, 0x8)
		ADD_VAR(::BoolProperty, bBlockedWhenClosed, 0x4)
		ADD_VAR(::BoolProperty, bInitiallyClosed, 0x2)
		ADD_VAR(::BoolProperty, bWaitUntilCompletelyOpened, 0x1)
		ADD_OBJECT(Actor, DoorTrigger)
		ADD_VAR(::ByteProperty, DoorType, 0xFFFFFFFF)
		ADD_OBJECT(InterpActor, MyDoor)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'MoverOpened'
		// Here lies the not-yet-implemented method 'MoverClosed'
		// Here lies the not-yet-implemented method 'SpecialHandling'
		// Here lies the not-yet-implemented method 'ProceedWithMove'
		// Here lies the not-yet-implemented method 'SuggestMovePreparation'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
