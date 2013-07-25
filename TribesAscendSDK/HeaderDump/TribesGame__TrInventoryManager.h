#pragma once
#include "UTGame__UTInventoryManager.h"
#include "TribesGame__TrStatsInterface.h"
#include "TribesGame__TrDevice.h"
#include "Engine__Weapon.h"
#include "Engine__Inventory.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrInventoryManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrInventoryManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrInventoryManager : public UTInventoryManager
	{
	public:
		ADD_VAR(::BoolProperty, c_bRetryEquippingPrimaryWeapon, 0x1)
		ADD_OBJECT(TrStatsInterface, Stats)
		ADD_VAR(::ByteProperty, m_PreviousDeviceEquipPoint, 0xFFFFFFFF)
		ADD_OBJECT(TrDevice, m_RealLastDevice)
		// Here lies the not-yet-implemented method 'GetDeviceByEquipPoint'
		// Here lies the not-yet-implemented method 'AddInventory'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'GetDeviceByWeaponClass'
		// Here lies the not-yet-implemented method 'GetDeviceByWeaponId'
		// Here lies the not-yet-implemented method 'TrGetWeaponList'
		// Here lies the not-yet-implemented method 'DiscardEquippedDeployable'
		// Here lies the not-yet-implemented method 'AdjustWeapon'
		// Here lies the not-yet-implemented method 'SetPendingWeapon'
		// Here lies the not-yet-implemented method 'RemoveFromInventory'
		// Here lies the not-yet-implemented method 'AutoFireWeapon'
		// Here lies the not-yet-implemented method 'SwitchWeaponByEquipPoint'
		// Here lies the not-yet-implemented method 'SwitchToPreviousWeapon'
		// Here lies the not-yet-implemented method 'ServerAutoFireWeapon'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
