#pragma once
#include "TribesGame__GFxTrPage.h"
#include "TribesGame__GFxTrAction.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Badges." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Badges : public GFxTrPage
	{
	public:
		ADD_VAR(::IntProperty, ActiveType, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'TakeAction'
		// Here lies the not-yet-implemented method 'ShowModel'
		// Here lies the not-yet-implemented method 'TakeFocus'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'FillProfile'
		// Here lies the not-yet-implemented method 'FillCombatType'
		// Here lies the not-yet-implemented method 'FillObjectiveType'
		// Here lies the not-yet-implemented method 'FillVehicleType'
		// Here lies the not-yet-implemented method 'FillTacticalType'
		// Here lies the not-yet-implemented method 'FillSingleType'
		// Here lies the not-yet-implemented method 'FillReferralType'
		// Here lies the not-yet-implemented method 'FillBadge'
		// Here lies the not-yet-implemented method 'GetHighestBadgeIndex'
		// Here lies the not-yet-implemented method 'GetHighestSkiBadgeIndex'
		// Here lies the not-yet-implemented method 'ProfileUp'
		// Here lies the not-yet-implemented method 'ProfileDown'
	};
}
#undef ADD_VAR
