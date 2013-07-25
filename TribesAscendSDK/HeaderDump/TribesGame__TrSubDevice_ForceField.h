#pragma once
#include "TribesGame__TrSubDevice.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSubDevice_ForceField." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSubDevice_ForceField : public TrSubDevice
	{
	public:
		ADD_VAR(::FloatProperty, m_MinSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_MaxSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_MinDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_MaxDamage, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'InstantFire'
		// Here lies the not-yet-implemented method 'ModifyInstantHitDamage'
	};
}
#undef ADD_VAR
