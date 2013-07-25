#pragma once
#include "TribesGame__TrDevice.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_PhaseRifle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDevice_PhaseRifle : public TrDevice
	{
	public:
		ADD_VAR(::FloatProperty, m_MaxEnergyConsumed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_DamagePerEnergy, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'InstantFire'
		// Here lies the not-yet-implemented method 'ModifyInstantHitDamage'
	};
}
#undef ADD_VAR
