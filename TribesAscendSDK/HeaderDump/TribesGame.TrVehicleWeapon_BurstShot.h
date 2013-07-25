#pragma once
#include "TribesGame.TrVehicleWeapon.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrVehicleWeapon_BurstShot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrVehicleWeapon_BurstShot : public TrVehicleWeapon
	{
	public:
		ADD_VAR(::NameProperty, m_PostFireState, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nBurstShotCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nCurrBurstShotCount, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
