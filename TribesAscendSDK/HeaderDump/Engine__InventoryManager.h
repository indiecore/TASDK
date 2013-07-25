#pragma once
#include "Engine__Actor.h"
#include "Engine__Inventory.h"
#include "Engine__Weapon.h"
#include "Engine__Pawn.h"
#include "Engine__HUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InventoryManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.InventoryManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class InventoryManager : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bMustHoldWeapon, 0x1)
		ADD_OBJECT(Weapon, LastAttemptedSwitchToWeapon)
		ADD_OBJECT(Weapon, PendingWeapon)
		ADD_OBJECT(Inventory, InventoryChain)
		// Here lies the not-yet-implemented method 'HandlePickupQuery'
		// Here lies the not-yet-implemented method 'AddInventory'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'GetPendingFireLength'
		// Here lies the not-yet-implemented method 'SetPendingFire'
		// Here lies the not-yet-implemented method 'ClearPendingFire'
		// Here lies the not-yet-implemented method 'IsPendingFire'
		// Here lies the not-yet-implemented method 'ClearAllPendingFire'
		// Here lies the not-yet-implemented method 'InventoryActors'
		// Here lies the not-yet-implemented method 'SetupFor'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'FindInventoryType'
		// Here lies the not-yet-implemented method 'CreateInventory'
		// Here lies the not-yet-implemented method 'RemoveFromInventory'
		// Here lies the not-yet-implemented method 'DiscardInventory'
		// Here lies the not-yet-implemented method 'OwnerDied'
		// Here lies the not-yet-implemented method 'DrawHUD'
		// Here lies the not-yet-implemented method 'GetWeaponRatingFor'
		// Here lies the not-yet-implemented method 'GetBestWeapon'
		// Here lies the not-yet-implemented method 'SwitchToBestWeapon'
		// Here lies the not-yet-implemented method 'PrevWeapon'
		// Here lies the not-yet-implemented method 'NextWeapon'
		// Here lies the not-yet-implemented method 'SetCurrentWeapon'
		// Here lies the not-yet-implemented method 'InternalSetCurrentWeapon'
		// Here lies the not-yet-implemented method 'ServerSetCurrentWeapon'
		// Here lies the not-yet-implemented method 'SetPendingWeapon'
		// Here lies the not-yet-implemented method 'CancelWeaponChange'
		// Here lies the not-yet-implemented method 'ClearPendingWeapon'
		// Here lies the not-yet-implemented method 'ChangedWeapon'
		// Here lies the not-yet-implemented method 'ClientWeaponSet'
		// Here lies the not-yet-implemented method 'UpdateController'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
