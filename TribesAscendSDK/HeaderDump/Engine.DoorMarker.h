#pragma once
#include "Engine.NavigationPoint.h"
#include "Engine.Actor.h"
#include "Engine.InterpActor.h"
#include "Engine.Pawn.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class DoorMarker : public NavigationPoint
	{
	public:
		enum EDoorType : byte
		{
			DOOR_Shoot = 0,
			DOOR_Touch = 1,
			DOOR_MAX = 2,
		};
		ADD_BOOL(bTempDisabledCollision, 704, 0x10)
		ADD_BOOL(bDoorOpen, 704, 0x8)
		ADD_BOOL(bBlockedWhenClosed, 704, 0x4)
		ADD_BOOL(bInitiallyClosed, 704, 0x2)
		ADD_BOOL(bWaitUntilCompletelyOpened, 704, 0x1)
		ADD_OBJECT(Actor, DoorTrigger, 700)
		ADD_STRUCT(DoorMarker::EDoorType, DoorType, 696)
		ADD_OBJECT(InterpActor, MyDoor, 692)
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
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		bool ProceedWithMove(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DoorMarker.ProceedWithMove");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SuggestMovePreparation(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DoorMarker.SuggestMovePreparation");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
