#pragma once
#include "UDKBase__UDKScriptedNavigationPoint.h"
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
		ADD_VAR(::BoolProperty, bSniping, 0x2)
		ADD_VAR(::BoolProperty, bFirstScript, 0x1)
		ADD_OBJECT(UDKGameObjective, DefendedObjective)
		ADD_VAR(::BoolProperty, bOnlyOnFoot, 0x4)
		ADD_VAR(::NameProperty, DefenseGroup, 0xFFFFFFFF)
		ADD_OBJECT(UTDefensePoint, NextDefensePoint)
		ADD_OBJECT(Controller, CurrentUser)
		ADD_VAR(::ByteProperty, DefensePriority, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOnlySkilled, 0x8)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
