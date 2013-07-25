#pragma once
#include "Engine__InventoryManager.h"
#include "UTGame__UTWeapon.h"
#include "Engine__Inventory.h"
#include "Engine__Weapon.h"
#include "Engine__HUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTInventoryManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTInventoryManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTInventoryManager : public InventoryManager
	{
	public:
		ADD_VAR(::BoolProperty, bInfiniteAmmo, 0x1)
		ADD_VAR(::FloatProperty, LastAdjustWeaponTime, 0xFFFFFFFF)
		ADD_OBJECT(UTWeapon, PendingSwitchWeapon)
		ADD_OBJECT(Weapon, PreviousWeapon)
		// Here lies the not-yet-implemented method 'NeedsAmmo'
		// Here lies the not-yet-implemented method 'ClientSyncWeapon'
		// Here lies the not-yet-implemented method 'OwnerEvent'
		// Here lies the not-yet-implemented method 'GetWeaponList'
		// Here lies the not-yet-implemented method 'SwitchWeapon'
		// Here lies the not-yet-implemented method 'AdjustWeapon'
		// Here lies the not-yet-implemented method 'PrevWeapon'
		// Here lies the not-yet-implemented method 'NextWeapon'
		// Here lies the not-yet-implemented method 'AllAmmo'
		// Here lies the not-yet-implemented method 'SetCurrentWeapon'
		// Here lies the not-yet-implemented method 'ClientSetCurrentWeapon'
		// Here lies the not-yet-implemented method 'ServerSetCurrentWeapon'
		// Here lies the not-yet-implemented method 'SetPendingWeapon'
		// Here lies the not-yet-implemented method 'ClientWeaponSet'
		// Here lies the not-yet-implemented method 'CreateInventory'
		// Here lies the not-yet-implemented method 'ProcessRetrySwitch'
		// Here lies the not-yet-implemented method 'RetrySwitchTo'
		// Here lies the not-yet-implemented method 'CheckSwitchTo'
		// Here lies the not-yet-implemented method 'AddInventory'
		// Here lies the not-yet-implemented method 'DiscardInventory'
		// Here lies the not-yet-implemented method 'RemoveFromInventory'
		// Here lies the not-yet-implemented method 'AddAmmoToWeapon'
		// Here lies the not-yet-implemented method 'HasInventoryOfClass'
		// Here lies the not-yet-implemented method 'ChangedWeapon'
		// Here lies the not-yet-implemented method 'SwitchToPreviousWeapon'
		// Here lies the not-yet-implemented method 'DrawHUD'
		// Here lies the not-yet-implemented method 'SwitchToBestWeapon'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
