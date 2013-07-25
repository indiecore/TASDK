#pragma once
#include "UTGame__UTPawn.h"
#include "UTGame__UTItemPickupFactory.h"
#include "UTGame__UTHUD.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTArmorPickupFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTArmorPickupFactory : public UTItemPickupFactory
	{
	public:
		ADD_VAR(::IntProperty, ShieldAmount, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'UpdateHUD'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'SpawnCopyFor'
		// Here lies the not-yet-implemented method 'CanUseShield'
		// Here lies the not-yet-implemented method 'AddShieldStrength'
		// Here lies the not-yet-implemented method 'BotDesireability'
	};
}
#undef ADD_VAR
