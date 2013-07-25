#pragma once
#include "UTGame__UTBot.h"
#include "UTGame__UTPickupFactory.h"
#include "Engine__Pawn.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTWeaponPickupFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTWeaponPickupFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTWeaponPickupFactory : public UTPickupFactory
	{
	public:
		ADD_VAR(::FloatProperty, WeaponPickupScaling, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsActive, 0x2)
		ADD_VAR(::BoolProperty, bWeaponStay, 0x1)
		ADD_OBJECT(ScriptClass, WeaponPickupClass)
		// Here lies the not-yet-implemented method 'AllowPickup'
		// Here lies the not-yet-implemented method 'InitializePickup'
		// Here lies the not-yet-implemented method 'SetPickupVisible'
		// Here lies the not-yet-implemented method 'SetPickupHidden'
		// Here lies the not-yet-implemented method 'SetPickupMesh'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'CheckForErrors'
		// Here lies the not-yet-implemented method 'SetWeaponStay'
		// Here lies the not-yet-implemented method 'StartSleeping'
		// Here lies the not-yet-implemented method 'AddCustomer'
		// Here lies the not-yet-implemented method 'HasCustomer'
		// Here lies the not-yet-implemented method 'PickedUpBy'
		// Here lies the not-yet-implemented method 'SpawnCopyFor'
		// Here lies the not-yet-implemented method 'ShowActive'
		// Here lies the not-yet-implemented method 'ShowHidden'
		// Here lies the not-yet-implemented method 'NotifyLocalPlayerDead'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
