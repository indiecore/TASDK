#pragma once
#include "UDKBase__UDKVehicleFactory.h"
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
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
