#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.NavigationPoint.h"
#include "Engine.Inventory.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class DroppedPickup : public Actor
	{
	public:
		ADD_BOOL(bFadeOut, 488, 0x1)
		ADD_OBJECT(NavigationPoint, PickupCache, 484)
		ADD_OBJECT(ScriptClass, InventoryClass, 480)
		ADD_OBJECT(Inventory, Inventory, 476)
		void AddToNavigation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14775);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveFromNavigation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14776);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14777);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14778);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14782);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupMesh(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PickupMesh)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14783);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PickupMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPickupParticles(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PickupParticles)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14786);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PickupParticles;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14790);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float DetourWeight(class Pawn* Other, float PathWeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14792);
			byte params[12] = { NULL };
			*(class Pawn**)params = Other;
			*(float*)&params[4] = PathWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		void Landed(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14798);
			byte params[16] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GiveTo(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14801);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PickedUpBy(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14804);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RecheckValidTouch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14806);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_OBJECT
