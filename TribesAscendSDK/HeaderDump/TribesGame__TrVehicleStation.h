#pragma once
#include "TribesGame__TrStation.h"
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
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
