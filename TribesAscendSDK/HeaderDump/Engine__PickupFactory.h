#pragma once
#include "Engine__Pawn.h"
#include "Engine__NavigationPoint.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PickupFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PickupFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PickupFactory : public NavigationPoint
	{
	public:
		ADD_OBJECT(PickupFactory, OriginalFactory)
		ADD_OBJECT(PickupFactory, ReplacementFactory)
		ADD_VAR(::FloatProperty, MaxDesireability, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RespawnEffectTime, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, InventoryType)
		ADD_VAR(::BoolProperty, bRespawnPaused, 0x10)
		ADD_VAR(::BoolProperty, bIsSuperItem, 0x8)
		ADD_VAR(::BoolProperty, bPredictRespawns, 0x4)
		ADD_VAR(::BoolProperty, bPickupHidden, 0x2)
		ADD_VAR(::BoolProperty, bOnlyReplicateHidden, 0x1)
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'InitializePickup'
		// Here lies the not-yet-implemented method 'SetInitialState'
		// Here lies the not-yet-implemented method 'ShutDown'
		// Here lies the not-yet-implemented method 'SetPickupMesh'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'CheckForErrors'
		// Here lies the not-yet-implemented method 'SetRespawn'
		// Here lies the not-yet-implemented method 'StartSleeping'
		// Here lies the not-yet-implemented method 'DetourWeight'
		// Here lies the not-yet-implemented method 'SpawnCopyFor'
		// Here lies the not-yet-implemented method 'ReadyToPickup'
		// Here lies the not-yet-implemented method 'GiveTo'
		// Here lies the not-yet-implemented method 'PickedUpBy'
		// Here lies the not-yet-implemented method 'RecheckValidTouch'
		// Here lies the not-yet-implemented method 'GetRespawnTime'
		// Here lies the not-yet-implemented method 'RespawnEffect'
		// Here lies the not-yet-implemented method 'SetPickupHidden'
		// Here lies the not-yet-implemented method 'SetPickupVisible'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'DelayRespawn'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
