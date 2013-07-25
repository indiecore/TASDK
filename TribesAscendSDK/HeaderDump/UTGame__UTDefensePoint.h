#pragma once
#include "UDKBase__UDKScriptedNavigationPoint.h"
#include "Engine__Actor.h"
#include "UDKBase__UDKGameObjective.h"
#include "Engine__Controller.h"
#include "UTGame__UTBot.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTDefensePoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTDefensePoint." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTDefensePoint : public UDKScriptedNavigationPoint
	{
	public:
		ADD_OBJECT(ScriptClass, WeaponPreference)
		ADD_VAR(::BoolProperty, bSniping, 0x2)
		ADD_VAR(::BoolProperty, bFirstScript, 0x1)
		ADD_OBJECT(UDKGameObjective, DefendedObjective)
		ADD_VAR(::BoolProperty, bOnlyOnFoot, 0x4)
		ADD_VAR(::NameProperty, DefenseGroup, 0xFFFFFFFF)
		ADD_OBJECT(UTDefensePoint, NextDefensePoint)
		ADD_OBJECT(Controller, CurrentUser)
		ADD_VAR(::ByteProperty, DefensePriority, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOnlySkilled, 0x8)
		// Here lies the not-yet-implemented method 'GetMoveTarget'
		// Here lies the not-yet-implemented method 'HigherPriorityThan'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'FreePoint'
		// Here lies the not-yet-implemented method 'CheckForErrors'
		// Here lies the not-yet-implemented method 'PreBeginPlay'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
