#pragma once
#include "Engine__Inventory.h"
#include "UTGame__UTGameReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTInventory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTInventory : public Inventory
	{
	public:
		ADD_VAR(::BoolProperty, bReceiveOwnerEvents, 0x1)
		// Here lies the not-yet-implemented method 'AddWeaponOverlay'
		// Here lies the not-yet-implemented method 'ClientLostItem'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'DropFrom'
		// Here lies the not-yet-implemented method 'OwnerEvent'
	};
}
#undef ADD_VAR
