#pragma once
#include "UTGame__UTItemPickupFactory.h"
#include "UTGame__UTHUD.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTHealthPickupFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTHealthPickupFactory : public UTItemPickupFactory
	{
	public:
		ADD_VAR(::BoolProperty, bSuperHeal, 0x1)
		ADD_VAR(::IntProperty, HealingAmount, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'UpdateHUD'
		// Here lies the not-yet-implemented method 'SpawnCopyFor'
		// Here lies the not-yet-implemented method 'HealAmount'
		// Here lies the not-yet-implemented method 'BotDesireability'
	};
}
#undef ADD_VAR
