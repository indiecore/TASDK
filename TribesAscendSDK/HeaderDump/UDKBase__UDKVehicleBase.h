#pragma once
#include "Engine__SVehicle.h"
#include "UDKBase__UDKCarriedObject.h"
#include "Engine__Pawn.h"
#include "Engine__Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKVehicleBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKVehicleBase : public SVehicle
	{
	public:
		ADD_VAR(::BoolProperty, bShouldEject, 0x1)
		// Here lies the not-yet-implemented method 'HoldGameObject'
		// Here lies the not-yet-implemented method 'SwitchWeapon'
		// Here lies the not-yet-implemented method 'AdjacentSeat'
		// Here lies the not-yet-implemented method 'ServerAdjacentSeat'
		// Here lies the not-yet-implemented method 'ServerChangeSeat'
		// Here lies the not-yet-implemented method 'GetDamageScaling'
		// Here lies the not-yet-implemented method 'NeedToTurn'
		// Here lies the not-yet-implemented method 'DrivingStatusChanged'
		// Here lies the not-yet-implemented method 'DriverEnter'
		// Here lies the not-yet-implemented method 'ApplyWeaponEffects'
		// Here lies the not-yet-implemented method 'GetVehicleDrivingStatName'
		// Here lies the not-yet-implemented method 'EjectDriver'
		// Here lies the not-yet-implemented method 'DetachDriver'
		// Here lies the not-yet-implemented method 'ChooseFireMode'
		// Here lies the not-yet-implemented method 'BotFire'
		// Here lies the not-yet-implemented method 'StopFiringWeapon'
		// Here lies the not-yet-implemented method 'DriverLeft'
		// Here lies the not-yet-implemented method 'HandleDeadVehicleDriver'
	};
}
#undef ADD_VAR
