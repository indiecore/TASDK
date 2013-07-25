#pragma once
#include "Engine__InventoryManager.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTInventoryManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTInventoryManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTInventoryManager : public InventoryManager
	{
	public:
		ADD_VAR(::BoolProperty, bInfiniteAmmo, 0x1)
		ADD_VAR(::FloatProperty, LastAdjustWeaponTime, 0xFFFFFFFF)
		ADD_OBJECT(UTWeapon, PendingSwitchWeapon)
		ADD_OBJECT(Weapon, PreviousWeapon)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
