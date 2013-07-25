#pragma once
#include "Engine__SequenceEvent.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTSeqEvent_VehicleFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTSeqEvent_VehicleFactory : public SequenceEvent
	{
	public:
		ADD_OBJECT(UTVehicle, SpawnedVehicle)
	};
}
#undef ADD_OBJECT
