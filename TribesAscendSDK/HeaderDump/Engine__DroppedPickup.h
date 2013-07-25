#pragma once
#include "Engine__Actor.h"
#include "Engine__Pawn.h"
#include "Engine__NavigationPoint.h"
#include "Engine__Inventory.h"
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
		// Here lies the not-yet-implemented method 'AddToNavigation'
		// Here lies the not-yet-implemented method 'RemoveFromNavigation'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'SetPickupMesh'
		// Here lies the not-yet-implemented method 'SetPickupParticles'
		// Here lies the not-yet-implemented method 'EncroachedBy'
		// Here lies the not-yet-implemented method 'DetourWeight'
		// Here lies the not-yet-implemented method 'Landed'
		// Here lies the not-yet-implemented method 'GiveTo'
		// Here lies the not-yet-implemented method 'PickedUpBy'
		// Here lies the not-yet-implemented method 'RecheckValidTouch'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
