#pragma once
#include "Engine.Actor.h"
#include "Engine.NavigationPoint.h"
#include "Engine.Inventory.h"
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DroppedPickup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.DroppedPickup." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DroppedPickup : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bFadeOut, 0x1)
		ADD_OBJECT(NavigationPoint, PickupCache)
		ADD_OBJECT(ScriptClass, InventoryClass)
		ADD_OBJECT(Inventory, Inventory)
		void AddToNavigation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DroppedPickup.AddToNavigation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveFromNavigation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DroppedPickup.RemoveFromNavigation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DroppedPickup.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DroppedPickup.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DroppedPickup.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupMesh(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PickupMesh)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DroppedPickup.SetPickupMesh");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PickupMesh;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPickupParticles(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PickupParticles)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DroppedPickup.SetPickupParticles");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PickupParticles;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DroppedPickup.EncroachedBy");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float DetourWeight(class Pawn* Other, float PathWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DroppedPickup.DetourWeight");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = Other;
			*(float*)(params + 4) = PathWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		void Landed(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DroppedPickup.Landed");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GiveTo(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DroppedPickup.GiveTo");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PickedUpBy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DroppedPickup.PickedUpBy");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RecheckValidTouch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DroppedPickup.RecheckValidTouch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
