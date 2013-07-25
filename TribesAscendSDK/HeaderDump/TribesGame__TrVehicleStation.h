#pragma once
#include "Engine__Texture2D.h"
#include "TribesGame__TrAnimNodeBlendList.h"
#include "TribesGame__TrStation.h"
#include "TribesGame__TrPawn.h"
#include "TribesGame__TrVehicle.h"
#include "TribesGame__TrVehiclePad.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrVehicleStation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrVehicleStation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrVehicleStation." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrVehicleStation : public TrStation
	{
	public:
		ADD_OBJECT(TrAnimNodeBlendList, m_VehicleStationBlendNode)
		ADD_VAR(::FloatProperty, m_fTimeToSpawnVehicleAfterRequest, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fInstigatorTeleportTime, 0xFFFFFFFF)
		ADD_OBJECT(TrPawn, m_PawnRequestingVehicle)
		ADD_OBJECT(TrVehicle, m_LastSpawnedVehicle)
		ADD_VAR(::FloatProperty, m_fSpawnTimeStamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPostSpawnLockoutTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_LastRequestedVehicleType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_nSpawnSequenceEnded, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, r_bSpawnSequenceStarted, 0x2)
		ADD_VAR(::BoolProperty, r_bIsLocked, 0x1)
		ADD_VAR(::IntProperty, r_nSpawnedVehicles, 0xFFFFFFFF)
		ADD_OBJECT(TrVehiclePad, m_VehiclePad)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrVehicleStation.VehicleSpawnInfo' for the property named 'm_SpawnList'!
		// Here lies the not-yet-implemented method 'RequestSpawnVehicle'
		// Here lies the not-yet-implemented method 'GetNumVehiclesSpawnedByType'
		// Here lies the not-yet-implemented method 'GetMaxVehicleCountAllowed'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'PawnEnteredStation'
		// Here lies the not-yet-implemented method 'PawnLeftStation'
		// Here lies the not-yet-implemented method 'PlayStationEnteredEffects'
		// Here lies the not-yet-implemented method 'PlayStationLeftEffects'
		// Here lies the not-yet-implemented method 'PlayRetractAnim'
		// Here lies the not-yet-implemented method 'PlayVehiclePadDeployAnim'
		// Here lies the not-yet-implemented method 'PlayVehiclePadCollapseAnim'
		// Here lies the not-yet-implemented method 'SpawnVehicle'
		// Here lies the not-yet-implemented method 'TeleportDriverToVehicle'
		// Here lies the not-yet-implemented method 'Unlock'
		// Here lies the not-yet-implemented method 'AbleToSpawnVehicleType'
		// Here lies the not-yet-implemented method 'AddVehicleToPackedList'
		// Here lies the not-yet-implemented method 'GetMarker'
		// Here lies the not-yet-implemented method 'ShouldPostRenderForCaH'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
