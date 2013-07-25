#pragma once
#include "UTGame__UTInventoryManager.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrInventoryManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrInventoryManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrInventoryManager : public UTInventoryManager
	{
	public:
		ADD_VAR(::BoolProperty, c_bRetryEquippingPrimaryWeapon, 0x1)
		ADD_OBJECT(TrStatsInterface, Stats)
		ADD_VAR(::ByteProperty, m_PreviousDeviceEquipPoint, 0xFFFFFFFF)
		ADD_OBJECT(TrDevice, m_RealLastDevice)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
