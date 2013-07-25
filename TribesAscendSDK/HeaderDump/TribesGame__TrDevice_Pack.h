#pragma once
#include "TribesGame__TrDevice.h"
#include "TribesGame__TrPawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_Pack." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDevice_Pack : public TrDevice
	{
	public:
		ADD_VAR(::FloatProperty, m_CachedPowerPoolCostPerSec, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDefaultPowerPoolCostPerSec, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'UsesPower'
		// Here lies the not-yet-implemented method 'GetPowerPool'
		// Here lies the not-yet-implemented method 'CanBeActive'
		// Here lies the not-yet-implemented method 'ConsumePowerPool'
		// Here lies the not-yet-implemented method 'ToggleActivate'
		// Here lies the not-yet-implemented method 'ServerToggleActivate'
		// Here lies the not-yet-implemented method 'ForceActivate'
		// Here lies the not-yet-implemented method 'ClientForceActive'
		// Here lies the not-yet-implemented method 'ClientForceInactive'
		// Here lies the not-yet-implemented method 'StartFire'
		// Here lies the not-yet-implemented method 'StopFire'
		// Here lies the not-yet-implemented method 'SendToFiringState'
	};
}
#undef ADD_VAR
