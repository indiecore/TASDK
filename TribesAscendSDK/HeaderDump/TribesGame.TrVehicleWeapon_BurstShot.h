#pragma once
#include "TribesGame.TrVehicleWeapon.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrVehicleWeapon_BurstShot : public TrVehicleWeapon
	{
	public:
		ADD_STRUCT(ScriptName, m_PostFireState, 1788)
		ADD_STRUCT(int, m_nBurstShotCount, 1784)
		ADD_STRUCT(int, m_nCurrBurstShotCount, 1780)
	};
}
#undef ADD_STRUCT
