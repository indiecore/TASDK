#pragma once
#include "UTGame__UTPlayerController.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTConsolePlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTConsolePlayerController : public UTPlayerController
	{
	public:
		ADD_VAR(::BoolProperty, bDebugTargetAdhesion, 0x2)
		ADD_VAR(::BoolProperty, bTargetAdhesionEnabled, 0x1)
		// Here lies the not-yet-implemented method 'UpdateRotation'
		// Here lies the not-yet-implemented method 'AimingHelp'
		// Here lies the not-yet-implemented method 'AimHelpModifier'
		// Here lies the not-yet-implemented method 'PerformedUseAction'
		// Here lies the not-yet-implemented method 'ClientSmartUse'
		// Here lies the not-yet-implemented method 'ClientRestart'
		// Here lies the not-yet-implemented method 'PrevWeapon'
		// Here lies the not-yet-implemented method 'NextWeapon'
		// Here lies the not-yet-implemented method 'ResetPlayerMovementInput'
	};
}
#undef ADD_VAR
