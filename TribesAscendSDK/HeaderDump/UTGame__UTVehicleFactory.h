#pragma once
#include "UDKBase__UDKVehicleFactory.h"
#include "UTGame__UTMapInfo.h"
#include "UTGame__UTGameObjective.h"
#include "Engine__Canvas.h"
#include "Engine__SeqAct_Toggle.h"
#include "UTGame__UTPlayerController.h"
#include "UTGame__UTVehicle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTVehicleFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTVehicleFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTVehicleFactory : public UDKVehicleFactory
	{
	public:
		ADD_VAR(::BoolProperty, bStartNeutral, 0x2)
		ADD_VAR(::BoolProperty, bKeyVehicle, 0x8)
		ADD_OBJECT(UTGameObjective, ReverseObjective)
		ADD_VAR(::BoolProperty, bForceAvoidReversing, 0x10)
		ADD_VAR(::BoolProperty, bDisabled, 0x4)
		ADD_VAR(::BoolProperty, bMayReverseSpawnDirection, 0x1)
		ADD_VAR(::FloatProperty, SpawnZOffset, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'AddToClosestObjective'
		// Here lies the not-yet-implemented method 'SetInitialState'
		// Here lies the not-yet-implemented method 'RenderMapIcon'
		// Here lies the not-yet-implemented method 'Activate'
		// Here lies the not-yet-implemented method 'Deactivate'
		// Here lies the not-yet-implemented method 'VehicleTaken'
		// Here lies the not-yet-implemented method 'VehicleDestroyed'
		// Here lies the not-yet-implemented method 'TriggerSpawnedEvent'
		// Here lies the not-yet-implemented method 'OnToggle'
		// Here lies the not-yet-implemented method 'GetSpawnRotation'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
