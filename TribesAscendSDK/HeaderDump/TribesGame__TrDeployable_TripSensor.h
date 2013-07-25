#pragma once
#include "TribesGame__TrDeployable_Sensor.h"
#include "Engine__Pawn.h"
#include "TribesGame__TrTripActor.h"
#include "Engine__ParticleSystem.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDeployable_TripSensor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDeployable_TripSensor : public TrDeployable_Sensor
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IInterface_TrTripNotifier'!
		// Here lies the not-yet-implemented method 'AddTripActor'
		// Here lies the not-yet-implemented method 'RemoveTripActor'
		// Here lies the not-yet-implemented method 'TripActivated'
		// Here lies the not-yet-implemented method 'GetParticleSystemName'
		// Here lies the not-yet-implemented method 'GetTripSocketPosition'
		// Here lies the not-yet-implemented method 'OnTripAwake'
		// Here lies the not-yet-implemented method 'OnTripSleep'
	};
}
#undef ADD_STRUCT
