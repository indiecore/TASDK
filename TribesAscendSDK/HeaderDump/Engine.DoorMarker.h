#pragma once
#include "Engine.NavigationPoint.h"
#include "Engine.Actor.h"
#include "Engine.InterpActor.h"
#include "Engine.Pawn.h"
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
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DoorMarker.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MoverOpened()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DoorMarker.MoverOpened");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MoverClosed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DoorMarker.MoverClosed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Actor* SpecialHandling(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DoorMarker.SpecialHandling");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 4);
			free(params);
			return returnVal;
		}
		bool ProceedWithMove(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DoorMarker.ProceedWithMove");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SuggestMovePreparation(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DoorMarker.SuggestMovePreparation");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
