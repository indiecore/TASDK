#pragma once
#include "UTGame__UTItemPickupFactory.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#include "UTGame__UTHUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTAmmoPickupFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTAmmoPickupFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTAmmoPickupFactory : public UTItemPickupFactory
	{
	public:
		ADD_OBJECT(ScriptClass, TargetWeapon)
		ADD_VAR(::IntProperty, AmmoAmount, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'SpawnCopyFor'
		// Here lies the not-yet-implemented method 'UpdateHUD'
		// Here lies the not-yet-implemented method 'BotDesireability'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
