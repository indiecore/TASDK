#pragma once
#include "UTGame__UTVehicle.h"
#include "UDKBase__UDKProjectile.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTAirVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTAirVehicle : public UTVehicle
	{
	public:
		ADD_VAR(::FloatProperty, LastRadarLockWarnTime, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RadarLockMessage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PushForce, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAutoLand, 0x1)
		// Here lies the not-yet-implemented method 'LockOnWarning'
		// Here lies the not-yet-implemented method 'SetDriving'
		// Here lies the not-yet-implemented method 'RecommendLongRangedAttack'
		// Here lies the not-yet-implemented method 'Dodge'
	};
}
#undef ADD_VAR
