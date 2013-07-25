#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrRibbonManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrRibbonManager : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bDirty, 0x1)
		ADD_VAR(::BoolProperty, bHaveUnlocks, 0x2)
		ADD_VAR(::BoolProperty, bOnlyUnlocks, 0x4)
		ADD_VAR(::BoolProperty, bHaveUpgrades, 0x8)
		ADD_VAR(::BoolProperty, bOnlyUpgrades, 0x10)
		ADD_VAR(::IntProperty, PreviousGold, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PreviousXP, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetClassRibbon'
		// Here lies the not-yet-implemented method 'GetTypeRibbon'
		// Here lies the not-yet-implemented method 'GetEquipRibbon'
		// Here lies the not-yet-implemented method 'CalculateRibbons'
	};
}
#undef ADD_VAR
