#pragma once
#include "Engine.Pawn.h"
#include "UTGame.UTDroppedPickup.h"
#include "Engine.SoundCue.h"
#include "Engine.Controller.h"
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
	class UTDroppedItemPickup : public UTDroppedPickup
	{
	public:
		ADD_OBJECT(SoundCue, PickupSound, 516)
		ADD_STRUCT(float, MaxDesireability, 512)
		float BotDesireability(class Pawn* Bot, class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47275);
			byte params[12] = { NULL };
			*(class Pawn**)params = Bot;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		void SetPickupMesh(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* NewPickupMesh)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47279);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = NewPickupMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47281);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47282);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DroppedFrom(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47283);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PickedUpBy(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47285);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
